// pvz.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <graphics.h>  
#include <conio.h>
#include <time.h>
#include "i1.h"

extern IMAGE im_bk;
extern IMAGE im_lose;
extern Store store;
extern The_Plants plants;
extern Zombie zombie;
extern Pea peas;

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
        catch(std::exception e) {
            putimagePng(180, 140, &im_lose);
            FlushBatchDraw();
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



