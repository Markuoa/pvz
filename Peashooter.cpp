#pragma once
#include "Peashooter.h"

std::vector<IMAGE> Peashooter::im_peashooter{};
extern Pea peas;


Peashooter::Peashooter()
{
	status = 0;
	start = clock();
}

Peashooter::Peashooter(int m_x, int m_y):Plant(m_x, m_y)
{
	status = 0;
	start = clock();
}


void Peashooter::init_img(void)
{
	im_peashooter.resize(13);
	for (int i = 0; i <= 9; i++)
	{
		TCHAR src[20] = _T("Peashooter/0.png");
		src[11] = i + '0';
		loadimage(&im_peashooter[i], src);   // 导入图片
	}
	for (int i = 0; i <= 2; i++)
	{
		TCHAR src[20] = _T("Peashooter/10.png");
		src[12] = i + '0';
		loadimage(&im_peashooter[i + 10], src);   // 导入图片
	}
}

void Peashooter::show()
{
	//吐子弹
	now = clock();
	bool CD = false;
	int now_second = (int(now - start) / CLOCKS_PER_SEC);
	if (now_second % 20 == 5)
	{
		peas.the_peas[y].push_back(coordinate_to_pixel(x, y).first + 45);
		start = now;
	}
	//显示
	std::pair<int, int> pixel_coordinate = coordinate_to_pixel(x, y);
	putimagePng(pixel_coordinate.first, pixel_coordinate.second, &im_peashooter[status]);
	status = (status + 1) % 12;
}