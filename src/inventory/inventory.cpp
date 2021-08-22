#include <iostream>
#include "inventory.h"

std::string CANT = " cannot be prepared because ";
std::string NOT_AVAILABLE = " is not available";
std::string NOT_SUFFICIENT = " is not sufficient";
std::string PREPARE_MESSAGE = " is prepared";
std::string ALERT_MESSAGE = " qunatity is very low";
std::string ALERT_PREFIX = "ALERT: ";

void Inventory::addRawMaterial(RawMaterial& rawMaterial) {
	auto it = rawMaterials_.find(rawMaterial.getName());
	if (it == rawMaterials_.end())
	{  // adding for the first time
		rawMaterials_.insert({rawMaterial.getName(), rawMaterial});
	}
	else
	{  //during refill
		it->second.addQuantity(rawMaterial.getQuantity());
	}
}

//prepare a beverage if ingridents available
bool Inventory::prepareBeverage(Beverage& beverage) {
	mtx_.lock();
	//critical section started
	if(!canWePrepareBeverage(beverage)) {
		mtx_.unlock();
		return false;
	}
	consumeRawMaterials(beverage);
	//critical section completed
	mtx_.unlock();

	std::string message = beverage.getName() + PREPARE_MESSAGE + "\n";
	std::cout << message;
	return true;
}

// notifies if a raw material qunatity reaches to less than threshold.
void Inventory::notifyIfRefillRequire(RawMaterial& rawMaterial) {
	if(rawMaterial.isUnderThreshold()) {
		std::string message = ALERT_PREFIX +rawMaterial.getName() + ALERT_MESSAGE + "\n";
		std::cout << message;
	}
}

//update raw Material quantity in the inventory
void Inventory::consumeRawMaterials(Beverage& beverage) {
	std::vector<Ingredient> ingredientsList = beverage.getIngredientsList();
	for(Ingredient ingredient : ingredientsList) {
		auto it = rawMaterials_.find(ingredient.getName());
		it->second.consumeQuantity(ingredient.getQuantity());
		notifyIfRefillRequire(it->second);
	}
}

//checks if all ingrdients are availble for a beverage
bool Inventory::canWePrepareBeverage(Beverage& beverage) {
	std::vector<Ingredient> ingredientsList = beverage.getIngredientsList();
	for(Ingredient ingredient : ingredientsList) {
		auto it = rawMaterials_.find(ingredient.getName());
		if(it == rawMaterials_.end() || it->second.getQuantity() < ingredient.getQuantity()) {
			std::string reason = (it == rawMaterials_.end() || it->second.getQuantity() == 0) ? NOT_AVAILABLE : NOT_SUFFICIENT;
			std::string message = beverage.getName() + CANT + ingredient.getName() + reason + "\n";
			std::cout << message;
			return false;
		}
	}
	return true;
}
