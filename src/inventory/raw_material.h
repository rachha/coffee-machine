
#ifndef DUNZO_RAW_MATERIAL_H
#define DUNZO_RAW_MATERIAL_H

#include <string>

class RawMaterial
{
public:
	RawMaterial(std::string name, int quantity, int threshold = 30) { //threshold in percentage
		name_ = name;
		quantity_ = quantity;
		threshold_ = threshold*quantity/100;
	}
	std::string getName() {
		return name_;
	}
	int getQuantity() {
		return quantity_;
	}
	void addQuantity(int quantity) {
		quantity_ += quantity;
	}
	void consumeQuantity(int quantity) {
		quantity_ -= quantity;
	}
	bool isUnderThreshold() {
		return quantity_ <= threshold_;
	}
	std::string details() {
		return "";
	}
private:
	std::string name_;
	int quantity_;
	int threshold_;
};

#endif