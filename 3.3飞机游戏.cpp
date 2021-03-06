#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int canvas[21][71]={0}; //2子弹，1敌机 
int limx=70,limy=20;  //边界
int posx=limx/2,posy=limy-2;   //飞机
int v=0,vv;  //游戏速度 
int by=1,vb=1,kill=0,bx=rand()%(67)+2;  //敌机 
int s=0;  //计分
int pause=1;  //暂停 
char input;
void gotoxy(int x,int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X =x;
	pos.Y =y;
	SetConsoleCursorPosition(handle,pos);
}
void startup()
{
	printf("游戏说明：w,s,a,d,分别移动飞机上下左右\n空格发射子弹，Esc开始或暂停游戏");
	while(pause) 
	{
		if(kbhit)
		{
			input=getch();
			if(input==27) pause=0;
		}	
	} 
	canvas[by][bx]=1;
}
void show()
{
	gotoxy(0,0); //清屏	
	for(int i=1;i<=limy;i++)   //i纵坐标
	{
		for(int j=1;j<=limx;j++)  //j横坐标
		{
			if((posx==j)&&(posy==i)) 
			{
				printf("*");
			}
			else if((i==posy+1)&&(j==posx-2)) 
			{
				printf("*****");
				j=posx+2;
			}
			else if((i==posy+2)&&(j==posx-1)) 
			{
				printf("* *");
				j=posx+1;
			}
			else if(canvas[i][j]==2) printf("|");
			else if(canvas[i][j]==1)  printf("@");
			else printf(" ");
		}
		printf("\n");
		
	} 
	printf("得分：%d",s);               //输出飞机及子弹 
	
}
void updatewithinput()
{
		if (kbhit())       //判断操作 
		{
			input=getch();
			if(input==27) pause=1;
			if((input=='w')&&(posy>1)) posy--;
			if((input=='s')&&(posy<limy-2)) posy++;
			if((input=='a')&&(posx>3)) posx--;
			if((input=='d')&&(posx<limx-3)) posx++;
			if(input==' ') 
			{
				canvas[posy-1][posx]=2;
			}
		}
		while(pause)
		{
			if(kbhit())
			{
				input=getch();
				if(input==27) pause=0;
			}
		}
}
void updatewithoutinput()
{
	for(int i=1;i<=limx;i++)
	{
		for(int j=1;j<=limy;j++)
		{
			if(canvas[i][j]==2) 
			{
				canvas[i][j]=0;
				canvas[i-1][j]=2;
			}
		} 
	}
	v++;
	if(s<200) vv=20-s/10;
	 else vv=1;
	if(v==vv)
	{
		by++;
		if(by==limy-3) 
		{
			bx=rand()%(67)+2;
			by=1;
		}
		v=0;
	}
	
	if(canvas[by][bx]==1) 
	{
		s++;
		bx=rand()%(67)+2;
		by=1;
	}
}
int main()
{
	startup();
	while(1)
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
		CursorInfo.bVisible = false; //隐藏控制台光标
		SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态

		show();
		updatewithoutinput();
		updatewithinput();
	} 
	return 0;
} 
