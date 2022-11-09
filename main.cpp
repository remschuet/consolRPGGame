#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include "cvm 21.h"
#include "human.h"
#include <Windows.h>

using namespace std;

void displayInformation(int information, int yPos, string texte) {
	gotoxy(98, yPos);
	cout << information;
	gotoxy(103, yPos);
	cout << texte;
}


int main()
{
	int playerPv = 100;
	int pointMagie = 0;
	char direction;

	// Init player
	Human player;
	player.set_values(15, 15);
	player.displayHuman("(^_^)");

	Human enemy;
	enemy.set_values(20, 12);
	enemy.displayHuman("(>_<)");


	while (true)
	{
		clrscr();
		// Display information
		player.displayHuman("(^_^)");
		enemy.displayHuman("(>_<)");

		displayInformation(playerPv, 1, "Points de vie");
		displayInformation(pointMagie, 2, "Points de magie");
		displayInformation(player.getPositionX(), 25, "Position en X");
		displayInformation(player.getPositionY(), 26, "Position en Y");

		direction = _getch();

		if (GetAsyncKeyState(VK_UP))
			direction = 'w';
		else if (GetAsyncKeyState(VK_DOWN))
			direction = 's';
		else if (GetAsyncKeyState(VK_LEFT))
			direction = 'a';
		else if (GetAsyncKeyState(VK_RIGHT))
			direction = 'd';

		if (direction)
			player.calculNextPositionXY(direction);

		direction = ' ';
		Sleep(50);
	}
}