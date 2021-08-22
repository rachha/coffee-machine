#include "coffee_machine.h"

CoffeeMachine::CoffeeMachine(int outlets) {
	outletNum = outlets;
}

void CoffeeMachine::addRawMaterialsToInventory(std::vector<RawMaterial>& rawMaterials) {
	// create inventory with the raw materials.
	for(auto rawMaterial: rawMaterials) {
		inventory.addRawMaterial(rawMaterial);
	}
}

void CoffeeMachine::serveBeverage(Beverage beverage){
	// TODO: currently we are allowing all the threads, we should restrict 
	// threads to no.of outlets, so we will also be knowing at which outlet we are serving the beverage.
	// we can implement using counting semaphore.

	//P(outletNum)
	inventory.prepareBeverage(beverage);
	//V(outletNum)
}

void CoffeeMachine::serveBeverages(std::vector<Beverage>& beverages) {
	// beverages: array of beverages need to be served

	// a thread for each beverage
	std::vector<std::thread> threads;
	for(auto beverage: beverages) {
		threads.push_back(std::thread(&CoffeeMachine::serveBeverage, this, beverage));
	}
	for (auto &th : threads) {
		th.join();
	}
}
