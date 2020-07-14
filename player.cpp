#pragma once
#include "player.h"
#include <windows.h>
#include <easyx.h>
#include "g.h"
#include<vector>
using namespace std;
#define right 1
#define left -1
void Player::load() 
{
	player_stand_Front.load ( _T("resource\\player\\player_stand_Front.png"), _T("resource\\player\\player_stand_Front_b.png"));
	player_stand_Back.load(_T("resource\\player\\player_stand_Back.png"), _T("resource\\player\\player_stand_Back_b.png"));
	player_wlak_Front[0].load(_T("resource\\player\\player_walk1_Front.png"), _T("resource\\player\\player_walk1_Front_b.png"));
	player_wlak_Front[1].load(_T("resource\\player\\player_walk2_Front.png"), _T("resource\\player\\player_walk2_Front_b.png"));
	player_wlak_Back[0].load(_T("resource\\player\\player_walk1_Back.png"), _T("resource\\player\\player_walk1_Back_b.png"));
	player_wlak_Back[1].load(_T("resource\\player\\player_walk2_Back.png"), _T("resource\\player\\player_walk2_Back_b.png"));
	player_attack_Back[0].load(_T("resource\\player\\player_attack1_Back.png"), _T("resource\\player\\player_attack1_Back_b.png"));
	player_attack_Back[1].load(_T("resource\\player\\player_attack2_Back.png"), _T("resource\\player\\player_attack2_Back_b.png"));
	player_attack_Front[0].load(_T("resource\\player\\player_attack1_Front.png"), _T("resource\\player\\player_attack1_Front_b.png"));
	player_attack_Front[1].load(_T("resource\\player\\player_attack2_Front.png"), _T("resource\\player\\player_attack2_Front_b.png"));
}
void Player::walk(int& x_scence)
{
	if (faceto == right)
	{
		if (x_local <= 280)
		{
		x_local += speed / 8;
		x_gobal += speed / 8;
		}
		else if (x_scence < 1300)
		{
			x_scence += speed / 8;
		    x_gobal += speed / 8;
		}
		else if(x_local<=1460)
		{
			x_local += speed / 8;
			x_gobal += speed / 8;
		}
	}
	if (faceto == left)
	{
		if (x_local >= 0)
		{
			x_local -= speed / 8;
			x_gobal -= speed / 8;
		}
		else if (x_scence >= 0)
		{
			x_scence -=speed / 8;
			x_gobal -= speed / 8;
		}
	}
	(faceto == right ? player_wlak_Front[walkpeth] : player_wlak_Back[walkpeth]).draw(x_local, y);
}
void Player::attack(vector<monster*> mon)
{
	if (faceto == right)
	{
		for (int i = 0; i < mon.size(); i++)
		{
			if (mon[i]->loc.x - x_gobal <= 70&& mon[i]->loc.x - x_gobal > 0 && mon[i]->isalive == true&& mon[i]->isactive==true)
			{
				mon[i]->health -= atk;
				if (mon[i]->health <= 0)
				{
					this->exp += 30;
					if (exp >= level * 100)
					{
						
						exp -= level * 100;
						atk += 1;
						health += 2;
						level++;						
					}
					mon[i]->isalive = false;
				}
			}
		}
	}
	else if(attackpeth==1)
	{
			for (int i = 0; i < mon.size(); i++)
			{
				if (x_gobal - mon[i]->loc.x <= 70&& x_gobal - mon[i]->loc.x >0&&mon[i]->isalive==true)
				{
					mon[i]->health -= atk;
					if (mon[i]->health <= 0)
					{
						this->exp += 30;
						if (exp >= level * 100)
						{
						
							exp -= level * 100;
							atk += 1;
							health += 2;	
							level++;							
						}
						mon[i]->isalive = false;
					}
				}
			}
		
	}
	(faceto == right ? player_attack_Front[attackpeth] : player_attack_Back[attackpeth]).draw(x_local, y);
}
void Player::jump()
{
	if (v < 0 && y >= 500)
	{
		isjump = false;
		y = 500;
	}
	else
	{
		y -= v;
		v -= g;
	}
	
	(faceto == right ? player_stand_Front : player_stand_Back).draw(x_local, y);
}
void Player::action(int& x_scence, vector<monster*> mon)
{
	if (iswalk)
	{
		walk(x_scence);
		walkpeth ++;
		if (walkpeth ==2)
		{
			walkpeth = 0;
			iswalk = false;
		}
	}
	else if (isattack)
	{
		attack(mon);
		attackpeth++;
		if (attackpeth == 2)
		{
			attackpeth = 0;
			isattack = false;
		}
	}
	else if (GetAsyncKeyState(0X4A) & 0X8000)
	{
		isattack = true;
		(faceto == right ? player_wlak_Front[walkpeth] : player_wlak_Back[walkpeth]).draw(x_local, y);
	}
	else if (GetAsyncKeyState(0X41) & 0X8000 )
	{
		iswalk = true;
		faceto = left;
		(faceto == right ? player_wlak_Front[walkpeth] : player_wlak_Back[walkpeth]).draw(x_local, y);
	}
	else if(GetAsyncKeyState(0X44) & 0X8000)               
	{
		iswalk = true;
		faceto = right;
		(faceto == right ? player_wlak_Front[walkpeth] : player_wlak_Back[walkpeth]).draw(x_local, y);
	}
	else if(GetAsyncKeyState(0X4B) & 0X8000)
	{		
		if(!isjump)
		v = 40;
		isjump = true;
	}
	else
	{
		(faceto == right ? player_stand_Front : player_stand_Back).draw(x_local, y);
	}
	if (GetAsyncKeyState(0X4B) & 0X8000 && !isattack)
	{
		if (!isjump)
			v = 40;
		isjump = true;

	}
	if (isjump)
	{
		jump();
	}
}
Player::Player(int health, int atk , int defence,
	int walkpeth , int attackpeth , int x_local, 
	int x_gobal , int y,int v,int faceto,int speed ,
	bool iswalk, bool isattack,bool isjump)
{
	this->health = health;
	this->atk = atk;
	this->defence = defence;
	this->walkpeth = walkpeth;
	this->attackpeth = attackpeth;
	this->x_local = x_local;
	this->x_gobal = x_gobal;
	this->y = y;
	this->faceto = faceto;
	this->speed = speed;
	this->iswalk = iswalk;
	this->isattack = isattack;
	this->isjump = isjump;
	this->v = v;
}