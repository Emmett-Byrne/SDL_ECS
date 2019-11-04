#pragma once
#include "Entity.h"
#include <vector>
#include "PositionComponant.h"
#include "inputComponant.h"
#include <SDL.h>

class ControlSystem
{
public:
	void addEntity(Entity* e) { entities.push_back(e); };
	void update(SDL_Event& event);
private:
	std::vector<Entity*> entities;
};

