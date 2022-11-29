#pragma once
#include <graphics.h>  
#include <iostream>
#include <conio.h>

class Plant
{
public:
	int x, y;

	Plant();
	Plant(int m_x, int m_y) :x(m_x), y(m_y) {};
	std::pair<int, int> coordinate_to_pixel(int, int);
	virtual void show()=0;
};