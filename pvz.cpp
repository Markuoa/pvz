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
    


    
    PlaySound(NULL, NULL, SND_FILENAME);
    mciSendString(L"open music/Grasswalk.wav", NULL, 0, NULL);
    mciSendString(L"play music/Grasswalk.wav", NULL, 0, NULL);
    //PlaySound(TEXT("music/Grasswalk.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    std::string command = "None";
    zombies.start = clock();
    zombies.init_wave(2);
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
            if (peekmessage(&m))
                if (m.message == WM_LBUTTONDOWN) {
                    if (m.x >= card_x && m.x < card_x + card_width && m.y >= card_y && m.y < card_y + card_y + caard_height)
                    {
                        flushmessage();
                        mciSendString(L"close music/Grasswalk.wav", NULL, 0, NULL);
                        break;
                    }
                }
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
                //if (m.x >= card_x && m.x < card_x + card_width && m.y >= card_y && m.y < card_y + card_y + caard_height)
                //    break;
            }
        flushmessage();
        Sleep(50);
    }

}



