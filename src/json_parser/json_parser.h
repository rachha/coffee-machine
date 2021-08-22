
#ifndef DUNZO_JSON_PARSER_H
#define DUNZO_JSON_PARSER_H

//using third-party library to parse the JSON data.
#include "../../json-header/nlohmann/json.hpp"
#include "../inventory/inventory.h"

using json = nlohmann::json;

class JsonParser
{
public:
	JsonParser(std::string& filepath);
	int parseOutlets();
	std::vector<RawMaterial> parseRawMaterials();
	std::vector<Beverage> parseBeverages();
private:
	std::string filepath_;
	json jsonData;
};

#endif