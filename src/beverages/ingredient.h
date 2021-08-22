
#ifndef DUNZO_INGREDIENT_H
#define DUNZO_INGREDIENT_H

#include<string>

class Ingredient
{
public:
	Ingredient(std::string name, int quantity) {
		name_ = name;
		quantity_ = quantity;
	}
	std::string getName() {
		return name_;
	}
	void addQuantity(int quantity) {
		quantity_ += quantity;
	}
	int getQuantity() {
		return quantity_;
	}
private:
	std::string name_;
	int quantity_;
};

#endif