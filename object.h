#ifndef __OBJECT__
	#define __OBJECT__
	#include <string>

using namespace std;

class Object
{
public:
	void set_values(int, int, int);
	void displayObject(string);
	int getPositionDownY();
	int getPositionTopY();
	int getPositionX();
private:
	int positionTopY = 0;
	int positionDownY = 1;
	int positionX = 0;
};

#endif // !__WINDOW__