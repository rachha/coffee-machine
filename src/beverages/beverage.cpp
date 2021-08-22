#include "beverage.h"

Beverage::Beverage(std::string name) {
	name_ = name;
}

//Adds ingredients to the beverage
void Beverage::addIngredient(Ingredient ingredient) {
	auto it = ingredients_.find(ingredient.getName());
	if (it == ingredients_.end())
	{
		ingredients_.insert({ingredient.getName(), ingredient});
	}
	else
	{ // if ingrdient listed multiple times, we update the required ingredient quantity.
		it->second.addQuantity(ingredient.getQuantity());
	}
}

std::vector<Ingredient> Beverage::getIngredientsList() {
	std::vector<Ingredient> ingredientsList;
	for(auto it = ingredients_.begin(); it != ingredients_.end(); ++it)
		ingredientsList.push_back(it->second);
	return ingredientsList;
}

std::string Beverage::getName() {
	return name_;
}