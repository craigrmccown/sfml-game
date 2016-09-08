all: program

program: main.o
	g++ -std=c++11 main.o -o program -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -std=c++11 -c main.cpp
