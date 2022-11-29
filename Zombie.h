#pragma once
#include <graphics.h>  
#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include "The_Plants.h"
#include "EasyXPng.h"

class Zombie
{
public:
	int pix_x = -120;
	int pix_y;
	int coordinate_y;
	int status = 0;
	static std::vector<IMAGE> im_zombie;
	static void init_img(void);

	Zombie();
	Zombie(int);
	void show(std::vector<std::vector<Plant*>>& the_Plants);
	void update(std::vector<std::vector<Plant*>>& the_Plants);
};
