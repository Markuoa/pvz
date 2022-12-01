#pragma once
#include <graphics.h>  
#include <conio.h>
#include <vector>
#include <iostream>
#include <time.h>
#include "Plant.h"
#include "EasyXPng.h"
#include "Pea.h"

class Peashooter : public Plant
{
public:
	int status = 0;
	clock_t now;
	clock_t start;
	static std::vector<IMAGE> im_peashooter;
	static void init_img(void);

	Peashooter();
	Peashooter(int, int);
	void show();
};
