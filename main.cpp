#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <Windows.h>
#include "cvm 21.h"
#include "human.h"
#include "object.h"

using namespace std;

void displayInformation(int information, int yPos, string texte, string place ) 
{
	if (place == "Right")
	{
		gotoxy(98, yPos);
		cout << information;
		gotoxy(103, yPos);
		cout << texte;
	}
	else if (place == "Left")
	{
		gotoxy(4, yPos);
		cout << information;
		gotoxy(9, yPos);
		cout << texte;
	}
}


int main()
{
	char direction;

	// Init Object
	Object mur;

	// Init player
	Human player;
	player.set_values(80, 15);
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


		displayInformation(player.getPositionX(), 3, "Position en X", "Right");
		displayInformation(player.getPositionY(), 4, "Position en Y", "Right");
		displayInformation(enemy.getPositionX(), 3, "Position en X", "Left");
		displayInformation(enemy.getPositionY(), 4, "Position en Y", "Left");

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