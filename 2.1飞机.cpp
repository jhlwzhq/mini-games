#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int limx=70,limy=20;  //�߽�
int posx=limx/2,posy=limy-2;   //�ɻ� 
int bulx,buly,fire=0;  //�ӵ� 
int v=0,vv;  //��Ϸ�ٶ� 
int by=1,vb=1,kill=0,bx=rand()%(67)+2;  //���� 
int s=0;  //�Ʒ�
int pause=1;  //��ͣ 
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
	printf("��Ϸ˵����w,s,a,d,�ֱ��ƶ��ɻ���������\n�ո����ӵ���Esc��ʼ����ͣ��Ϸ");
	while(pause) 
	{
		if(kbhit)
		{
			input=getch();
			if(input==27) pause=0;
		}	
	}
}
void show()
{
	gotoxy(0,0); //����	
	for(int i=1;i<=limy;i++)   //i������
	{
		for(int j=1;j<limx;j++)  //j������
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
			else if((bulx==j)&&(buly==i)&&(fire==1)) printf("|");
			else if((bx==j)&&(by==i))  printf("@");
			else printf(" ");
		}
		printf("\n");
		
	} 
	printf("�÷֣�%d",s);               //����ɻ����ӵ� 
	
}
void updatewithinput()
{
		if (kbhit())       //�жϲ��� 
		{
			input=getch();
			if(input==27) pause=1;
			if((input=='w')&&(posy>1)) posy--;
			if((input=='s')&&(posy<limy-2)) posy++;
			if((input=='a')&&(posx>3)) posx--;
			if((input=='d')&&(posx<limx-3)) posx++;
			if(input==' ') 
			{
				bulx=posx;
				buly=posy-1;
				fire=1;
			}
		}
		if(buly==0) fire=0;
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
	buly--;
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
	
	if((bx==bulx)&&(buly==by)) 
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
		GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
		CursorInfo.bVisible = false; //���ؿ���̨���
		SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬

		show();
		updatewithoutinput();
		updatewithinput();
	} 
	return 0;
} 




//9/44
