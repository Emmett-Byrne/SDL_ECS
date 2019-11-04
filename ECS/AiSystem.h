#pragma once
#include "Entity.h"
#include <vector>
#include "PositionComponant.h"

class AiSystem
{
public:
	void addEntity(Entity* e) { entities.push_back(e); };
	void update();
private:
	std::vector<Entity*> entities;
};

