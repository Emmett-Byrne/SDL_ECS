#pragma once
#include "Entity.h"
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "PositionComponant.h"

class RenderSystem
{
public:
	void addEntity(Entity* e) { entities.push_back(e); };
	void update(SDL_Renderer* renderer);
private:
	std::vector<Entity*> entities;
};

