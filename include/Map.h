#ifndef MAP_H
#define MAP_H

#include "Item.h"

class Map
{
private:
	static const int SIZE = 20;

public:
	char board[SIZE][SIZE];
	Item *items[SIZE][SIZE];

public:
	Map();
	~Map();

	void create();
	void placeItem(int x, int y, Item *item);
	void printMap();
};

#endif