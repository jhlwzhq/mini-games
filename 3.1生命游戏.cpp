#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#include<windows.h>
#define height 20
#define width 40
int a[height][width]={0};
int temp[height][width]={0};
int n=0;
char input;
int pause=1;
int time=500;
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
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			a[i][j]=rand()%2;  //1live,2death
		}
	}
}
void show()
{
	gotoxy(0,0);
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(a[i][j]==1) printf("*");
			  else printf(" ");
		}
		printf("\n");
	}
}
void updatewithinput()
{
	if(kbhit())
	{
		input=getch();
		if(input==27) pause=1;
		if(input=='r') startup();
		if(input=='+') time=time/2;
		if(input=='-') time=time*2;
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
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			temp[i][j]=a[i][j];
		}
	}
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if((i+1<height-1)&&(temp[i+1][j]==1)) n++;
			if((i-1>0)&&(temp[i-1][j]==1)) n++;
			if((j+1<width-1)&&(temp[i][j+1]==1)) n++;
			if((j-1>0)&&(temp[i][j-1]==1)) n++;
			if((i+1<height-1)&&(j+1<width-1)&&(temp[i+1][j+1]==1)) n++;
			if((i+1<height-1)&&(j-1>0)&&(temp[i+1][j-1]==1)) n++;
			if((i-1>0)&&(j+1<width-1)&&(temp[i-1][j+1]==1)) n++;
			if((i-1>0)&&(j-1>0)&&(temp[i-1][j-1]==1)) n++;
			
			if(n==3) a[i][j]=1;
			 else if(n==2) a[i][j]=temp[i][j];
			   else a[i][j]=2;
			n=0;
		}
	}
}
int main()
{
	printf("ESC暂停或开始，r重新开始，+或-改变速度");
	while(pause) 
	{
		if(kbhit)
		{
			input=getch();
			if(input==27) pause=0;
		}	
	}
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
		Sleep(time);
	}
	return 0;
}
