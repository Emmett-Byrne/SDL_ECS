#include "Entity.h"

void Entity::displayData()
{
	std::cout << id << ": ";
	for (int i = 0; i < componants.size(); i++)
	{
		componants[i]->displayData();
	}
	std::cout << std::endl;
}
