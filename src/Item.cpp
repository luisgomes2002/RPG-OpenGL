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
	std::cout << "\n=== Criar item ===\n";

	std::cout << "1. Item ID\nDigite: ";
	std::cin >> id;
	std::cin.ignore();

	std::cout << "2. Nome do item\nDigite: ";
	std::getline(std::cin, name);

	std::cout << "3. Tipo do item\nDigite: ";
	std::getline(std::cin, type);

	do
	{
		std::cout << "4. Quantidade\nDigite: ";
		std::cin >> amount;
		if (amount < 0)
			std::cout << "Quantidade não pode ser negativa. Tente novamente.\n";
	} while (amount < 0);

	do
	{
		std::cout << "5. Quantidade máxima\nDigite: ";
		std::cin >> maxAmount;
		if (maxAmount <= 0)
			std::cout << "Quantidade máxima deve ser maior que zero. Tente novamente.\n";
		if (amount > maxAmount)
			std::cout << "Quantidade não pode ser maior que o máximo. Tente novamente.\n";
	} while (maxAmount <= 0 || amount > maxAmount);

	std::cout << "6. Símbolo\nDigite: ";
	std::cin >> std::ws >> symbol;

	saveById();

	std::cout << "\nItem salvo em: ../items/" << id << ".txt\n";
}