#pragma once
#include"player.h"
#include<easyx.h>
#include"image.h"
#include<iostream>
void showplayerstate(Player& b)
{
	IMAGE a;
	loadimage(&a, _T("image\\a.png"));
	image  s(_T("image\\close.png"), _T("image\\close_b.png"));
	putimage(0, 0, &a);
	s.draw(600, 20);
	char c[30];
	sprintf_s(c, "�ȼ���%d", b.level);
	outtextxy(200, 200, c);
	sprintf_s(c, "���飺%d/%d00", b.exp,b.level);
	outtextxy(200, 250, c);
	sprintf_s(c, "������%d", b.atk);
	outtextxy(200, 350, c);
	sprintf_s(c, "Ѫ����%d/%d", b.health,18+2*b.level);
	outtextxy(200, 300, c);
	sprintf_s(c, "�������룺85");
	outtextxy(200, 400, c);
}