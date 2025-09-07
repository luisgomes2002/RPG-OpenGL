#include "Player.h"

Player::Player() : Object(19, 10, '@', "Player"), Inventory(10) {}

Player::~Player() {}

void Player::move(char input)
{
	if (input == 'w')
		x--;
	else if (input == 's')
		x++;
	else if (input == 'a')
		y--;
	else if (input == 'd')
		y++;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x >= 20)
		x = 19;
	if (y >= 20)
		y = 19;

	std::cout << "Player X: " << y << " PLayer Y: " << x << std::endl;
}

void Player::trackItem(int px, int py, std::vector<Item *> &itemAtPos, Map map)
{

	int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

	itemAtPos.clear();

	for (int i = 0; i < 8; i++)
	{
		int nx = px + dx[i];
		int ny = py + dy[i];

		if (nx >= 0 && nx < 20 && ny >= 0 && ny < 20)
		{
			Item *item = map.items[nx][ny];
			if (item != nullptr)
			{
				itemAtPos.push_back(item);
			}
		}
	}

	for (auto item : itemAtPos)
	{
		std::cout << item->getName() << std::endl;
	}

	if (!itemAtPos.empty())
	{
		std::cout << "Aperte E para interagir" << std::endl;
	}
}

void Player::collectItem(std::vector<Item *> &itemAtPos, int option, Player &player, Map &map)
{
	std::cout << "\n=== Itens ===\n";
	for (int i = 0; i < itemAtPos.size(); i++)
	{
		if (itemAtPos[i] != nullptr)
			std::cout << i + 1 << ". Pegar item " << itemAtPos[i]->getName() << "\n";
	}
	std::cout << "0. Sair\n";
	std::cout << "Escolha: ";
	std::cin >> option;

	if (option == 1)
	{
		int ix = itemAtPos[option - 1]->getX();
		int iy = itemAtPos[option - 1]->getY();

		player.addItem(*itemAtPos[option - 1]);

		map.board[ix][iy] = '.';

		delete itemAtPos[option - 1];
		map.items[ix][iy] = nullptr;

		std::cout << "Item coletado!" << std::endl;
	}
}