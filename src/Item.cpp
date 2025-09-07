#include <fstream>
#include <iostream>
#include <filesystem>

#include "Item.h"

Item::Item(std::string id, std::string type, int amount, int maxAmount)
	: Object(0, 0, '?', "Unknown"), id(id), type(type), amount(amount), maxAmount(maxAmount) {}

Item::~Item() {}

std::string Item::getId() const { return id; }
std::string Item::getType() const { return type; }
int Item::getAmount() const { return amount; }
int Item::getMaxAmount() const { return maxAmount; }

void Item::setAmount(int newAmount) { amount = newAmount; }

void Item::print() const
{
	std::cout << name << symbol << " (" << type << ") x" << amount << "\n";
}

void Item::save(std::string &filename)
{
	std::filesystem::create_directories("../items");
	std::ofstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Erro ao salvar o item no arquivo: " << filename << "\n";
		return;
	}

	file << id << "\n"
		 << name << "\n"
		 << type << "\n"
		 << amount << "\n"
		 << maxAmount << "\n"
		 << symbol;
}

void Item::load(const std::string &filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Erro ao carregar o item do arquivo: " << filename << "\n";
		return;
	}

	std::getline(file, id);
	std::getline(file, name);
	std::getline(file, type);
	file >> amount >> maxAmount;
	file >> symbol;
}

void Item::saveById()
{
	std::string filename = "../items/" + id + ".txt";
	save(filename);
}

void Item::loadById()
{
	std::string filename = "../items/" + id + ".txt";
	load(filename);
}

void Item::createItem()
{
}