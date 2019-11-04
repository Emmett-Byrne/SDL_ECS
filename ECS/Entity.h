#pragma once

#include <vector>
#include "Componant.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Entity
{
public:
	Entity(std::string s, const char* texPath, SDL_Renderer* t_renderer) : id(s), renderer(t_renderer) {
		texture = IMG_LoadTexture(renderer, texPath);
	};
	void addComponant(Componant* c) { componants.push_back(c); }
	//remove
	std::vector<Componant*> getComponants() { return componants; };
	SDL_Texture* getTexture() { return texture; };
	void displayData();
	std::string id;
private:
	std::vector<Componant*> componants;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
};

