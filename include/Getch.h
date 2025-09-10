#ifndef GETCH_H
#define GETCH_H

#ifdef _WIN32
#include <conio.h>

#else
#include <unistd.h>
#include <termios.h>

inline char getch()
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
#endif

#endif // GETCH_H
