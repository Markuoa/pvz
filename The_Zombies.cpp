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
	if (hurder == 2)
	{
		//memset(&all_Zombies[1][0], 0, sizeof(int) * 9 * 5);
		all_Zombies.clear();
		all_Zombies.resize(11);
		for (auto& i : all_Zombies)
		{
			i.resize(5);
			for (auto& j : i)
				j = 0;
		}
		all_Zombies[1][0] = 1; all_Zombies[1][1] = 0; all_Zombies[1][2] = 0; all_Zombies[1][3] = 0; all_Zombies[1][4] = 0;
		all_Zombies[2][0] = 0; all_Zombies[2][1] = 1; all_Zombies[2][2] = 0; all_Zombies[2][3] = 0; all_Zombies[2][4] = 0;
		all_Zombies[3][0] = 0; all_Zombies[3][1] = 0; all_Zombies[3][2] = 1; all_Zombies[3][3] = 0; all_Zombies[3][4] = 0;
		all_Zombies[4][0] = 0; all_Zombies[4][1] = 0; all_Zombies[4][2] = 0; all_Zombies[4][3] = 1; all_Zombies[4][4] = 0;
		all_Zombies[5][0] = 0; all_Zombies[5][1] = 0; all_Zombies[5][2] = 0; all_Zombies[5][3] = 0; all_Zombies[5][4] = 1; 
		all_Zombies[6][0] = 1; all_Zombies[6][1] = 0; all_Zombies[6][2] = 0; all_Zombies[6][3] = 0; all_Zombies[6][4] = 0;
		all_Zombies[7][0] = 0; all_Zombies[7][1] = 1; all_Zombies[7][2] = 0; all_Zombies[7][3] = 0; all_Zombies[7][4] = 0;
		all_Zombies[8][0] = 0; all_Zombies[8][1] = 0; all_Zombies[8][2] = 1; all_Zombies[8][3] = 0; all_Zombies[8][4] = 0;
		all_Zombies[9][0] = 0; all_Zombies[9][1] = 0; all_Zombies[9][2] = 0; all_Zombies[9][3] = 1; all_Zombies[9][4] = 0;
	}
}

void The_Zombies::flush_zombie()
{
	for (auto& zombie_rows : the_Zombies)
	{
		for (auto& zombie_ptr : zombie_rows)
		{
			delete(zombie_ptr);
			zombie_ptr = nullptr;
		}
		zombie_rows.clear();
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
	if (now_secound >= 8 && wave != 10 && wave != 11)
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
		for (auto& i : the_Zombies)
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
