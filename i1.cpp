#pragma once
#include "i1.h"

IMAGE im_bk;
The_Plants plants;
Store store;
TheMouseEvent event1;
The_Zombies zombies;
Pea peas;

//��������
IMAGE im_lose;

void init_pvz()
{
	initgraph(960, 720);
	loadimage(&im_bk, _T("background.png"));   // ���뱳��ͼƬ
	loadimage(&im_lose, _T("other/lose.png"));   // ����ʧ��ͼƬ
	Sun::init_img();
	Sunflower::init_img();
	Peashooter::init_img();
	Store::init_img();
	Zombie::init_img();
	Pea::init_img();
	zombies.the_Zombies[4].push_back(new Zombie(4));
}



