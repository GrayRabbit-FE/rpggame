#pragma once
#include <graphics.h>
//函数的注释均在cpp源文件中
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
