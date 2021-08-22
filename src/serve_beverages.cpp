#include <iostream>
#include "json_parser/json_parser.h"
#include "coffee_machine/coffee_machine.h"

int main() {

	std::vector<std::string> files(2);
	files[0] = "input/input_one.json";
	files[1] = "input/input_two.json";

	for(auto file : files) {
		JsonParser jsonObj(file);
		int outlets = jsonObj.parseOutlets();
		std::vector<RawMaterial> rawMaterials = jsonObj.parseRawMaterials();
		std::vector<Beverage> beverages = jsonObj.parseBeverages();

		CoffeeMachine coffeeMachine(outlets);
		coffeeMachine.addRawMaterialsToInventory(rawMaterials);
		coffeeMachine.serveBeverages(beverages);
		std::cout << std::endl << std::endl;
	}

	return 0;
}
