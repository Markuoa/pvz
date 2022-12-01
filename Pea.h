#pragma once
#include <graphics.h>  
#include <iostream>
#include <conio.h>
#include <vector>
#include <list>
#include "EasyXPng.h"
class Pea
{
public:
	static IMAGE im_pea;
	static void init_img(void);

	std::vector<std::list<int>> the_peas;

	Pea();
	int coordinate_to_pix_y(int);
	void add_pea();
	void show();
};