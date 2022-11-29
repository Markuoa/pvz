#pragma once
#include <graphics.h>  
#include <conio.h>
#include <vector>
#include <time.h>
#include "Plant.h"

class The_Plants
{
public:
	std::vector<std::vector<Plant*>> the_Plants;

	The_Plants();
	void show_Plants();
	void add_Plant(int, int, Plant*);
};
