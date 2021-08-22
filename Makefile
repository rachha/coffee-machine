SRC_FILES = src/beverages/beverage.cpp src/coffee_machine/coffee_machine.cpp \
			src/inventory/inventory.cpp src/json_parser/json_parser.cpp 

build_linux:
	g++ -std=c++17 -pthread src/serve_beverages.cpp ${SRC_FILES} -o serve_beverages.out

build_mac:
	g++ -std=c++17 src/serve_beverages.cpp ${SRC_FILES} -o serve_beverages.out