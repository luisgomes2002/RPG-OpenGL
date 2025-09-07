#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory
{
private:
	int slots;
	std::vector<Item> items;

public:
	Inventory(int slots = 30);
	~Inventory();

	int getSlots();
	bool addItem(const Item &item);
	bool removeItem(int index);
	void showItems();
	int freeSlots() const;
};

#endif
