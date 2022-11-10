#include <iostream>
#include "cvm 21.h"
#include "object.h"

using namespace std;

int Object::getPositionDownY()
{
	return this->positionDownY;
}


int Object::getPositionTopY()
{
	return this->positionTopY;
}


int Object::getPositionX()
{
	return this->positionX;
}


void Object::set_values(int x, int topY, int downY)
{
	this->positionTopY = topY;
	this->positionDownY = downY;
	this->positionX = x;
}


void Object::displayObject(string objectDesign)
{
	gotoxy(this->positionX, this->positionTopY);
	
	int posY = this->positionTopY - 1;

	gotoxy(this->positionX, this->positionTopY);
	for (int i = 0; i <= (this->positionDownY - this->positionTopY); i++)
	{
		gotoxy(this->positionX, posY++);
		cout << objectDesign;
	}
}