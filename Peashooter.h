#pragma once
#include <graphics.h>  
#include <conio.h>
#include <vector>
#include <iostream>
#include "Plant.h"
#include "EasyXPng.h"

class Peashooter : public Plant
{
public:
	int status = 0;
	static std::vector<IMAGE> im_peashooter;
	static void init_img(void);

	Peashooter();
	Peashooter(int, int);
	void show();
};
