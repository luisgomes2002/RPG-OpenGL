#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

#include "Object.h"

class Item : public Object
{
private:
	std::string id;
	std::string type;
	int amount;
	int maxAmount;

public:
	Item(std::string id = "", std::string type = "", int amount = 1, int maxAmount = 0);
	~Item();

	std::string getId() const;
	std::string getType() const;
	int getAmount() const;
	int getMaxAmount() const;

	void setAmount(int newAmount);
	void print() const;
	void save(std::string &filename);
	void load(const std::string &filename);
	void saveById();
	void loadById();
	void createItem();
};

#endif
