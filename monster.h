#pragma once
#include<math.h>
#include"image.h"
#include<iostream>
#define right 1
#define left -1
class loction
{
public :
    int x;
    int y;
};
class monster
{
public:
    int atk;
    float atkcd;
    int health; 
    int speed;
    int walkpeth = 0;
    loction loc;
    int atklen;
    int faceto;
    bool isactive;
    bool isalive;
    virtual void attack(int& player_health, int player_xl, int player_y, int x_scence)=0;
    virtual void walk(int player_xg, int x_scence)=0;
    virtual void action(int& player_health, int player_xl, int player_xg, int player_y, int x_scence)=0;
};
class mushroom :public monster
{
public:
    image mushroom_walk_Back[2];
    image mushroom_walk_Front[2];
    mushroom(int x, int y)
    {

        atk = 2;
        health = 25;
        speed = 2;
        loc.x = x;
        loc.y = y;
        atkcd = 2;
        atklen = 30;
        faceto = left;
        isactive = false;
        isalive = true;
        walkpeth = 0;
        mushroom_walk_Back[0].load(_T("resource\\monster\\mushroom\\mushroom_walk1_Back.png"), _T("resource\\monster\\mushroom\\mushroom_walk1_Back_b.png"));
        mushroom_walk_Back[1].load(_T("resource\\monster\\mushroom\\mushroom_walk2_Back.png"), _T("resource\\monster\\mushroom\\mushroom_walk2_Back_b.png"));
        mushroom_walk_Front[0].load(_T("resource\\monster\\mushroom\\mushroom_walk1_Front.png"), _T("resource\\monster\\mushroom\\mushroom_walk1_Front_b.png"));
        mushroom_walk_Front[1].load(_T("resource\\monster\\mushroom\\mushroom_walk2_Front.png"), _T("resource\\monster\\mushroom\\mushroom_walk2_Front_b.png"));
    }
    virtual void walk(int player_xg, int x_scence)
    {
        if (player_xg > loc.x)
            faceto = right;
        else
            faceto = left;
        if(loc.x-x_scence>=0 && loc.x - x_scence<=640)
        ((faceto == right )? mushroom_walk_Front[walkpeth/5] : mushroom_walk_Back[walkpeth/5]).draw(loc.x-x_scence, loc.y);
        walkpeth++;
        if (walkpeth == 10)
            walkpeth = 0;
        if (faceto == right)
            loc.x += speed ;
        else loc.x -= speed ; 

    }
    virtual void action(int & player_health,int player_xl,int player_xg, int player_y,int x_scence)
    {

        if (!isactive)
        {
            if (abs(loc.x - player_xg) < 640)
                isactive = true;
        }
        else if(isalive)
        {
            char s[20];
            sprintf_s(s, "Ä¢¹½¹Ö||%d/25", health);
            outtextxy(loc.x-x_scence-15,loc.y -60, s);
            if (abs(loc.x - player_xg) > atklen)
            {
                if (walkpeth >= 10)
                    walkpeth /= 2;
                walk(player_xg, x_scence);
            }
            else
                attack(player_health ,player_xl, player_y,x_scence);
        }
        
    }
    virtual void attack(int& player_health, int player_xl , int player_y,int x_scence)
    {
           walkpeth++;
         ((faceto == right) ? mushroom_walk_Front[walkpeth / 10] : mushroom_walk_Back[walkpeth / 10]).draw(loc.x - x_scence, loc.y);
        if (walkpeth == 20)
        { 
            walkpeth = 0; 
            player_health -= atk;
            char s[20];
            sprintf_s(s, "-%d", atk);
            outtextxy(player_xl, player_y-40, s);
        }
       
    }
};
class ice :public monster
{
public:
    image mushroom_walk_Back[2];
    image mushroom_walk_Front[2];
    image mushroom_attack_Back[2];
    image mushroom_attack_Front[2];
    ice(int x, int y)
    {

        atk =4;
        health = 45;
        speed = 1;
        loc.x = x;
        loc.y = y;
        atkcd = 2;
        atklen = 60;
        faceto = left;
        isactive = false;
        isalive = true;
        walkpeth = 0;
        mushroom_walk_Back[0].load(_T("resource\\monster\\ice\\ice_walk1_Back.png"), _T("resource\\monster\\ice\\ice_walk1_Back_b.png"));
        mushroom_walk_Back[1].load(_T("resource\\monster\\ice\\ice_walk2_Back.png"), _T("resource\\monster\\ice\\ice_walk2_Back_b.png"));
        mushroom_walk_Front[0].load(_T("resource\\monster\\ice\\ice_walk1_Front.png"), _T("resource\\monster\\ice\\ice_walk1_Front_b.png"));
        mushroom_walk_Front[1].load(_T("resource\\monster\\ice\\ice_walk2_Front.png"), _T("resource\\monster\\ice\\ice_walk2_Front_b.png"));
        mushroom_attack_Back[0].load(_T("resource\\monster\\ice\\ice_walk1_Back.png"), _T("resource\\monster\\ice\\ice_walk1_Back_b.png"));
        mushroom_attack_Back[1].load(_T("resource\\monster\\ice\\ice_attack_Back.png"), _T("resource\\monster\\ice\\ice_attack_Back_b.png"));
        mushroom_attack_Front[0].load(_T("resource\\monster\\ice\\ice_walk1_Front.png"), _T("resource\\monster\\ice\\ice_walk1_Front_b.png"));
        mushroom_attack_Front[1].load(_T("resource\\monster\\ice\\ice_attack_Front.png"), _T("resource\\monster\\ice\\ice_attack_Front_b.png"));
    }
    virtual void walk(int player_xg, int x_scence)
    {
        if (player_xg > loc.x)
            faceto = right;
        else
            faceto = left;
        if (loc.x - x_scence >= 0 && loc.x - x_scence <= 640)
            ((faceto == right) ? mushroom_walk_Front[walkpeth / 5] : mushroom_walk_Back[walkpeth / 5]).draw(loc.x - x_scence, loc.y);
        walkpeth++;
        if (walkpeth == 10)
            walkpeth = 0;
        if (faceto == right)
            loc.x += speed;
        else loc.x -= speed;

    }
    virtual void action(int& player_health, int player_xl, int player_xg, int player_y, int x_scence)
    {

        if (!isactive)
        {
            if (abs(loc.x - player_xg) < 640)
                isactive = true;
        }
        else if (isalive)
        {
            char s[20];
            sprintf_s(s, "±ù¹Ö||%d/45", health);
            outtextxy(loc.x - x_scence - 15, loc.y -100, s);
            if (abs(loc.x - player_xg) > atklen)
            {
                if (walkpeth >= 10)
                    walkpeth /= 2;
                walk(player_xg, x_scence);
            }
            else
                attack(player_health, player_xl, player_y, x_scence);
        }

    }
    virtual void attack(int& player_health, int player_xl, int player_y, int x_scence)
    {
        walkpeth++;
        ((faceto == right) ? mushroom_attack_Front[walkpeth / 10] : mushroom_attack_Back[walkpeth / 10]).draw(loc.x - x_scence, loc.y);
        if (walkpeth == 20)
        {
            walkpeth = 0;
            player_health -= atk;
            char s[20];
            sprintf_s(s, "-%d", atk);
            outtextxy(player_xl, player_y - 40, s);
        }

    }
};

class bird :public monster
{
public:
    image mushroom_walk_Back[4];
    image mushroom_walk_Front[4];
    bird(int x, int y)
    {

        atk = 7;
        health = 100;
        speed = 1;
        loc.x = x;
        loc.y = y;
        atkcd = 2;
        atklen = 60;
        faceto = left;
        isactive = false;
        isalive = true;
        walkpeth = 0;
        mushroom_walk_Back[0].load(_T("resource\\monster\\bird\\bird_walk1_Back.png"), _T("resource\\monster\\bird\\bird_walk1_Back_b.png"));
        mushroom_walk_Back[1].load(_T("resource\\monster\\bird\\bird_walk2_Back.png"), _T("resource\\monster\\bird\\bird_walk2_Back_b.png"));
        mushroom_walk_Front[0].load(_T("resource\\monster\\bird\\bird_walk1_Front.png"), _T("resource\\monster\\bird\\bird_walk1_Front_b.png"));
        mushroom_walk_Front[1].load(_T("resource\\monster\\bird\\bird_walk2_Front.png"), _T("resource\\monster\\bird\\bird_walk2_Front_b.png"));
        mushroom_walk_Back[2].load(_T("resource\\monster\\bird\\bird_walk3_Back.png"), _T("resource\\monster\\bird\\bird_walk3_Back_b.png"));
        mushroom_walk_Back[3].load(_T("resource\\monster\\bird\\bird_walk4_Back.png"), _T("resource\\monster\\bird\\bird_walk4_Back_b.png"));
        mushroom_walk_Front[2].load(_T("resource\\monster\\bird\\bird_walk3_Front.png"), _T("resource\\monster\\bird\\bird_walk3_Front_b.png"));
        mushroom_walk_Front[3].load(_T("resource\\monster\\bird\\bird_walk4_Front.png"), _T("resource\\monster\\bird\\bird_walk4_Front_b.png"));
    }
    virtual void walk(int player_xg, int x_scence)
    {
        if (player_xg > loc.x)
            faceto = right;
        else
            faceto = left;
        if (loc.x - x_scence >= 0 && loc.x - x_scence <= 640)
            ((faceto == right) ? mushroom_walk_Front[walkpeth / 3] : mushroom_walk_Back[walkpeth / 3]).draw(loc.x - x_scence, loc.y);
        walkpeth++;
        if (walkpeth == 10)
            walkpeth = 0;
        if (faceto == right)
            loc.x += speed;
        else loc.x -= speed;

    }
    virtual void action(int& player_health, int player_xl, int player_xg, int player_y, int x_scence)
    {

        if (!isactive)
        {
            if (abs(loc.x - player_xg) < 640)
                isactive = true;
        }
        else if (isalive)
        {
            char s[20];
            sprintf_s(s, "¾ÞÄñ||%d/100", health);
            outtextxy(loc.x - x_scence - 15, loc.y - 100, s);
            if (abs(loc.x - player_xg) > atklen)
            {
                if (walkpeth >= 10)
                    walkpeth /= 2;
                walk(player_xg, x_scence);
            }
            else
                attack(player_health, player_xl, player_y, x_scence);
        }

    }
    virtual void attack(int& player_health, int player_xl, int player_y, int x_scence)
    {
        walkpeth++;
        ((faceto == right) ? mushroom_walk_Front[walkpeth / 5] : mushroom_walk_Back[walkpeth /5]).draw(loc.x - x_scence, loc.y);
        if (walkpeth == 20)
        {
            walkpeth = 0;
            player_health -= atk;
            char s[20];
            sprintf_s(s, "-%d", atk);
            outtextxy(player_xl, player_y - 40, s);
        }

    }
};