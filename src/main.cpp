#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <termios.h>

#include "Item.h"
#include "Chest.h"
#include "Map.h"
#include "Player.h"

void showMenu()
{
	std::cout << "\n=== MENU ===\n";
	std::cout << "1. Criar item\n";
	std::cout << "2. Carregar item\n";
	std::cout << "3. Remover item\n";
	std::cout << "0. Sair\n";
	std::cout << "Escolha: ";
}

char getch()
{
	struct termios oldt, newt;
	char ch;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;

	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}

int main()
{
	int option = 0;

	Map map;
	map.create();

	Player player;
	std::cout << "Use W/A/S/D para mover, Q para sair\n";

	map.printMap();

	while (true)
	{
		int px = player.getX();
		int py = player.getY();

		player.trackItem(px, py, player.itemAtPos, map);

		char key = getch();
		map.board[px][py] = '.';

		if (key == 'e')
		{
			player.collectItem(player.itemAtPos, option, player, map);
		}

		if (key == 'q')
		{
			do
			{
				showMenu();
				std::cin >> option;

				switch (option)
				{
				case 1:
				{
					Item *item = new Item("", "", 0, 0);
					item->createItem();
					delete item;
					break;
				}
				case 2:
				{
					break;
				}
				default:
					break;
				}

			} while (option != 0);

			break;
		}

		player.move(key);

		map.board[player.getX()][player.getY()] = player.getSymbol();
		map.printMap();
	}

	return 0;
}