#include "The_Zombies.h"

The_Zombies::The_Zombies()
{
	the_Zombies.resize(5);
}

void The_Zombies::show_Zombies(std::vector<std::vector<Plant*>>& the_Plants)
{
	for (auto& i : the_Zombies)
	{
		for (auto& j : i)
		{
			j->show(the_Plants);
		}
	}
}
