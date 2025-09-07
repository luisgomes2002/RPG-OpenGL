#include "Object.h"
#include <iostream>

Object::Object(int x, int y, char symbol, std::string name)
	: x(x), y(y), symbol(symbol), name(name)
{
	std::cout << "Objeto criado: " << name << " (" << symbol << ") em (" << x << "," << y << ")\n";
}

Object::~Object()
{
	std::cout << "Objeto destruído: " << name << std::endl;
}

int Object::getX() const { return x; }
int Object::getY() const { return y; }
char Object::getSymbol() const { return symbol; }
std::string Object::getName() const { return name; }