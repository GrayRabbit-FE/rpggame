#include <graphics.h>
#include <conio.h>
#include "player.h"
#include "Start.h"
#include "engine.h"
#include <easyx.h>
int main()
{
        Start mystart;//创建一个Start对象
        Player player;
        Manager manager;
        IMAGE failed, succeed;
        enum stateofstart{Failed,Successed,Return};
        int i,j=0;
        stateofstart a=Return;
        loadimage(&failed, _T("image\\fild.png"));
        loadimage(&succeed, _T("image\\succeed.png"));
        //i用作记录ControlBegin()的返回值，0代表用户选择了开始游戏按钮，1表示选择了游戏操作按钮，2表示选择了退出游戏按钮
        //j用作记录ControlSelect()的返回值，1代表关卡1，2代表关卡2.3代表关卡3
        mystart.InitBegin();//初始化
        while (1)
        {
            while (j==0) // 此循环用于实现返回按钮的功能
            {
                if (a == Return)
                {
                    mystart.DrawBegin();
                    i = mystart.ControlBegin();
                }
                switch (i)
                {
                    case 0:mystart.DrawSelect();
                          j = mystart.ControlSelect();
                          if (j ==0)
                          {
                              a = Return;
                          }
                          break;
                    case 1:mystart.DrawHandle();
                           mystart.ControlHandle();
                           break;
                    case 2:return 0;
                }
            }
            cleardevice();
            switch (j)
            {
            case 1:manager.level1(player);
                if (player.health <= 0)
                {
                    a = Failed;
                    putimage(0, 0, &failed);
                    Sleep(1500);
                }
                else
                {
                    a = Successed;
                    putimage(0, 0, &succeed);
                    Sleep(1500);
                }
                j = 0;
                player.health = 18 + player.level * 2;
                player.x_local = 20, player.x_gobal = 20;
                break;
            case 2:manager.level2(player);
                if (player.health <= 0)
                {
                    a = Failed;
                    putimage(0, 0, &failed);
                    Sleep(1500);
                }
                else
                {
                    a = Successed;
                    putimage(0, 0, &succeed);
                    Sleep(1500);
                }
                j = 0;
                player.health = 18 + player.level * 2;
                player.x_local = 20, player.x_gobal = 20;
                break;
            case 3:manager.level3(player);
                if (player.health <= 0)
                {
                    a = Failed;
                    putimage(0, 0, &failed);
                    Sleep(1500);

                }
                else
                {
                    a = Successed;
                    putimage(0, 0, &succeed);
                    Sleep(1500);
                }
                j = 0;
                player.health = 18 + player.level * 2;
                player.x_local = 20, player.x_gobal = 20;
                break;
            default:
                break;
            }
        }

        _getch();
        closegraph();
        return 0;
}

