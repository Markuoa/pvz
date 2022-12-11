#pragma once
#include "Sun.h"

IMAGE Sun::im_sun;
int Sun::height;
int Sun::width;

Sun::Sun()
{
	down = true;
	destination_x = rand() % 700 + 150;
	destination_y = rand() % 350 + 220;
	x = destination_x;
	y = 0;
}

Sun::Sun(int external_x, int external_y)
{
	down = true;
	destination_x = external_x;
	destination_y = external_y;
	x = external_x;
	y = 0;
}

Sun::Sun(int external_x, int external_y, int command)
{
	down = false;
	destination_x = external_x;
	destination_y = external_y;
	x = external_x;
	y = external_y;
}

void Sun::init_img()
{
	loadimage(&im_sun, _T("other/Sun.png"));   // µ¼ÈëÍ¼Æ¬
	width = im_sun.getwidth();
	height = im_sun.getheight();
}

void Sun::show()
{
	if (down)
	{
		y = y + 3;
		if (y >= destination_y) down = false;
	}
	putimagePng(x, y, &im_sun);
}
