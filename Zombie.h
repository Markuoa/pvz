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
	int pix_x = 900;
	int pix_y;
	int coordinate_x;
	int coordinate_y;
	int status = 0; //哪一张图片
	int situation = 1;//行走状态
	static std::vector<IMAGE> im_zombie;
	static std::vector<IMAGE> im_zombie_eat;
	static void init_img(void);

	Zombie();
	Zombie(int);
	void show(std::vector<std::vector<Plant*>>& the_Plants);
	int update(std::vector<std::vector<Plant*>>& the_Plants);
	int pix_to_coordinate_x(int);
};
