#pragma once
#include "Plant.h"

Plant::Plant()
{
	;
}

std::pair<int, int> Plant::coordinate_to_pixel(int, int)
{
	int pixel_x, pixel_y;
	switch (x)
	{
	case 0:
		pixel_x = 65;
		break;
	case 1:
		pixel_x = 150;
		break;
	case 2:
		pixel_x = 235;
		break;
	case 3:
		pixel_x = 320;
		break;
	case 4:
		pixel_x = 405;
		break;
	case 5:
		pixel_x = 495;
		break;
	case 6:
		pixel_x = 580;
		break;
	case 7:
		pixel_x = 665;
		break;
	case 8:
		pixel_x = 745;
		break;
	default:
		break;
	}
	switch (y)
	{
	case 0:
		pixel_y = 120;
		break;
	case 1:
		pixel_y = 240;
		break;
	case 2:
		pixel_y = 360;
		break;
	case 3:
		pixel_y = 480;
		break;
	case 4:
		pixel_y = 600;
		break;
	default:
		break;
	}
	return std::pair<int, int>(pixel_x, pixel_y);
}



