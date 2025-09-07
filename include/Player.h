#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <vector>

#include "Object.h"
#include "Inventory.h"
#include "Map.h"

class Player : public Object, public Inventory
{
private:
	int level;

public:
	std::vector<Item *> itemAtPos;

public:
	Player();
	~Player();

	void move(char input);
	void trackItem(int px, int py, std::vector<Item *> &itemAtPos, Map map);
	void collectItem(std::vector<Item *> &itemAtPos, int option, Player &player, Map &map);
};

#endif