#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object
{
protected:
	int x, y;
	char symbol;
	std::string name;

public:
	Object(int x, int y, char symbol, std::string name);
	virtual ~Object();

	int getX() const;
	int getY() const;
	char getSymbol() const;
	std::string getName() const;
};

#endif
