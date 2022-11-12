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


bool Human::ChoosePath(int playerX, int playerY, int wallX, int wallTopY, int wallDownY, char firstDirection, char secondDirection)
{
	bool touchWall;
	int humanPositionX, humanPositionY;

	humanPositionX = this->positionX;
	humanPositionY = this->positionY;
	touchWall = false;


	while (humanPositionX != playerX || humanPositionY != playerY)
	{
		if (humanPositionX > playerX)
			--humanPositionX;
		else if (humanPositionX < playerX)
			++humanPositionX;

		if (humanPositionY > playerY)
			--humanPositionY;
		else if (humanPositionY < playerY)
			++humanPositionY;
		
		if (humanPositionX == wallX)
			for (wallTopY; wallTopY <= wallDownY; wallTopY++)			// calculer la hauteur du meur
			{
				if (humanPositionY == wallTopY)
				{
					touchWall = true;
					break;
				}
			}
	}
	return touchWall;

	/*

// calcul pour droit et gauche
	value1 = pow(this->positionX - wallX, 2);

// calcul pour monter
	if (this->positionY > wallTopY - 1)						// 'w'	-1 pour grosseur du joueur
		value2 = pow(this->positionY - posWallTopY, 2);
	// calcul si plus haut
	else
		value2 = 0;
	lenghtPath1 = sqrt(value1 + value2);				// hypothénuse

	// calculer le segment du mur au joueur

// calcul pour descendre
	if (this->positionY < wallDownY + 1)
		value2 = pow(this->positionY - posWallDownY, 2);
	else
		value2 = 0;
	lenghtPath2 = sqrt(value1 + value2);				// hypothénuse
	// calculer le segment du mur au joueur
	*/
}


void Human::ChooseDirection(int playerX, int playerY, int wallX, int wallTopY, int wallDownY)
{
	char firstDirection = ' ';
	char secondDirection = ' ';

	// Calculer le chemin le plus rapide
	// partir dans la direction

	for (int i = 0; i <= 1; i++)
	{
		if (firstDirection != 's')
			if (this->positionY < playerY)
				secondDirection = 's';

		if (firstDirection != 'w')
			if (this->positionY > playerY)
				secondDirection = 'w';

		if (firstDirection != 'd')
			if (this->positionX < playerX)
				secondDirection = 'd';

		if (firstDirection != 'a')
			if (this->positionX > playerX)
				secondDirection = 'a';

		if (i == 0)
			firstDirection = secondDirection;
	}
	bool touchWall = ChoosePath(playerX, playerY, wallX, wallTopY, wallDownY, firstDirection, secondDirection);
	if (!(touchWall))
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