#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define height 27
#define width 80
int directionx=1; //��1,��-1
int directiony=0; //��1,��-1 
int length=5;//�ߵĳ��� 
int posx=20,posy=20;//��ͷλ�� 
int game=1;//��Ϸ��ʼ����� 
int fx,fy;
char input;
int canvas[height+1][width+1];
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
//�滮�߽� 
	for(int i=1;i<=height;i++)  canvas[i][width]=-1;
	for(int i=1;i<width;i++) canvas[height][i]=-1;
//��ʼ���ߵ�λ��	
	canvas[posy][posx]=1;
	for(int i=2;i<=5;i++)
	{
		canvas[posy][posx+1-i]=i;
	}
//��ʼ��ʳ��λ��
	fy=rand()%(height-1-2+1)+2;
	fx=rand()%(width-1-2+1)+2;	
}
void show()
{
	gotoxy(0,0);
//������� 
	for(int i=1;i<=height;i++)
	{
		for(int j=1;j<=width;j++)
		{
			if(canvas[i][j]==-1) printf("#");
			else if((i==fy)&&(j==fx)) printf("o");
			else if(canvas[i][j]==1) printf("@");
			else if(canvas[i][j]>1) printf("*");
			else printf(" ");
		}
		printf("\n");
	} 
}
void updatewithinput()
{
//�ж����� 
	if(kbhit())
	{
		input=getch();
		if((input=='w')&&(directiony!=1))
		{
			directiony=-1;
			directionx=0;
		}
		 else if((input=='s')&&(directiony!=-1))
		{
		 	directiony=1;
			directionx=0;
		}
		 else if((input=='a')&&(directionx!=1))
		{
		 	directionx=-1;
			directiony=0;
		}
		 else if((input=='d')&&(directionx!=-1))
		{
		 	directionx=1;
			directiony=0;
		}
	} 
}
void updatewithoutinput()
{
//�ߵ�λ�ø��� 
	if(directionx!=0) 
	{
		for(int i=1;i<=height;i++)
		{
			for(int j=1;j<width;j++)
			{
				if(canvas[i][j]==length) canvas[i][j]=0;
				if(canvas[i][j]>0) canvas[i][j]++;
			}
		}
		posx=posx+directionx;
		canvas[posy][posx]=1;
	}
	else if(directiony!=0) 
	{
		Sleep(50);
		for(int i=1;i<=height;i++)
		{
			for(int j=1;j<width;j++)
			{
				if(canvas[i][j]==length) canvas[i][j]=0;
				if(canvas[i][j]>0) canvas[i][j]++;
			}
		}
		posy=posy+directiony;
		canvas[posy][posx]=1;
	}
//��ʳ��
	if(canvas[fy][fx]==1) 
	{
		length++;
		fy=rand()%(height-1-2+1)+2;
		fx=rand()%(width-1-2+1)+2;
	} 
//��Ϸ�����ж� 
	if((posx==0)||(posx==width)||(posy==0)||(posy==height)) game=0;
}
int main()
{
	startup();
	while(game)
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
		CursorInfo.bVisible = false; //���ؿ���̨���
		SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬

		show();
		updatewithoutinput();
		updatewithinput();
	}
	system("cls");
	printf("��Ϸ����"); 
	return 0;
}
