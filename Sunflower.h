#pragma once
#include <graphics.h>  
#include <conio.h>
#include <vector>
#include <iostream>
#include "Plant.h"
#include "EasyXPng.h"

class Sunflower:public Plant
{
public:
	int status = 0;
	static std::vector<IMAGE> im_sunflower;
	static void init_img(void);

	Sunflower();
	Sunflower(int, int);
	void show();
};
