#pragma once
#include "Sunflower.h"

std::vector<IMAGE> Sunflower::im_sunflower{};

Sunflower::Sunflower() 
{ 
	status = 0;
}


Sunflower::Sunflower(int m_x, int m_y):Plant(m_x, m_y)
{
	status = 0;
}


void Sunflower::init_img() {
	im_sunflower.resize(17);
	for (int i = 0; i <= 9; i++)
	{
		TCHAR src[20] = _T("Sunflower/0.png");
		src[10] = i + '0';
		loadimage(&im_sunflower[i], src);   // 导入图片
	}
	for (int i = 0; i <= 6; i++)
	{
		TCHAR src[20] = _T("Sunflower/10.png");
		src[11] = i + '0';
		loadimage(&im_sunflower[i + 10], src);   // 导入图片
	}
}

void Sunflower::show() {
	std::pair<int, int> pixel_coordinate = coordinate_to_pixel(x, y);
	putimagePng(pixel_coordinate.first, pixel_coordinate.second, &im_sunflower[status]);
	status = (status + 1) % 16;
}
