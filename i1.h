#pragma once
#include <graphics.h>  
#include <conio.h>
#include <vector>
#include "Sunflower.h"
#include "Peashooter.h"
#include "The_Plants.h"
#include "Sun.h"
#include "Store.h"
#include "The_Zombies.h"
#include "Pea.h"

extern IMAGE im_bk;
extern IMAGE im_lose;

extern The_Plants plants;
extern The_Zombies zombies;
extern Pea peas;

void init_pvz(void);

class TheMouseEvent
{
public:
	bool click = false;
	IMAGE im_move;
	int chosePlant_index = -1;


	TheMouseEvent();
	void update();
	std::pair<int, int> pixel_to_coordinate_plant(int, int);
};

class Store
{
public:
	int x;
	int y;
	bool Pea_avalaible = true;
	bool Sunflower_avalaible = true;
	clock_t start;
	clock_t now = 0;
	int now_second = 0;
	Sun* sun;
	int count_sun = 500;
	//以下几个IMAGE
	//store:(0,0)
	//card:起始点(132,5),宽53，高75
	static IMAGE im_store;
	static IMAGE im_Sunflower_card;
	static IMAGE im_Peashooter_card;
	static IMAGE im_Peashooter_card_2;


	Store();
	static void init_img();
	void show();
	void update();
	bool click_sun(int, int);
};

extern TheMouseEvent event1;
extern Store store;
