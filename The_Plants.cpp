#pragma once
#include "The_Plants.h"

The_Plants::The_Plants()
{
	the_Plants.resize(5);
	for (auto& i : the_Plants)
	{
		i.resize(9);
		for (auto& j : i)
			j = nullptr;
	}
}

void The_Plants::show_Plants()
{
	for (auto& i : the_Plants)
	{
		for (auto j : i)
			if (j != nullptr)
				j->show();
	}
}

void The_Plants::flush_plants()
{
	for (auto& i : the_Plants)
	{
		for (auto& j : i)
			if (j != nullptr)
			{
				delete(j);
				j = nullptr;
			}
	}
}

bool The_Plants::add_Plant(int x, int y, Plant* plant)
{
	if (the_Plants[y][x] != nullptr)
		return false;
	the_Plants[y][x] = plant;
	return true;
}
