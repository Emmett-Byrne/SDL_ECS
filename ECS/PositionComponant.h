#pragma once
#include "Componant.h"
class PositionComponant : public Componant
{
public:
	PositionComponant() : xPos(0), yPos(0) {}
	int getX() { return xPos; }
	int getY() { return yPos; }
	void setPosition(int x, int y) { this->xPos = x; this->yPos = y; }
	void displayData() { std::cout << "|x: " << xPos << " y: " << yPos << "| "; };

private:
	int xPos;
	int yPos;
};

