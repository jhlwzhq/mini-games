#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int ballx=1,bally=1;  //С��
int posx=10,posy=24,length=30;  //ƽ��
int blockx,blocky=1;  //���� 
int height=25,width=50;  //�߿� 
int pause=1;  //��ͣ 
int vx=1,vy=1;  //С���� 
int num=0,score=0; //�÷� 
int speed=1,v=3; //�ٶ� 
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
	printf("��Ϸ˵����a,d,�����ƶ�ƽ�巴��С��\n���з���@�ɵ�һ��\nEsc��ʼ����ͣ��Ϸ"); 
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
	gotoxy(0,0); //����	
	for(int i=1;i<=height;i++)  //i������ 
	{
		for(int j=1;j<=width;j++)  //j������ 
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
	printf("����С������%d\n",num);
	printf("���𷽿�����%d",score);	
}
void updatewithoutinput()
{ 
	ballx=ballx+vx;
	bally=bally+vy;   //С������
	
	if(bally==1) vy=-vy;
	if((ballx==1)||(ballx==width-1)) vx=-vx;   //������ײ 
	
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
	 }                      //С����� 
	
	if((ballx==blockx)&&(bally==blocky)) 
	{
		score++;
		blockx=rand()%50;
		if(length>1) length--; 
	}                                           //���е÷� 
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
		GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
		CursorInfo.bVisible = false; //���ؿ���̨���
		SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬
		
		show();
		updatewithinput();
		updatewithoutinput();
	}
	return 0;
}
