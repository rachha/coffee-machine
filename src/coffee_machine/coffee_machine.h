
#ifndef DUNZO_COFFEE_MACHINE_H
#define DUNZO_COFFEE_MACHINE_H

#include <thread>
#include "../inventory/inventory.h"

class CoffeeMachine
{
public:
	CoffeeMachine(int outles);
	void addRawMaterialsToInventory(std::vector<RawMaterial>& rawMaterials);
	
	void serveBeverages(std::vector<Beverage>& beverages);
private:
	void serveBeverage(Beverage beverage);
	int outletNum;
	Inventory inventory;
};

#endif