#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int ballx=1,bally=1;  //小球
int posx=10,posy=24,length=30;  //平板
int blockx,blocky=1;  //方块 
int height=25,width=50;  //边框 
int pause=1;  //暂停 
int vx=1,vy=1;  //小球方向 
int num=0,score=0; //得分 
int speed=1,v=3; //速度 
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
	printf("游戏说明：a,d,左右移动平板反弹小球\n击中方块@可得一分\nEsc开始或暂停游戏"); 
	while(pause) 
	{
		if(kbhit())
		{
			input=getch();
			if(input==27) pause=0;
		}	
	}
	blockx=rand()%50;
}
void show()
{
	gotoxy(0,0); //清屏	
	for(int i=1;i<=height;i++)  //i纵坐标 
	{
		for(int j=1;j<=width;j++)  //j横坐标 
		{
			if((i==bally)&&(j==ballx)) printf("o");
			else if((i==blocky)&&(j==blockx)) printf("@");
			else if(j==width) printf("|");
			else if(i==height) printf("-");
			else if((i==posy)&&(j==posx))
			{
				for(int k=1;k<=length;k++)
				{
					printf("*");
				}
				j=j+length-1;
			} 
			else printf(" ");
		}
		printf("\n");
	}
	printf("消耗小球数：%d\n",num);
	printf("消灭方块数：%d",score);	
}
void updatewithoutinput()
{ 
	ballx=ballx+vx;
	bally=bally+vy;   //小球下落
	
	if(bally==1) vy=-vy;
	if((ballx==1)||(ballx==width-1)) vx=-vx;   //左右碰撞 
	
	if(bally==posy-1)
	{
		if((ballx>=posx)&&(ballx<posx+length)&&(vy==1))
		{
			vy=-vy;
			printf("\a");
		}
	 	 else if(bally==height-1)
	 	 {
	 	 	ballx=1;
	 	 	bally=1;
	 	 	vx=1;
	 	 	vy=1;
	 	 	num++; 
	 	 }
	}
	 else if(bally==height-1) 
	 {
	 	ballx=1;
	 	bally=1;
	 	vx=1;
	 	vy=1;
		num++; 
	 }                      //小球变向 
	
	if((ballx==blockx)&&(bally==blocky)) 
	{
		score++;
		blockx=rand()%50;
		if(length>1) length--; 
	}                                           //击中得分 
}
void updatewithinput()
{
	if(kbhit())
	{
		input=getch();
		if(input==27) pause=1;
		if((input=='w')&&(posy>1)) posy--;
		if((input=='s')&&(posy<height-1)) posy++;
		if((input=='a')&&(posx>1)) posx--;
		if((input=='d')&&(posx<width-length)) posx++;
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
		updatewithinput();
		updatewithoutinput();
	}
	return 0;
}
