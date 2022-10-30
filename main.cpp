#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include "cvm 21.h"
#include <Windows.h>

using namespace std;


class Human
{
	public:
		void set_values(int, int);
		void displayHuman(string);
		void calculNextPositionXY(char);
		void movementHumanXY(char);
		void VerifyIfHumanInScreen();
		int getPositionX();
		int getPositionY();
	private:
		int positionX;
		int positionY;
		int nextPositionY;
		int nextPositionX;
		bool canMove = false;
};

int Human::getPositionX()
{
	return this->positionX;
}

int Human::getPositionY()
{
	return this->positionY;
}

void Human::set_values(int x, int y) {
	this->positionX = x;
	this->positionY = y;
}

void Human::displayHuman(string HumanDesign)
{
	gotoxy(this->positionX, this->positionY);
	cout << HumanDesign;
}

void Human::calculNextPositionXY(char direction)
{
	int nextPositionX;
	int nextPositionY;

	// Calcul the next position
	switch (direction)
	{
		case 'w': this->nextPositionY = this->positionY - 1; break;
		case 'a': this->nextPositionX = this->positionX - 1; break;
		case 's': this->nextPositionY = this->positionY + 1; break;
		case 'd': this->nextPositionX = this->positionX + 1;
	}
	// Calcul if Human in screen
	VerifyIfHumanInScreen();
	// If Human in screen, move
	if (this->canMove)
		this->movementHumanXY(direction);
}

void Human::movementHumanXY(char direction)
{
	// Move human position
	switch (direction)
	{
	case 'w': this->positionY -= 1; break;
	case 'a': this->positionX -= 3; break;
	case 's': this->positionY += 1; break;
	case 'd': this->positionX += 3;
	}
}


void Human::VerifyIfHumanInScreen()
{
	// can Move start false
	this->canMove = true;

	// Verify if human in the screen
	if (this->nextPositionX <= 0 || this->nextPositionX >= 115 ||
		this->nextPositionY <= 0 || this->nextPositionY >= 29)
	{
			this->canMove = false;
	}
}


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