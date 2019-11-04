#include "RenderSystem.h"

void RenderSystem::update(SDL_Renderer* renderer)
{
	for (int i = 0; i < entities.size(); i++)
	{
		std::vector<Componant*> temp = entities[i]->getComponants();

		for (int j = 0; j < temp.size(); j++)
		{
			PositionComponant* pc = dynamic_cast<PositionComponant*>(temp[j]);
			if (pc != NULL)
			{
				SDL_Rect rect{ pc->getX(), pc->getY(), 64, 64 };
				SDL_RenderCopy(renderer, entities[i]->getTexture(), NULL, &rect);
			}
		}
	}
}
