#pragma once
#include <easyx.h>
#include "image.h"
#include"monster.h"
#define right 1
#define left -1
#include<vector>
using namespace std;
class Player
{
public:
	int health;
	int atk;
	int defence;
	int walkpeth;
	int attackpeth;
	int x_local;
	int x_gobal;
	int y;
	int v;
	int faceto;
	int speed;
	bool iswalk;
	bool isattack;
	bool isjump;
	int level=1;
	int exp=0;
	void walk(int& x_scence);
	void attack(vector<monster*> mon);
	void action(int& x, vector<monster*> mon);
	void jump();
	void load();
	Player(int health = 20, int atk = 2, int defence = 5, int walkpeth = 0,
		int attackpeth = 0, int x_local =20, int x_gobal = 20, int y = 500, int v = 0,
		int faceto = right, int speed = 75, bool iswalk = false, bool isattack = false,bool isjump=false);
	image player_wlak_Front[2];
	image player_wlak_Back[2];
	image player_attack_Front[2];
	image player_attack_Back[2];
	image player_stand_Front;
	image player_stand_Back;
};
