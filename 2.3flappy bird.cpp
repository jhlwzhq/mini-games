#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h> 
int birdx,birdy; //小鸟
int height,width;  //边框
int obstaclex,obstacley,length; //障碍 
int i,j,over=1;
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
	length=5; //障碍间隙长度
	height=25;
	width=100;
	birdx=5;
	birdy=3;
	obstaclex=width-1;
	obstacley=rand()%(height-length); 
}
void show()
{
	gotoxy(0,0);
	
	for(i=1;i<=height;i++)  //i纵坐标
	{
		for(j=1;j<=width;j++) //j横坐标
		{
			if(j==width) printf("|");
			else if(i==height) printf("-");
			else if((i==birdy)&&(j==birdx))  printf("@");
			else if((j==obstaclex)&&(i>=1)&&(i<obstacley)) printf("*");
			else if((j==obstaclex)&&(i>=obstacley+5)&&(i<height))  printf("*"); 
			else printf(" ");
		} 
		printf("\n");
	} 
}
void updatewithoutinput()
{
	if(birdx==obstaclex)
	{
		if((birdy>=obstacley)&&(birdy<obstacley+5)) 
		{
			obstaclex=width-1;
			obstacley=rand()%(height-length);
		}
		 else over=0;
	}
	if(birdy<height) birdy++;
	  else over=0;
	if(obstaclex>0) obstaclex--;
}
void updatewithinput()
{
	if(kbhit())
	{
		input=getch();
		if((input==' ')&&(birdy>3)) birdy=birdy-3 ; 
	}
}
int main()
{
	startup();
	while(over)
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
	Sleep(1000);
	system("cls");
	gotoxy(0,0);
	printf("game over\n");
	return 0;
}
