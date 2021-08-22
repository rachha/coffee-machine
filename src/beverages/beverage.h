
#ifndef DUNZO_BEVERAGE_H
#define DUNZO_BEVERAGE_H

#include <string>
#include <unordered_map>
#include <vector>
#include "ingredient.h"

class Beverage
{
public:
	Beverage(std::string name);
	void addIngredient(Ingredient ingredient);
	std::vector<Ingredient> getIngredientsList();
	std::string getName();
private:
	std::string name_;
	std::unordered_map<std::string, Ingredient> ingredients_;
};

#endif