#pragma once
#include<easyx.h>
#include "player.h"
#include "g.h"
#include <string>
#include"image.h"
#include"monster.h"
#include<time.h>
#include<vector>
#include <mmsystem.h>
#include"mianban.h"
#pragma comment(lib,"Winmm.lib")
using namespace std;
#define right 1
#define left -1
class Manager
{
public:
	IMAGE getscence1();
    IMAGE getscence2(); 
    IMAGE getscence3();
	void level1(Player& player);
    void level2(Player& player);
    void level3(Player& player);
    void showstate(Player& player);
    
};
IMAGE Manager::getscence1()
{
	IMAGE Scence1;
	loadimage(&Scence1, _T("resource\\scence1.png"));
	return Scence1;
}
IMAGE Manager::getscence2()
{
    IMAGE Scence1;
    loadimage(&Scence1, _T("resource\\scence2.png"));
    return Scence1;
}
IMAGE Manager::getscence3()
{
    IMAGE Scence1;
    loadimage(&Scence1, _T("resource\\scence3.png"));
    return Scence1;
}
void Manager::showstate(Player& player)
{
    char s[20];
    sprintf_s(s, "生命：%d", player.health);
    outtextxy(0, 0, s);
    sprintf_s(s, "等级：%d", player.level);
    outtextxy(0, 20, s);
    sprintf_s(s, "经验：%d/%d00", player.exp,player.level);
    outtextxy(0, 40, s);
}
void Manager::level1(Player& player)
{
    image mianban(_T("resource\\shuxing\\a.png"), _T("resource\\shuxing\\a_b.png"));
    mciSendString(_T("close skmusic"), NULL, 0, NULL);      //关闭初始界面背景音乐
    mciSendString(_T("open music/levelone.mp3  alias levelone"), NULL, 0, NULL);//播放新的背景音乐
    mciSendString(_T("play levelone repeat"), NULL, 0, NULL);
    int t_start=clock(), t_now;
    int x_scence=0;
    vector<monster*>  mon = { 
        new mushroom(600, 480), new mushroom(650, 480), new mushroom(700, 480), 
        new mushroom(800, 480), new mushroom(900, 480), new mushroom(1000, 480), 
        new mushroom(1100, 480), new mushroom(1200, 480),new mushroom(1300, 480), 
        new mushroom(1400, 480), new mushroom(1500, 480), new mushroom(1600, 480)
    };
    IMAGE Scence1 = getscence1();
    player.load();
    int& a = x_scence;
    setbkmode(TRANSPARENT);
    settextcolor(RED);
    int numofalive=0;
    while (1)
    {
        t_now =clock();
        if (t_now-t_start>=50)
        {
            putimage(0,0,640,640 ,&Scence1,x_scence,0);
            numofalive = 0;
            for(int i=0;i<12;i++)
            { 
                if (mon[i]->isalive == true)
                    numofalive++;
                if(mon[i]->isalive == true)
                mon[i]->action(player.health,player.x_local,player.x_gobal,player.y, x_scence);
                if (player.health <= 0)
                {
                    mciSendString(_T("close levelone"), NULL, 0, NULL);
                    return ;
                }              
            }
             if (numofalive == 0)
                {
                    mciSendString(_T("close levelone"), NULL, 0, NULL);
                    return ;//生成返回点
                }
            player.action(a,mon);      
            showstate(player);
            mianban.draw(80, 120);
            t_start = t_now;
        }
        if(MouseHit())
            {                
                MOUSEMSG a=GetMouseMsg();
                bool isclose=true;
                if (a.mkLButton == true && a.x >= 0 && a.x <= 200 && a.y <= 185 && a.y >= 115)//点击面板按钮
                {
                    isclose = false;
                    showplayerstate(player); //打开面板
                }
                     while (!isclose)
                     {
                         if (MouseHit())
                         {
                             a = GetMouseMsg();
                             if (a.mkLButton == true && a.x >= 560 && a.x <= 640 && a.y >= 0 && a.y <= 80)
                                 isclose = true;

                         }
                     };
            }      
    }
    
}
void Manager::level2(Player& player)
{
    image mianban(_T("resource\\shuxing\\a.png"), _T("resource\\shuxing\\a_b.png"));
    mciSendString(_T("close skmusic"), NULL, 0, NULL);      //关闭初始界面背景音乐
    mciSendString(_T("open music/leveltwo.mp3  alias leveltwo"), NULL, 0, NULL);//播放新的背景音乐
    mciSendString(_T("play leveltwo repeat"), NULL, 0, NULL);
    int t_start = clock(), t_now;
    int x_scence = 0;
    vector<monster*>  mon = { new ice(800, 480), new ice(400, 480),
         new ice(650, 480), new ice(1000, 480),new ice(1300, 480), new ice(1600, 480)
    };
    IMAGE Scence1 = getscence2();
    player.load();
    int& a = x_scence;
    setbkmode(TRANSPARENT);
    settextcolor(RED);
    int numofalive = 0;
    while (1)
    {
        t_now = clock();
        if (t_now - t_start >= 50)
        {
            putimage(0, 0, 640, 640, &Scence1, x_scence, 0);
            numofalive = 0;
            for (int i = 0; i <6; i++)
            {
                if (mon[i]->isalive == true)
                    numofalive++;
                if (mon[i]->isalive == true)
                    mon[i]->action(player.health, player.x_local, player.x_gobal, player.y, x_scence);
                if (player.health <= 0)
                {
                    mciSendString(_T("close leveltwo"), NULL, 0, NULL);
                    return;
                }         
            }
                if (numofalive == 0)
                {
                    mciSendString(_T("close leveltwo"), NULL, 0, NULL);
                    return;//生成返回点
                }
            player.action(a, mon);
            showstate(player);
            mianban.draw(80, 120);
            t_start = t_now;
        }
        if (MouseHit())
        {
            MOUSEMSG a = GetMouseMsg();
            bool isclose = true;
            if (a.mkLButton == true && a.x >= 0 && a.x <= 200 && a.y <= 185 && a.y >= 115)//点击面板按钮
            {
                isclose = false;
                showplayerstate(player); //打开面板
            }
            while (!isclose)
            {
                if (MouseHit())
                {
                    a = GetMouseMsg();
                    if (a.mkLButton == true && a.x >= 560 && a.x <= 640 && a.y >= 0 && a.y <= 80)
                        isclose = true;

                }
            };
        }
    }

}
void Manager::level3(Player& player)
{
    image mianban(_T("resource\\shuxing\\a.png"), _T("resource\\shuxing\\a_b.png"));
    mciSendString(_T("close skmusic"), NULL, 0, NULL);      //关闭初始界面背景音乐
    mciSendString(_T("open music/levelthree.mp3  alias levelthree"), NULL, 0, NULL);//播放新的背景音乐
    mciSendString(_T("play levelthree repeat"), NULL, 0, NULL);
    int t_start = clock(), t_now;
    int x_scence = 0;
    vector<monster*>  mon = { new bird(800, 480), new bird(400, 480),
         new bird(650, 480), new  bird(1000, 480),new bird(1300, 480), new bird(1600, 480)
    };
    IMAGE Scence1 = getscence3();
    player.load();
    int& a = x_scence;
    setbkmode(TRANSPARENT);
    settextcolor(RED);
    int numofalive = 0;
    while (1)
    {
        t_now = clock();
        if (t_now - t_start >= 50)
        {
            putimage(0, 0, 640, 640, &Scence1, x_scence, 0);
            numofalive = 0;
            for (int i = 0; i < 6; i++)
            {
                if (mon[i]->isalive == true)
                    numofalive++;
                if (mon[i]->isalive == true)
                    mon[i]->action(player.health, player.x_local, player.x_gobal, player.y, x_scence);
                if (player.health <= 0)
                {
                    mciSendString(_T("close levelthree"), NULL, 0, NULL);
                    return;

                }
               
            }
                if (numofalive == 0)
                {
                    mciSendString(_T("close levelthree"), NULL, 0, NULL);
                    return;//生成返回点
                }
            player.action(a, mon);
            showstate(player);
            mianban.draw(80, 120);
            t_start = t_now;
        }
        if (MouseHit())
        {
            MOUSEMSG a = GetMouseMsg();
            bool isclose = true;
            if (a.mkLButton == true && a.x >= 0 && a.x <= 200 && a.y <= 185 && a.y >= 115)//点击面板按钮
            {
                isclose = false;
                showplayerstate(player); //打开面板
            }
            while (!isclose)
            {
                if (MouseHit())
                {
                    a = GetMouseMsg();
                    if (a.mkLButton == true && a.x >= 560 && a.x <= 640 && a.y >= 0 && a.y <= 80)
                        isclose = true;

                }
            };
        }
    }

}
