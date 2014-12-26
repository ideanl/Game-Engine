all:
	g++ -o main main.cpp src/*.cpp src/scenes/*.cpp src/levels/*.cpp src/menus/*.cpp -lsfml-window -lsfml-graphics -lsfml-system --std=c++11
