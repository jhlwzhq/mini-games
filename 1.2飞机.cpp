#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
	int x=50,y=20,fire=0,kill=0,bx=1,vb=1,s=0,v,vv;
	char input;
	printf("��Ϸ˵����w,s,a,d,�ֱ𽫷ɻ����ϣ��£������ƶ����ո��伤��\n��ѡ����Ϸ�Ѷȣ�1~9��:");
	scanf("%d",&v); 
	while(1)
	{
		system("cls");  //���� 
		
		if(kill==0)
		{
			for(int i=1;i<bx;i++) printf(" ");
			printf("*\n");                                //������� 
		}
		else kill=0;
		
		if(fire==0)
		{
			for(int i=1;i<y;i++) printf("\n");  //ȷ���ɻ�λ�� 
		}
		else                                   //�����ӵ� 
		{
			for(int j=1;j<y;j++)
			{
				for(int i=1;i<x;i++) printf(" ");
				printf("|\n");
			}
			fire=0;
			if(bx==x) 
			{
				kill=1;
				s++;
			}
		}
		for(int i=1;i<x;i++) printf(" ");
		printf("*\n");                        //����ɻ� 
		for(int i=1;i<x-2;i++) printf(" ");
		printf("*****\n");
		for(int i=1;i<x-1;i++) printf(" ");
		printf("* *\n");
		printf("score:%d",s);
		
		if (kbhit())       //�жϲ��� 
		{
			input=getch();
			if(input=='w') y=y-1;
			if(input=='s') y=y+1;
			if(input=='a') x=x-1;
			if(input=='d') x=x+1;
			if(input==' ') fire=1;
		}
		if(bx==100||bx==0) vb=-vb;
		bx=bx+vb;
		vv=(10-v)*10000000;
		for(int i=0;i<vv;i++) ;
	}
	return 0;
} 
