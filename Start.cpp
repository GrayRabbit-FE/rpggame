#include "Start.h"
#include"Parameter.h"      //参数类，此头文件包含部分图片的位置参数
#include <graphics.h>
#pragma comment(lib,"Winmm.lib")//引用mciSendString()函数
void Start::InitBegin()  //初始化函数，准备图片等
{   
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);//创建窗口
	loadimage(&background, _T("image/background.png"));    //准备所需要的图片
	loadimage(&button_bmp, _T("image/button_bmp.png"));
	loadimage(&beginbutton, _T("image/beginbutton.png"));
	loadimage(&gameselect, _T("image/gameselect.png"));
	loadimage(&handlebutton, _T("image/handlebutton.png"));
	loadimage(&handleui, _T("image/handleui.png"));
	loadimage(&handleui_bmp, _T("image/handleui_bmp.png"));
	loadimage(&back, _T("image/back.png"));
	loadimage(&exitgame, _T("image/exitgame.png"));
	loadimage(&selectone, _T("image/selectone.png"));
	loadimage(&selecttwo, _T("image/selecttwo.png"));
	loadimage(&selectthree, _T("image/selectthree.png"));
	loadimage(&select_bmp, _T("image/select_bmp.png"));
	loadimage(&backbegin,_T("image/backbegin.png"));
	loadimage(&backbegin_bmp, _T("image/backbegin_bmp.png"));
}
void Start::DrawBegin()   //加载开始界面
{
	putimage(0, 0, &background);     //加载背景图片
	mciSendString(_T("open music/begin.mp3  alias bkmusic"), NULL, 0, NULL);//播放开始界面的背景音乐
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
	putimage(GAMEBUTTON_X, GAMEBUTTON_Y, &button_bmp, NOTSRCERASE);  //加载按钮：开始游戏
	putimage(GAMEBUTTON_X, GAMEBUTTON_Y, &beginbutton, SRCINVERT);
	putimage(HANDLEBUTTON_X, HANDLEBUTTON_Y, &button_bmp, NOTSRCERASE);//加载按钮：游戏操作
	putimage(HANDLEBUTTON_X, HANDLEBUTTON_Y, &handlebutton, SRCINVERT);
	putimage(EXITGAME_X, EXITGAME_Y, &button_bmp, NOTSRCERASE);        //加载按钮：退出游戏
	putimage(EXITGAME_X, EXITGAME_Y, &exitgame, SRCINVERT);
}

int Start::ControlBegin()  //控制开始界面的函数
{
	while (true)
	{
		if (MouseHit())   //判断是否有鼠标消息
		{
			m = GetMouseMsg();  //获得一条鼠标消息
			if (m.uMsg == WM_LBUTTONDOWN ) //判读用户是否按下了左键
			{
				if (m.x >= GAMEBUTTON_X && m.x <= GAMEBUTTON_X + 150 && m.y >= GAMEBUTTON_Y && m.y <= GAMEBUTTON_Y + 75)
				{  
					//判读按下左键的同时鼠标是否在开始游戏按钮上（按钮宽150px,高75px）
					return 0;
				}
				if (m.x >= HANDLEBUTTON_X && m.x <= HANDLEBUTTON_X + 150 && m.y >= HANDLEBUTTON_Y && m.y <= HANDLEBUTTON_Y + 75)
				{
					//判读按下左键的同时鼠标是否在游戏操作按钮上（按钮宽150px,高75px）
					return 1;
				}
				if (m.x >= EXITGAME_X && m.x <= EXITGAME_X + 150 && m.y >= EXITGAME_Y && m.y <= EXITGAME_Y + 75)
				{   
					//判读按下左键的同时鼠标是否在退出游戏按钮上（按钮宽150px,高75px）
					return 2;
				}
			}

		}
	}
}
void Start::DrawSelect()  //加载选择关卡界面
{
	mciSendString(_T("close bkmusic"), NULL, 0, NULL);      //关闭初始界面背景音乐
	mciSendString(_T("open music/select.mp3  alias skmusic"), NULL, 0, NULL);//播放新的背景音乐
	mciSendString(_T("play skmusic repeat"), NULL, 0, NULL); 
	putimage(0, 0, &gameselect);                       //加载选择界面的背景图片
	putimage(BACKBEGIN_X, BACKBEGIN_Y, &backbegin_bmp, NOTSRCERASE);//加载返回按钮
	putimage(BACKBEGIN_X, BACKBEGIN_Y, &backbegin, SRCINVERT);
	putimage(SELECTONE_X, SELECTONE_Y, &select_bmp, NOTSRCERASE);
	putimage(SELECTONE_X, SELECTONE_Y, &selectone,SRCINVERT);     //加载关卡一的按钮
	putimage(SELECTTWO_X, SELECTTWO_Y, &select_bmp, NOTSRCERASE);
	putimage(SELECTTWO_X, SELECTTWO_Y, &selecttwo, SRCINVERT);   //加载关卡二的按钮
	putimage(SELECTTHREE_X, SELECTTHREE_Y, &select_bmp, NOTSRCERASE);
	putimage(SELECTTHREE_X, SELECTTHREE_Y, &selectthree, SRCINVERT);//加载关卡三的按钮
}
int Start::ControlSelect()  //控制选择关卡界面的函数
{   
	while (true)
	{
		if (MouseHit())   //判断是否有鼠标消息
		{  
			n = GetMouseMsg();//得到一条鼠标消息
			if (n.uMsg == WM_LBUTTONDOWN)//判断用户是否按下了左键
			{   
				
				if (n.x >= SELECTONE_X && n.x <= SELECTONE_X+75 && n.y >= SELECTONE_Y&& n.y <= SELECTONE_Y+75)
				{    
					//关闭背景音乐，判断是否选择关卡一
					mciSendString(_T("close skmusic"), NULL, 0, NULL);
					return 1;
				}
				if (n.x >= SELECTTWO_X && n.x <= SELECTTWO_X+75 && n.y >= SELECTTWO_Y && n.y <= SELECTTWO_Y+75)
				{   //关闭背景音乐，判断是否选择关卡二
					mciSendString(_T("close skmusic"), NULL, 0, NULL);
					return 2;
				}
				if (n.x >= SELECTTHREE_X && n.x <= SELECTTHREE_X +75&& n.y >= SELECTTHREE_Y && n.y <= SELECTTHREE_Y+75)
				{   //关闭背景音乐，判断是否选择关卡三
					mciSendString(_T("close skmusic"), NULL, 0, NULL);
					return 3;
				}
				if (n.x >= BACKBEGIN_X && n.x <= BACKBEGIN_X + 75 && n.y >= BACKBEGIN_Y && n.y <= BACKBEGIN_Y + 75)
				{   
					mciSendString(_T("close skmusic"), NULL, 0, NULL);
					return 0;
				}
			}
		}
	}

}
void Start::DrawHandle()   //加载游戏操作介绍界面
{
	putimage(0, 0, &handleui_bmp, NOTSRCERASE);//加载介绍的界面
	putimage(0, 0, &handleui, SRCINVERT);
	putimage(BACK_X, BACK_Y, &back);
}
int Start::ControlHandle()   //控制游戏操作界面的函数
{
	while (true)
	{
		if (MouseHit())  //判断是否有鼠标消息
		{
			c = GetMouseMsg();//得到一条鼠标消息
			if (c.uMsg == WM_LBUTTONDOWN)
			{
				if (c.x >= BACK_X && c.x <= BACK_X + 30 && c.y >= BACK_Y && c.y <= BACK_Y +30)
				{   
					//判读按下左键的同时鼠标是否在返回按钮上（按钮宽30px,高30px）
					return  0;
				}
			}
		}
	}
}

