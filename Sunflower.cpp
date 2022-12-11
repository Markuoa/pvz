#pragma once
#include "Sunflower.h"

std::vector<IMAGE> Sunflower::im_sunflower{};
std::list<Sun> Sunflower::Suns;
extern int count_sun;

Sunflower::Sunflower() 
{ 
	status = 0;
	start = clock();
}


Sunflower::Sunflower(int m_x, int m_y):Plant(m_x, m_y)
{
	status = 0;
	start = clock();
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

bool Sunflower::click_sun(int mouse_x, int mouse_y)
{
	for (auto iter = Suns.begin(); iter != Suns.end(); iter++)
	{
		Sun sun = *iter;
		if (mouse_x - sun.x >= 0 && mouse_x - sun.x <= Sun::width && mouse_y - sun.y >= 0 && mouse_y - sun.y <= Sun::height * 1.5)
		{
			Suns.erase(iter);
			count_sun += 25;
			return true;
		}
	}
	return false;
}

void Sunflower::show() {
	// 点击阳光
	// 生成阳光
	provide_sun();
	// 展示向日葵
	std::pair<int, int> pixel_coordinate = coordinate_to_pixel(x, y);
	putimagePng(pixel_coordinate.first, pixel_coordinate.second, &im_sunflower[status]);
	status = (status + 1) % 16;
	//展示阳光
	for (Sun& sun : Suns)
		sun.show();
}

void Sunflower::provide_sun()
{
	now = clock();
	int now_second = (now - start) / CLOCKS_PER_SEC;
	if (now_second >= 5)
	{
		std::pair<int, int> coordinate = coordinate_to_pixel(x, y);
		Suns.push_back(Sun(coordinate.first, coordinate.second, 1));
		start = now;
	}
}
