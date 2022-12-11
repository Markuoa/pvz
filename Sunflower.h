#pragma once
#include <graphics.h>  
#include <conio.h>
#include <vector>
#include <iostream>
#include <list>
#include "Plant.h"
#include "Sun.h"
#include "EasyXPng.h"
#include "Store.h"

class Sunflower:public Plant
{
public:
	int status = 0;
	clock_t start;
	clock_t now;
	static std::vector<IMAGE> im_sunflower;
	static std::list<Sun> Suns;
	static void init_img(void);

	Sunflower();
	Sunflower(int, int);
	void show();
	static bool click_sun(int, int);
	void provide_sun();
};
