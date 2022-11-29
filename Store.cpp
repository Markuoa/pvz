#include "i1.h"

IMAGE Store::im_store;
IMAGE Store::im_Sunflower_card;
IMAGE Store::im_Peashooter_card;
IMAGE Store::im_Peashooter_card_2;

const int card_coordinate_x = 132;
const int card_coordinate_y = 5;
const int card_width = 53;
const int caard_height = 75;

extern TheMouseEvent event1;

Store::Store()
{
	x = 0;
	y = 0;
	start = clock();
	sun = new Sun;
}


void Store::init_img()
{
	loadimage(&im_store, _T("other/Plantstore.png"));   // ����ͼƬ
	loadimage(&im_Peashooter_card, _T("other/peashooter_card.png"));   // ����ͼƬ
	loadimage(&im_Peashooter_card_2, _T("other/peashooter_card_2.png"));   // ����ͼƬ
	loadimage(&im_Sunflower_card, _T("other/sunflower_card.png"));   // ����ͼƬ
}

void Store::update()
{
	now = clock();
	now_second = (int(now - start) / CLOCKS_PER_SEC);
	if (now_second % 5 == 4)
	{
		start = now;
		delete(sun);
		sun = new Sun;
	}
	//�㶹���ֿ�����
	if (count_sun < 100)
		Pea_avalaible = false;
	else if(!event1.click)
		Pea_avalaible = true;
}

bool Store::click_sun(int mouse_x, int mouse_y)
{
	if(sun != nullptr)
		if (mouse_x - sun->x >= 0 && mouse_x - sun->x <= Sun::width && mouse_y - sun->y >= 0 && mouse_y - sun->y <= Sun::height * 1.5)
		{
			delete(sun);
			sun = nullptr;
			count_sun += 25;
			return true;
		}
	return false;
}

void Store::show()
{
	//����
	update();
	//��ʾ����
	if (sun != nullptr)
		sun->show();
	putimagePng(0, 0, &im_store);
	//��ʾ����
	putimagePng(card_coordinate_x + card_width, card_coordinate_y, &im_Sunflower_card);
	//��ʾ��Ƭ1���㶹����
	if(Pea_avalaible)
		putimagePng(card_coordinate_x, card_coordinate_y, &im_Peashooter_card);
	else
		putimagePng(card_coordinate_x, card_coordinate_y, &im_Peashooter_card_2);
	//��ʾ����ֵ
	TCHAR s[5] = { '0' };
	_stprintf_s(s, _T("%d"), count_sun);
	settextstyle(20, 0, _T("Arial"));
	outtextxy(87, 63, s);
}

