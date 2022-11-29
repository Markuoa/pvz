#pragma once
#include <graphics.h>  
#include <conio.h>
#include <vector>
#include <time.h>
#include "Zombie.h"

class The_Zombies
{
public:
	std::vector<std::vector<Zombie*>> the_Zombies;

	The_Zombies();
	void show_Zombies(std::vector<std::vector<Plant*>>&);
};