#include "Inventory.h"

Inventory::Inventory(int slots) : slots(slots) {}

Inventory::~Inventory() {}

int Inventory::getSlots()
{
	return slots;
}

bool Inventory::addItem(const Item &item)
{
	for (int i = 0; i < (int)items.size(); i++)
	{
		if (items[i].getId() == item.getId())
		{
			if (items[i].getAmount() < items[i].getMaxAmount())
			{
				int total = items[i].getAmount() + item.getAmount();

				if (total > item.getMaxAmount())
				{
					int remainingItems = total - item.getMaxAmount();
					items[i].setAmount(item.getMaxAmount());

					Item newItem = item;
					newItem.setAmount(remainingItems);

					if ((int)items.size() < slots)
					{
						items.push_back(newItem);
						return true;
					}
					std::cout << "O baú está cheio!\n";
					return false;
				}
				else
				{
					items[i].setAmount(total);
					return true;
				}
			}
			else
			{
				if ((int)items.size() < slots)
				{
					items.push_back(item);
					return true;
				}
				std::cout << "O baú está cheio!\n";
				return false;
			}
		}
	}

	if ((int)items.size() < slots)
	{
		items.push_back(item);
		return true;
	}

	std::cout << "O baú está cheio!\n";
	return false;
}

bool Inventory::removeItem(int index)
{
	if (index >= 0 && index < (int)items.size())
	{
		items.erase(items.begin() + index);
		return true;
	}

	std::cout << "Item inválido!\n";
	return false;
}

void Inventory::showItems()
{
	if (items.empty())
	{
		std::cout << "O baú está vazio.\n";
		return;
	}

	for (int i = 0; i < (int)items.size(); i++)
	{
		std::cout << i + 1 << ": ";
		items[i].print();
	}
}

int Inventory::freeSlots() const
{
	return slots - (int)items.size();
}
