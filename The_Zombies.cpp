#include "The_Zombies.h"

The_Zombies::The_Zombies()
{
	the_Zombies.resize(5);
	all_Zombies.resize(11);
	for (auto& i : all_Zombies)
	{
		i.resize(5);
		for (auto& j : i)
			j = 0;
	}
	start = clock();
}

void The_Zombies::init_wave(int hurder)
{
	if (hurder == 1)
	{
		for (int i = 0; i < 10; i++)
			all_Zombies[i][2] = 1;
	}
}

void The_Zombies::add_zombie()
{
	//当前wave的僵尸上场
	/*the_Zombies[4].push_back(new Zombie(0));*/
	for (int row = 0; row <= 4; row++)
	{
		for(int acount = 0; acount < all_Zombies[wave][row]; acount++)
			the_Zombies[row].push_back(new Zombie(row, acount * 50 + 920));
	}
}

void The_Zombies::update()
{
	now = clock();
	int now_secound = (now - start) / CLOCKS_PER_SEC;
	if (now_secound >= 2 && wave != 10 && wave != 11)
	{
		wave++;
		start = now;
		add_zombie();
	}
}

void The_Zombies::show_Zombies(std::vector<std::vector<Plant*>>& the_Plants, std::vector<std::list<int>>& peas)
{
	update();
	for (auto& i : the_Zombies)
	{
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
	if (wave == 10)
	{
		wave++;
		throw "HugeWave";
	}
	if (wave == 11)
	{
		bool pass = true;
		for (auto i : the_Zombies)
		{
			if (! i.empty())
			{
				pass = false;
				break;
			}
		}
		if (pass)
			throw "pass";
	}

}
