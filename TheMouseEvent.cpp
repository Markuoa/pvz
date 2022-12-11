#pragma once
#include "i1.h"
#include "base_base.h"

extern const int card_coordinate_x;
extern const int card_coordinate_y;
extern const int card_width;
extern const int caard_height;
extern The_Plants plants;
extern Store store;
extern int count_sun;

TheMouseEvent::TheMouseEvent()
{
	;
}

std::pair<int, int> TheMouseEvent::pixel_to_coordinate_plant(int p_x, int p_y)
{
	int x, y;
	if (p_x >= 65 && p_x < 150) x = 0;
	else if (p_x >= 150 && p_x < 235) x = 1;
	else if (p_x >= 235 && p_x < 320) x = 2;
	else if (p_x >= 320 && p_x < 405) x = 3;
	else if (p_x >= 405 && p_x < 495) x = 4;
	else if (p_x >= 495 && p_x < 580) x = 5;
	else if (p_x >= 580 && p_x < 665) x = 6;
	else if (p_x >= 665 && p_x < 745) x = 7;
	else if (p_x >= 745 && p_x < 810) x = 8;
	else x = -1;

	if (p_y >= 120 && p_y < 240) y = 0;
	else if (p_y >= 240 && p_y < 360) y = 1;
	else if (p_y >= 360 && p_y < 480) y = 2;
	else if (p_y >= 480 && p_y < 600) y = 3;
	else if (p_y >= 600 && p_y < 720) y = 4;
	else y = -1;
	return std::pair<int, int>(x, y);
}

void TheMouseEvent::update()
{
	ExMessage m;
	if (peekmessage(&m))
		if (m.message == WM_LBUTTONDOWN)
		{
			
			if (m.x > card_coordinate_x && m.x < card_coordinate_x + card_width && m.y > card_coordinate_y && m.y < card_coordinate_y + caard_height)
			{
				if (store.Pea_avalaible) {
					//第一个卡槽事件
					click = true;
					store.Pea_avalaible = false;
					chosePlant_index = 1;
				}
			}
			else if (m.x > card_coordinate_x + card_width && m.x < card_coordinate_x + card_width * 2 && m.y > card_coordinate_y && m.y < card_coordinate_y + caard_height)
			{
				if (store.Sunflower_avalaible) {
					//第二个卡槽事件
					click = true;
					store.Sunflower_avalaible = false;
					chosePlant_index = 2;
				}
			}
			//优先点卡槽，次选择点阳光，阳光不在乎是否已经点击过卡槽
			else if (store.click_sun(m.x, m.y))
			{
				;
			}
			else if (Sunflower::click_sun(m.x, m.y))
			{
				;
			}
			else if (click) //已有过点击，判断是否在框内
			{
				click = false;
				std::pair<int, int> coordinate_mouse = pixel_to_coordinate_plant(m.x, m.y);
				if (coordinate_mouse.first >= 0 && coordinate_mouse.second >= 0)
				{
					//创建新植物

					if (chosePlant_index == 1)
					{
						Plant* ptr = new Peashooter(coordinate_mouse.first, coordinate_mouse.second);
						if (plants.add_Plant(coordinate_mouse.first, coordinate_mouse.second, ptr))
							count_sun -= 100;
						else
							delete(ptr);
					}
					if (chosePlant_index == 2)
					{
						Plant* ptr = new Sunflower(coordinate_mouse.first, coordinate_mouse.second);
						if (plants.add_Plant(coordinate_mouse.first, coordinate_mouse.second, ptr))
							count_sun -= 50;
						else
							delete(ptr);
					}
				}
				chosePlant_index = -1;
			}
		}
	//清空鼠标信息
	flushmessage();
}


