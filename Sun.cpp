#pragma once
#include "Sun.h"

IMAGE Sun::im_sun;
int Sun::height;
int Sun::width;

Sun::Sun()
{
	destination_x = rand() % 700 + 150;
	destination_y = rand() % 350 + 220;
	x = destination_x;
	y = 0;
}

Sun::Sun(int external_x, int external_y)
{
	destination_x = external_x;
	destination_y = external_y;
	x = external_x;
	y = 0;
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
		y = y + 5;
		if (y >= destination_y) down = false;
	}
	putimagePng(x, y, &im_sun);
}
