#pragma once
#include <graphics.h>
//������ע�;���cppԴ�ļ���
class Start
{
public:
	void  InitBegin();
	void  DrawBegin();
	int   ControlBegin();
	void  DrawSelect();
	void  DrawHandle();
	int   ControlSelect();
	int  ControlHandle();
private:
	IMAGE background,beginbutton,button_bmp,handlebutton,handleui,handleui_bmp,back,gameselect,exitgame,selectone,selecttwo,selectthree,select_bmp,backbegin,backbegin_bmp;
	MOUSEMSG m,n,c;
};
