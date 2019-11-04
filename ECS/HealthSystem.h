#pragma once
#include <vector>
#include "Entity.h"
#include "HealthComponant.h"
#include <iostream>

class HealthSystem
{
public:
	void addEntity(Entity* e) { entities.push_back(e); };
	void update();
private:
	std::vector<Entity*> entities;
};

