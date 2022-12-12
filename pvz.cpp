// pvz.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <graphics.h>  
#include <conio.h>
#include <time.h>
#include "i1.h"
const int card_x = 600;
const int card_y = 350;
extern const int card_width;
extern const int caard_height;
extern IMAGE im_wait;
extern IMAGE im_bk;
extern IMAGE im_big_bk;
extern IMAGE im_lose;
extern IMAGE im_ready;
extern IMAGE im_set;
extern IMAGE im_setplant;
extern IMAGE im_find_sunflower;
extern IMAGE im_HugeWave;
extern IMAGE im_win;
extern IMAGE im_end;
extern Store store;
extern The_Plants plants;
extern Zombie zombie;
extern Pea peas;

extern int level;
clock_t start;
clock_t now;
int font = 0;
int main()
{
    init_pvz();
    //1-1进场界面
    PlaySound(TEXT("music/Choose Your Seeds.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    ExMessage m;
    while (true)
    {
        putimage(0, 0, &im_wait);
        if (peekmessage(&m)) 
            if (m.message == WM_LBUTTONDOWN) {
                flushmessage();
                break;
        }
    }
    for (int pix_left = 0; pix_left > -690; pix_left = pix_left-3)
    {
        putimage(pix_left, 0, &im_big_bk);
        Sleep(1);
    }
    Sleep(500);
    for (int pix_left = -690; pix_left <=-240; pix_left = pix_left+3)
    {
        putimage(pix_left, 0, &im_big_bk);
        Sleep(1);
    }

    BeginBatchDraw();
    for (int font = 0; font <= 2; font++)
    {
        cleardevice();
        putimagePng(-240, 0, &im_big_bk);
        switch (font)
        {
        case 0:
            putimagePng(440, 320, &im_ready);
            break;
        case 1:
            putimagePng(420, 320, &im_set);
            break;
        case 2:
            putimagePng(420, 320, &im_setplant);
            break;
        case 4:
            putimagePng(190, 320, &im_HugeWave);
            break;
        default:
            break;
        }
        FlushBatchDraw();
        Sleep(1000);
    }
    //exit(0);
    //1-1正式开始
    PlaySound(NULL, NULL, SND_FILENAME);
    mciSendString(L"open music/Grasswalk.wav", NULL, 0, NULL);
    mciSendString(L"play music/Grasswalk.wav", NULL, 0, NULL);
    std::string command = "None";
    zombies.flush_zombie();
    zombies.wave = 0;
    zombies.start = clock();
    zombies.init_wave(1);
    count_sun = 150;
    while (true)
    {   
        cleardevice();
        putimage(0, 0, &im_bk);
        if(event1.update()=="pass")
        {
            mciSendString(L"close music/Grasswalk.wav", NULL, 0, NULL); 
            event1.pass = false;
            break;
        }
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
            }
            if (e == "HugeWave")
            {
                start = clock();
                font = 4;
            }
            if (e == "pass")
            {
                putimagePng(card_x, card_y, &(store.im_Sunflower_card));
                command = "Pass";
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
        if (command == "Pass")
        {
            event1.pass = true;
        }
        FlushBatchDraw();
        flushmessage();
        Sleep(30);
    }
    //1.1结束，向日葵展示页面
    mciSendString(L"close music/Grasswalk.wav", NULL, 0, NULL);
    mciSendString(L"open music/Zen.mp3", NULL, 0, NULL);
    mciSendString(L"play music/Zen.mp3", NULL, 0, NULL);
    while (true)
    {
        putimage(0, 0, &im_find_sunflower);
        FlushBatchDraw();
        if (peekmessage(&m))
            if (m.message == WM_LBUTTONDOWN) {

                break;
            }
        flushmessage();
        Sleep(50);
    }

    //1-2进场界面
    level = 2;
    mciSendString(L"close music/Zen.mp3", NULL, 0, NULL);
    PlaySound(TEXT("music/Choose Your Seeds.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    for (int pix_left = 0; pix_left > -690; pix_left = pix_left - 3)
    {
        putimage(pix_left, 0, &im_big_bk);
        FlushBatchDraw();
        Sleep(1);
    }
    Sleep(500);
    for (int pix_left = -690; pix_left <= -240; pix_left = pix_left + 3)
    {
        putimage(pix_left, 0, &im_big_bk);
        FlushBatchDraw();
        Sleep(1);
    }
    for (int font = 0; font <= 2; font++)
    {
        cleardevice();
        putimagePng(-240, 0, &im_big_bk);
        switch (font)
        {
        case 0:
            putimagePng(440, 320, &im_ready);
            break;
        case 1:
            putimagePng(420, 320, &im_set);
            break;
        case 2:
            putimagePng(420, 320, &im_setplant);
            break;
        case 4:
            putimagePng(190, 320, &im_HugeWave);
            break;
        default:
            break;
        }
        FlushBatchDraw();
        Sleep(1000);
    }
    //1-2正式开始
    PlaySound(NULL, NULL, SND_FILENAME);
    mciSendString(L"open music/Grasswalk.wav", NULL, 0, NULL);
    mciSendString(L"play music/Grasswalk.wav", NULL, 0, NULL);
    zombies.flush_zombie();
    //测试，无问题

    command = "None";
    count_sun = 100;
    plants.flush_plants();
    peas.flush_pea();
    zombies.start = clock();
    zombies.wave = 0;
    //测试，无问题
    zombies.init_wave(2);
    //测试，有问题，大大的问题
    //不要memset对二维vector赋值
    while (true)
    {
        cleardevice();
        putimage(0, 0, &im_bk);
        if (event1.update() == "pass")
        {
            mciSendString(L"close music/Grasswalk.wav", NULL, 0, NULL);
            event1.pass = false;
            break;
        }
        store.show();
        plants.show_Plants();
        peas.show();
        try {
            zombies.show_Zombies(plants.the_Plants, peas.the_peas);
        }
        catch (const char* e) {
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
                putimagePng(card_x, card_y, &(im_win));
                command = "Pass";
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
        if (command == "Pass")
        {
            event1.pass = true;
        }
        FlushBatchDraw();
        flushmessage();
        Sleep(30);
    }
    //1.2结束，奖杯展示页面
    mciSendString(L"close music/Grasswalk.wav", NULL, 0, NULL);
    mciSendString(L"open music/Zen.mp3", NULL, 0, NULL);
    mciSendString(L"play music/Zen.mp3", NULL, 0, NULL);
    while (true)
    {
        putimage(0, 0, &im_end);
        FlushBatchDraw();
        if (peekmessage(&m))
            if (m.message == WM_LBUTTONDOWN) {
                exit(0);
                break;
            }
        flushmessage();
        Sleep(50);
    }
    exit(0);
}