#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h> 
int birdx,birdy; //С��
int height,width;  //�߿�
int obstaclex,obstacley,length; //�ϰ� 
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
	length=5; //�ϰ���϶����
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
	
	for(i=1;i<=height;i++)  //i������
	{
		for(j=1;j<=width;j++) //j������
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
		GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
		CursorInfo.bVisible = false; //���ؿ���̨���
		SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬
		
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
