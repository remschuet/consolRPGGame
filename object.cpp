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


void Object::set_values(int topx, int downx, int y)
{
	this->positionTopY = topx;
	this->positionTopY = downx;
	this->positionX = y;
}

void Object::displayObject(string objectDesign)
{
	for (this->positionTopY; this->positionTopY < this->positionDownY; ++ this->positionTopY)
	{
		gotoxy(this->positionX, this->positionX);
		cout << objectDesign;
	}
}