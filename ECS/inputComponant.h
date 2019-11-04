#pragma once
#include "Componant.h"
class inputComponant : public Componant
{
public:
	inputComponant() : up(false), down(false), left(false), right(false) {}
	bool getUp() { return up; };
	bool getDown() { return down; };
	bool getLeft() { return left; };
	bool getRight() { return right; };

	void setUp(bool b) { up = b; };
	void setDown(bool b) { down = b; };
	void setLeft(bool b) { left = b; };
	void setright(bool b) { right = b; };

	void displayData() { std::cout << "|up: " << up << " down: " << down << " left: " << left << " right: " << right << "| "; };

private:
	bool up;
	bool down;
	bool left;
	bool right;
};

