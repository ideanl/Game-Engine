all:
	g++ -o main main.cpp src/{,scenes/}*.cpp -lsfml-window -lsfml-graphics -lsfml-system --std=c++11
