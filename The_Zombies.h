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
	std::vector<std::vector<Zombie*>> the_Zombies;//场上僵尸
	std::vector<std::vector<int>> all_Zombies;//本关全部僵尸
	int wave = 0;//波次
	clock_t start;
	clock_t now;

	The_Zombies();
	void show_Zombies(std::vector<std::vector<Plant*>>&, std::vector<std::list<int>>&);
	void init_wave(int);
	void flush_zombie();
	void update();
	void add_zombie();
};