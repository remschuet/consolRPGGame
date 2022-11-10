#include <iostream>
#include <string>
#include "cvm 21.h"
#include "human.h"

using namespace std;


int Human::getPositionX()
{
	return this->positionX;
}


int Human::getPositionY()
{
	return this->positionY;
}


void Human::set_values(int x, int y) 
{
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
		this->movementHumanXY(direction, ' ');
}


void Human::movementHumanXY(char firstDirection, char secondDirection)
{
	// Move human position
	switch (firstDirection)
	{
	case 'w': this->positionY -= 1; break;
	case 'a': this->positionX -= 2; break;
	case 's': this->positionY += 1; break;
	case 'd': this->positionX += 2;
	}

	switch (secondDirection)
	{
	case 'w': this->positionY -= 1; break;
	case 'a': this->positionX -= 2; break;
	case 's': this->positionY += 1; break;
	case 'd': this->positionX += 2;
	}
}

void Human::ChooseDirection(int playerX, int playerY, int wallX, int wallTopY, int wallDownY)
{
	char firstDirection = ' ';
	bool secondBeAble = true;
	char secondDirection = ' ';

	for (int i = 0; i <= 1; i++)
	{
		if (firstDirection != 'd')
			if (this->positionX < playerX)
				secondDirection = 'd';

		if (firstDirection != 'a')
			if (this->positionX > playerX)
			secondDirection = 'a';

		if (firstDirection != 's')
			if (this->positionY < playerY)
				secondDirection = 's';

		if (firstDirection != 'w')
			if (this->positionY > playerY)
				secondDirection = 'w';

		if (i == 0)
		firstDirection = secondDirection;

	}

	movementHumanXY(firstDirection, secondDirection);

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