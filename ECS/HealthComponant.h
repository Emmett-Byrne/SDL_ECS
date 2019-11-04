#pragma once
#include "Componant.h"
class HealthComponant :	public Componant
{
public:
	HealthComponant() : health(100) {}
	int getHealth() { return health; }
	void setHealth(int h) { this->health = h; }
	void displayData() { std::cout << "|health: " << health << "| ";  };

private: 
	int health;
};

