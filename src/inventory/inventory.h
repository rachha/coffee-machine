
#ifndef DUNZO_INVENTORY_H
#define DUNZO_INVENTORY_H

#include <string>
#include <unordered_map>
#include <mutex>
#include "raw_material.h"
#include "../beverages/beverage.h"

class Inventory
{
public:
	void addRawMaterial(RawMaterial& rawMaterial);
	bool prepareBeverage(Beverage& beverage);
private:
	bool canWePrepareBeverage(Beverage& beverage);

	//we consume only when it's possible to make a beverage
	void consumeRawMaterials(Beverage& beverage);
	void notifyIfRefillRequire(RawMaterial& rawMaterial);

	std::unordered_map<std::string, RawMaterial> rawMaterials_;
	std::mutex mtx_; // mutex for critical section
};

#endif