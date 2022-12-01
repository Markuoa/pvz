#include "Pea.h"

IMAGE Pea::im_pea;

Pea::Pea(void)
{
	the_peas.resize(5);
}

int Pea::coordinate_to_pix_y(int coordinate_y)
{
	int pix_y;
	switch (coordinate_y)
	{
	case 0:
		pix_y = 125;
		break;
	case 1:
		pix_y = 241;
		break;
	case 2:
		pix_y = 364;
		break;
	case 3:
		pix_y = 485;
		break;
	case 4:
		pix_y = 605;
		break;
	default:
		break;
	}
	return pix_y;
}

void Pea::init_img(void)
{
	loadimage(&im_pea, _T("other/pea.png"));   // µº»ÎÕº∆¨
}

void Pea::add_pea()
{
	;
}

void Pea::show()
{
	for (int i = 0; i <= 4; i++)
	{
		int pix_y = coordinate_to_pix_y(i);
		for (auto& pix_x : the_peas[i])
		{
			pix_x = pix_x + 10;
			int a = im_pea.getheight();
			putimagePng(pix_x, pix_y, &im_pea);
		}
	}
}
