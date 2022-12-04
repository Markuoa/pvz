// pvz.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <graphics.h>  
#include <conio.h>
#include <time.h>
#include "i1.h"

extern IMAGE im_bk;
extern IMAGE im_lose;
extern IMAGE im_HugeWave;
extern Store store;
extern The_Plants plants;
extern Zombie zombie;
extern Pea peas;

clock_t start;
clock_t now;
int font = 0;
int main()
{
    init_pvz();

    
    BeginBatchDraw();

    while (true)
    {   
        cleardevice();
        putimage(0, 0, &im_bk);
        event1.update();
        store.show();
        plants.show_Plants();
        peas.show();
        try {
            zombies.show_Zombies(plants.the_Plants, peas.the_peas);
        }
        catch(const char* e) {
            if (e == "Lose")
            {
                putimagePng(180, 140, &im_lose);
                FlushBatchDraw();
                break;
            }
            if (e == "HugeWave")
            {
                start = clock();
                font = 4;
            }
            if (e == "pass")
            {
                putimagePng(300, 350, &(store.im_Sunflower_card));
            }
        }
        now = clock();
        int now_second = (now - start) / CLOCKS_PER_SEC;
        switch (font)
        {
        case 4:
            putimagePng(190, 320, &im_HugeWave);
            if (now_second >= 4)   font = 0;
            break;
        default:
            break;
        }
        FlushBatchDraw();
        Sleep(30);
    }
    while (true)
    {
        ;
    }
}



