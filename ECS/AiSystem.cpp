#include "AiSystem.h"

void AiSystem::update()
{
	for (int i = 0; i < entities.size(); i++)
	{
		std::vector<Componant*> temp = entities[i]->getComponants();

		for (int i = 0; i < temp.size(); i++)
		{
			PositionComponant* pc = dynamic_cast<PositionComponant*>(temp[i]);
			if (pc != NULL)
			{
				pc->setPosition(pc->getX() + 1, pc->getY());
			}
		}
	}
}
