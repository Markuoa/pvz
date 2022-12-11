#pragma once
#include "i1.h"

IMAGE im_wait;
IMAGE im_bk;
IMAGE im_big_bk;
IMAGE im_ready;
IMAGE im_set;
IMAGE im_setplant;
IMAGE im_find_sunflower;
The_Plants plants;
Store store;
TheMouseEvent event1;
The_Zombies zombies;
Pea peas;

//部分文字
IMAGE im_lose;
IMAGE im_HugeWave;

void init_pvz()
{
	initgraph(960, 720);
	loadimage(&im_wait, _T("start1.png"));   // 导入背景图片
	/*PlaySound(TEXT("music/music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);*/
	loadimage(&im_bk, _T("background.png"));   // 导入背景图片
	loadimage(&im_big_bk, _T("background2.png"));   // 导入背景图片
	loadimage(&im_find_sunflower, _T("other/findSunflower.png"));   // 导入背景图片
	loadimage(&im_ready, _T("other/ready.png"));   // 导入文字图片
	loadimage(&im_set, _T("other/set.png"));   // 导入文字图片
	loadimage(&im_setplant, _T("other/setplant.png"));   // 导入文字图片
	loadimage(&im_lose, _T("other/lose.png"));   // 导入失败图片
	loadimage(&im_HugeWave, _T("other/Hugewave.png"));   // 导入一大波图片
	Sun::init_img();
	Sunflower::init_img();
	Peashooter::init_img();
	Store::init_img();
	Zombie::init_img();
	Pea::init_img();
}
