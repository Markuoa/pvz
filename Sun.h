#pragma once
#include <graphics.h>  
#include <conio.h>
#include <cstdlib>
#include "EasyXPng.h"

class Sun
{
public:
	int x, y;
	int destination_x, destination_y;
	static int width;
	static int height;
	bool down = true;
	static IMAGE im_sun;

	Sun();
	Sun(int, int);
	static void init_img();
	void show();
};