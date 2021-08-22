#include "json_parser.h"
#include <fstream>
#include <iostream>

JsonParser::JsonParser(std::string &filepath) {
	filepath_ = filepath;
	std::ifstream ifs(filepath_);
	jsonData = json::parse(ifs);
	ifs.close();
}

int JsonParser::parseOutlets() {
	jsonData = jsonData["machine"];
	return jsonData["outlets"]["count_n"];
}

std::vector<RawMaterial> JsonParser::parseRawMaterials() {
	std::vector<RawMaterial> rawMaterials;
	for (const auto &[rawMaterial, units] : jsonData["total_items_quantity"].items())
	{
		rawMaterials.push_back(RawMaterial(rawMaterial, units));
	}
	return rawMaterials;
}

std::vector<Beverage> JsonParser::parseBeverages() {
	std::vector<Beverage> beverages;
	for (const auto &[beverageName, jsonIngredients] : jsonData["beverages"].items())
	{
		Beverage beverage(beverageName);
		for (const auto &[ingredientName, ingredientQuantity] : jsonIngredients.items())
		{
			beverage.addIngredient(Ingredient(ingredientName, ingredientQuantity));
		}
		beverages.push_back(beverage);
	}
	return beverages;
}