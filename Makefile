SRC_FILES = src/beverages/beverage.cpp src/coffee_machine/coffee_machine.cpp \
			src/inventory/inventory.cpp src/json_parser/json_parser.cpp 

build:
	g++ -g -std=c++17 src/serve_beverages.cpp ${SRC_FILES} -o serve_beverages.out