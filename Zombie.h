#pragma once
#include <graphics.h>  
#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <list>
#include "The_Plants.h"
#include "EasyXPng.h"

class Zombie
{
public:
	float pix_x = 900;
	int pix_y;
	int coordinate_x;
	int coordinate_y;
	int HP = 210;
	float status = 0; //哪一张图片
	int situation = 1;//行走状态
	static std::vector<IMAGE> im_zombie;
	static std::vector<IMAGE> im_zombie_eat;
	static std::vector<IMAGE> im_zombie_die;
	static void init_img(void);

	Zombie();
	Zombie(int);
	Zombie(int, int);
	void show(std::vector<std::vector<Plant*>>& the_Plants, std::vector<std::list<int>>&);
	int update(std::vector<std::vector<Plant*>>& the_Plants, std::vector<std::list<int>>&);
	int pix_to_coordinate_x(int);
};
