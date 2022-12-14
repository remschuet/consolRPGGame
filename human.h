#ifndef __WINDOW__
	#define __WINDOW__
	#include <string>

using namespace std;

class Human
{
public:
	void set_values(int, int);
	void displayHuman(string);
	void calculNextPositionXY(char);
	void movementHumanXY(char, char);
	bool ChoosePath(int, int , int , int , int, char, char);
	void ChooseDirection(int, int, int, int, int);
	void VerifyIfHumanInScreen();
	int getPositionX();
	int getPositionY();

private:
	int positionX = 0;
	int positionY = 0;
	int nextPositionY = 0;
	int nextPositionX = 0;
	int posWallX = 0;
	int posWallTopY = 0;
	int posWallDownY = 0;

	bool canMove = false;

};

#endif // !__WINDOW__
