#include "Map.h"
#include "Item.h"

#include <iostream>

Map::Map() {}

Map::~Map() {}

void Map::create()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			board[i][j] = '.';
			items[i][j] = nullptr;
		}
	}
}

void Map::placeItem(int x, int y, Item *item)
{
	if (x >= 0 && x < SIZE && y >= 0 && y < SIZE)
	{
		items[x][y] = item;
		board[x][y] = item->getSymbol();
	}
}

void Map::printMap()
{
	Item *fireball = new Item("fire_ball");
	fireball->loadById();

	Item *fireball2 = new Item("fire_ball");
	fireball2->loadById();

	Item *fireball3 = new Item("fire_ball");
	fireball3->loadById();

	Item *fireball4 = new Item("fire_ball");
	fireball4->loadById();

	placeItem(6, 3, fireball);
	placeItem(6, 4, fireball2);
	placeItem(7, 3, fireball3);
	placeItem(8, 4, fireball4);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
