#include "ControlSystem.h"

void ControlSystem::update(SDL_Event& event)
{

	for (int i = 0; i < entities.size(); i++)
	{
		inputComponant* ic = NULL;
		std::vector<Componant*> temp = entities[i]->getComponants();

		for (int j = 0; j < temp.size(); j++)
		{
			ic = dynamic_cast<inputComponant*>(temp[j]);
			if (ic != NULL)
			{
				while (SDL_PollEvent(&event)) {
					switch (event.type) {
					case SDL_KEYDOWN:
						switch (event.key.keysym.sym)
						{
						case SDLK_UP:
							ic->setUp(true);
							break;
						case SDLK_DOWN:
							ic->setDown(true);
							break;
						case SDLK_LEFT:
							ic->setLeft(true);
							break;
						case SDLK_RIGHT:
							ic->setright(true);
							break;
						default:
							break;
						}
						break;

					case SDL_KEYUP:
						switch (event.key.keysym.sym)
						{
						case SDLK_UP:
							ic->setUp(false);
							break;
						case SDLK_DOWN:
							ic->setDown(false);
							break;
						case SDLK_LEFT:
							ic->setLeft(false);
							break;
						case SDLK_RIGHT:
							ic->setright(false);
							break;
						default:
							break;
						}
						break;

					default:
						break;
					}
				}
			}
		}

		for (int i = 0; i < temp.size(); i++)
		{
			PositionComponant* pc = dynamic_cast<PositionComponant*>(temp[i]);
			if (pc != NULL && ic != NULL)
			{
				if (ic->getUp())
				{
					pc->setPosition(pc->getX(), pc->getY() - 5);
				}
				if (ic->getDown())
				{
					pc->setPosition(pc->getX(), pc->getY() + 5);
				}
				if (ic->getLeft())
				{
					pc->setPosition(pc->getX() - 5, pc->getY());
				}
				if (ic->getRight())
				{
					pc->setPosition(pc->getX() + 5, pc->getY());
				}
			}
		}
	}
}
