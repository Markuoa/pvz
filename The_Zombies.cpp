#include "The_Zombies.h"

The_Zombies::The_Zombies()
{
	the_Zombies.resize(5);
}

void The_Zombies::show_Zombies(std::vector<std::vector<Plant*>>& the_Plants, std::vector<std::list<int>>& peas)
{
	for (auto& i : the_Zombies)
	{
		//for (auto& j : i)
		//{
		//	if(j->situation != 4)
		//		j->show(the_Plants, peas);
		//	else//真正死亡，躺尸动画都放完了
		//		delete(j);
		//}
		for (std::vector<Zombie*>::iterator iter = i.begin(); iter != i.end();)
		{
			if((*iter)->situation != 4)
				(*iter)->show(the_Plants, peas);
			else {
				delete(*iter);
				iter = i.erase(iter);
				break;
			}
			iter++;
		}
	}
}
