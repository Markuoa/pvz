#pragma once
#include <graphics.h>  
#include <conio.h>
#include <vector>
#include <time.h>
#include <list>
#include "Zombie.h"

class The_Zombies
{
public:
	std::vector<std::vector<Zombie*>> the_Zombies;//���Ͻ�ʬ
	std::vector<std::vector<int>> all_Zombies;//����ȫ����ʬ
	int wave = 0;//����
	clock_t start;
	clock_t now;

	The_Zombies();
	void show_Zombies(std::vector<std::vector<Plant*>>&, std::vector<std::list<int>>&);
	void init_wave(int);
	void flush_zombie();
	void update();
	void add_zombie();
};