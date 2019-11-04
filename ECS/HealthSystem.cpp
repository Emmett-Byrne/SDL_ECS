#include "HealthSystem.h"

void HealthSystem::update()
{
	for (int i = 0; i < entities.size(); i++) 
	{
		std::vector<Componant*> temp = entities[i]->getComponants();

		for (int i = 0; i < temp.size(); i++)
		{
			HealthComponant* hc = dynamic_cast<HealthComponant*>(temp[i]);
			if (hc != NULL)
			{
				hc->setHealth(hc->getHealth() - 1);
			}
		}
	}
}
