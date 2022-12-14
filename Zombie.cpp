#include "Zombie.h"

std::vector<IMAGE> Zombie::im_zombie{};
std::vector<IMAGE> Zombie::im_zombie_eat{};
std::vector<IMAGE> Zombie::im_zombie_die{};

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
		loadimage(&im_zombie[i + 20], src);   // 导入图片
	}

	//eat
	im_zombie_eat.resize(22);
	for (int i = 0; i <= 9; i++)
	{
		TCHAR src[20] = _T("zombie/eat/1.png");
		src[11] = i + '0';
		loadimage(&im_zombie_eat[i], src);   // 导入图片
	}
	for (int i = 0; i <= 9; i++)
	{
		TCHAR src[20] = _T("zombie/eat/10.png");
		src[12] = i + '0';
		loadimage(&im_zombie_eat[i + 10], src);   // 导入图片
	}
	for (int i = 0; i <= 1; i++)
	{
		TCHAR src[20] = _T("zombie/eat/20.png");
		src[12] = i + '0';
		loadimage(&im_zombie_eat[i + 20], src);   // 导入图片
	}

	//die
	im_zombie_die.resize(10);
	for (int i = 0; i <= 9; i++)
	{
		TCHAR src[20] = _T("zombie/die/1.png");
		src[11] = i + '0';
		loadimage(&im_zombie_die[i], src);   // 导入图片
	}
}

Zombie::Zombie(void)
{
	coordinate_y = rand() % 5;
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
		pix_y = 550;
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
		pix_y = 550;
		break;
	default:
		break;
	}
}

Zombie::Zombie(int y, int p_x)
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
		pix_y = 550;
		break;
	default:
		break;
	}
	this->pix_x = pix_x;
}

int Zombie::pix_to_coordinate_x(int p_x)
{
	int x;
	if (p_x >= -50 && p_x <= 50) x = 0;
	else if (p_x >= 50 && p_x < 135) x = 1;
	else if (p_x >= 135 && p_x < 220) x = 2;
	else if (p_x >= 220 && p_x < 305) x = 3;
	else if (p_x >= 305 && p_x < 390) x = 4;
	else if (p_x >= 390 && p_x < 480) x = 5;
	else if (p_x >= 480 && p_x < 565) x = 6;
	else if (p_x >= 565 && p_x < 650) x = 7;
	else if (p_x >= 650 && p_x < 745) x = 8;
	else if (p_x >= 745) x = 9;
	else x = -1;
	return x;
}

int Zombie::update(std::vector<std::vector<Plant*>>& the_Plants, std::vector<std::list<int>>& peas)
{
	//更新状态图片
	if (situation == 1 || situation == 2)
	{
		//status = (status + 1) % 22;
		status += 0.5;
		if (status == 22) status = 0;
	}
	coordinate_x = pix_to_coordinate_x(pix_x);
	//位移
	if (situation == 1)
	{
		pix_x -= 0.5;
	}
	//遇到植物进入eat状态，植物扣血
	if (situation == 1 || situation == 2)
	{
		//植物攻击，僵尸攻击
		//植物攻击
		for (int j = 0; j <= coordinate_x; j++)
		{
			if (j == 9) break;
			if (the_Plants[coordinate_y][j] != nullptr)
				the_Plants[coordinate_y][j]->exist_zombie_right = true;
		}
		//超出屏幕，不会啃食，屏幕内，可能啃食植物
		if (coordinate_x != 9 && coordinate_x != -1 && the_Plants[coordinate_y][coordinate_x] != nullptr)
		{
			//eat
			the_Plants[coordinate_y][coordinate_x]->HP--;
			situation = 2;
			if (the_Plants[coordinate_y][coordinate_x]->HP <= 0)
			{
				delete(the_Plants[coordinate_y][coordinate_x]);
				the_Plants[coordinate_y][coordinate_x] = nullptr;
				situation = 1;
			}
		}
		//僵尸挨子弹
		for (std::list<int>::iterator iter = peas[coordinate_y].begin(); iter != peas[coordinate_y].end();)
		{
			if (*iter - pix_x > 45 && *iter - pix_x < 110)
			{
				iter = peas[coordinate_y].erase(iter);
				HP = HP - 20;
				if (HP < 0) {
					situation = 3;
					status = -1;
					//植物攻击结束
					for (int j = 0; j <= coordinate_x; j++)
					{
						if (j == 9) break;
						if (the_Plants[coordinate_y][j] != nullptr)
							the_Plants[coordinate_y][j]->exist_zombie_right = false;
					}
				} 
				break;
			}
			++iter;
		}
	}

	//死亡
	if (situation == 3) {
		status++;
		if (status == 9) situation = 4; //真正死亡
	}
	return 1;
}

void Zombie::show(std::vector<std::vector<Plant*>>& the_Plants, std::vector<std::list<int>>& peas)
{
	update(the_Plants, peas);
	int status_int = (int)status;
	if (situation == 1)
		putimagePng(pix_x, pix_y, &im_zombie[status_int]);
	if (situation == 2)
		putimagePng(pix_x, pix_y, &im_zombie_eat[status_int]);
	if (situation == 3)
		putimagePng(pix_x, pix_y, &im_zombie_die[status_int]);
	if (pix_x < -110)
	{
		throw "Lose";
	}
}


