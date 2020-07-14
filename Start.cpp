#include "Start.h"
#include"Parameter.h"      //�����࣬��ͷ�ļ���������ͼƬ��λ�ò���
#include <graphics.h>
#pragma comment(lib,"Winmm.lib")//����mciSendString()����
void Start::InitBegin()  //��ʼ��������׼��ͼƬ��
{   
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);//��������
	loadimage(&background, _T("image/background.png"));    //׼������Ҫ��ͼƬ
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
void Start::DrawBegin()   //���ؿ�ʼ����
{
	putimage(0, 0, &background);     //���ر���ͼƬ
	mciSendString(_T("open music/begin.mp3  alias bkmusic"), NULL, 0, NULL);//���ſ�ʼ����ı�������
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
	putimage(GAMEBUTTON_X, GAMEBUTTON_Y, &button_bmp, NOTSRCERASE);  //���ذ�ť����ʼ��Ϸ
	putimage(GAMEBUTTON_X, GAMEBUTTON_Y, &beginbutton, SRCINVERT);
	putimage(HANDLEBUTTON_X, HANDLEBUTTON_Y, &button_bmp, NOTSRCERASE);//���ذ�ť����Ϸ����
	putimage(HANDLEBUTTON_X, HANDLEBUTTON_Y, &handlebutton, SRCINVERT);
	putimage(EXITGAME_X, EXITGAME_Y, &button_bmp, NOTSRCERASE);        //���ذ�ť���˳���Ϸ
	putimage(EXITGAME_X, EXITGAME_Y, &exitgame, SRCINVERT);
}

int Start::ControlBegin()  //���ƿ�ʼ����ĺ���
{
	while (true)
	{
		if (MouseHit())   //�ж��Ƿ��������Ϣ
		{
			m = GetMouseMsg();  //���һ�������Ϣ
			if (m.uMsg == WM_LBUTTONDOWN ) //�ж��û��Ƿ��������
			{
				if (m.x >= GAMEBUTTON_X && m.x <= GAMEBUTTON_X + 150 && m.y >= GAMEBUTTON_Y && m.y <= GAMEBUTTON_Y + 75)
				{  
					//�ж����������ͬʱ����Ƿ��ڿ�ʼ��Ϸ��ť�ϣ���ť��150px,��75px��
					return 0;
				}
				if (m.x >= HANDLEBUTTON_X && m.x <= HANDLEBUTTON_X + 150 && m.y >= HANDLEBUTTON_Y && m.y <= HANDLEBUTTON_Y + 75)
				{
					//�ж����������ͬʱ����Ƿ�����Ϸ������ť�ϣ���ť��150px,��75px��
					return 1;
				}
				if (m.x >= EXITGAME_X && m.x <= EXITGAME_X + 150 && m.y >= EXITGAME_Y && m.y <= EXITGAME_Y + 75)
				{   
					//�ж����������ͬʱ����Ƿ����˳���Ϸ��ť�ϣ���ť��150px,��75px��
					return 2;
				}
			}

		}
	}
}
void Start::DrawSelect()  //����ѡ��ؿ�����
{
	mciSendString(_T("close bkmusic"), NULL, 0, NULL);      //�رճ�ʼ���汳������
	mciSendString(_T("open music/select.mp3  alias skmusic"), NULL, 0, NULL);//�����µı�������
	mciSendString(_T("play skmusic repeat"), NULL, 0, NULL); 
	putimage(0, 0, &gameselect);                       //����ѡ�����ı���ͼƬ
	putimage(BACKBEGIN_X, BACKBEGIN_Y, &backbegin_bmp, NOTSRCERASE);//���ط��ذ�ť
	putimage(BACKBEGIN_X, BACKBEGIN_Y, &backbegin, SRCINVERT);
	putimage(SELECTONE_X, SELECTONE_Y, &select_bmp, NOTSRCERASE);
	putimage(SELECTONE_X, SELECTONE_Y, &selectone,SRCINVERT);     //���عؿ�һ�İ�ť
	putimage(SELECTTWO_X, SELECTTWO_Y, &select_bmp, NOTSRCERASE);
	putimage(SELECTTWO_X, SELECTTWO_Y, &selecttwo, SRCINVERT);   //���عؿ����İ�ť
	putimage(SELECTTHREE_X, SELECTTHREE_Y, &select_bmp, NOTSRCERASE);
	putimage(SELECTTHREE_X, SELECTTHREE_Y, &selectthree, SRCINVERT);//���عؿ����İ�ť
}
int Start::ControlSelect()  //����ѡ��ؿ�����ĺ���
{   
	while (true)
	{
		if (MouseHit())   //�ж��Ƿ��������Ϣ
		{  
			n = GetMouseMsg();//�õ�һ�������Ϣ
			if (n.uMsg == WM_LBUTTONDOWN)//�ж��û��Ƿ��������
			{   
				
				if (n.x >= SELECTONE_X && n.x <= SELECTONE_X+75 && n.y >= SELECTONE_Y&& n.y <= SELECTONE_Y+75)
				{    
					//�رձ������֣��ж��Ƿ�ѡ��ؿ�һ
					mciSendString(_T("close skmusic"), NULL, 0, NULL);
					return 1;
				}
				if (n.x >= SELECTTWO_X && n.x <= SELECTTWO_X+75 && n.y >= SELECTTWO_Y && n.y <= SELECTTWO_Y+75)
				{   //�رձ������֣��ж��Ƿ�ѡ��ؿ���
					mciSendString(_T("close skmusic"), NULL, 0, NULL);
					return 2;
				}
				if (n.x >= SELECTTHREE_X && n.x <= SELECTTHREE_X +75&& n.y >= SELECTTHREE_Y && n.y <= SELECTTHREE_Y+75)
				{   //�رձ������֣��ж��Ƿ�ѡ��ؿ���
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
void Start::DrawHandle()   //������Ϸ�������ܽ���
{
	putimage(0, 0, &handleui_bmp, NOTSRCERASE);//���ؽ��ܵĽ���
	putimage(0, 0, &handleui, SRCINVERT);
	putimage(BACK_X, BACK_Y, &back);
}
int Start::ControlHandle()   //������Ϸ��������ĺ���
{
	while (true)
	{
		if (MouseHit())  //�ж��Ƿ��������Ϣ
		{
			c = GetMouseMsg();//�õ�һ�������Ϣ
			if (c.uMsg == WM_LBUTTONDOWN)
			{
				if (c.x >= BACK_X && c.x <= BACK_X + 30 && c.y >= BACK_Y && c.y <= BACK_Y +30)
				{   
					//�ж����������ͬʱ����Ƿ��ڷ��ذ�ť�ϣ���ť��30px,��30px��
					return  0;
				}
			}
		}
	}
}

