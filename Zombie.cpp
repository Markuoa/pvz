#include "Zombie.h"

std::vector<IMAGE> Zombie::im_zombie{};

void Zombie::init_img(void)
{
	im_zombie.resize(22);
	for (int i = 0; i <= 9; i++)
	{
		TCHAR src[20] = _T("zombie/0.png");
		src[7] = i + '0';
		loadimage(&im_zombie[i], src);   // 导入图片
	}
	for (int i = 0; i <= 9; i++)
	{
		TCHAR src[20] = _T("zombie/10.png");
		src[8] = i + '0';
		loadimage(&im_zombie[i + 10], src);   // 导入图片
	}
	for (int i = 0; i <= 1; i++)
	{
		TCHAR src[20] = _T("zombie/20.png");
		src[8] = i + '0';
		loadimage(&im_zombie[i + 10], src);   // 导入图片
	}
}

Zombie::Zombie(void)
{
	coordinate_y = rand() % 5;
	switch (coordinate_y)
	{
	case 0:
		pix_y = 120;
		break;
	case 1:
		pix_y = 240;
		break;
	case 2:
		pix_y = 360;
		break;
	case 3:
		pix_y = 480;
		break;
	case 4:
		pix_y = 600;
		break;
	default:
		break;
	}
}

Zombie::Zombie(int y)
{
	coordinate_y = y;
	switch (coordinate_y)
	{
	case 0:
		pix_y = 67;
		break;
	case 1:
		pix_y = 187;
		break;
	case 2:
		pix_y = 315;
		break;
	case 3:
		pix_y = 430;
		break;
	case 4:
		pix_y = 547;
		break;
	default:
		break;
	}
}

void Zombie::update(std::vector<std::vector<Plant*>>& the_Plants)
{
	pix_x -= 1;
}

void Zombie::show(std::vector<std::vector<Plant*>>& the_Plants)
{
	update(the_Plants);
	putimagePng(pix_x, pix_y, &im_zombie[status]);
	status = (status + 1) % 20;
	if (pix_x < -110)
	{
		std::exception e;
		throw e;
	}
}


