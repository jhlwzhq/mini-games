#include<stdio.h>
#include<stdlib.h>
int main()
{
	int vx,vy,x=1,y=1,limx,limy;
	printf("������߽磬�磺40 15\n");
	scanf("%d %d",&limx,&limy);
	while(1)
	{
		system("cls");
		
		for(int i=0;i<limx+2;i++) printf("*");    //��һ�б߿� 
		
		printf("\n");                                 
		for(int i=1;i<y;i++) 
		{
			printf("*");
			for(int k=1;k<=limx;k++) printf(" ");
			printf("*\n");
		}                                           //С�����ϱ߿� 
		
		printf("*");
		for(int i=2;i<x;i++)  printf(" ");     
		printf("o");
		for(int i=x+1;i<=limx+1;i++)  printf(" ");
		printf("*\n");								//С��ͬ�б߿�С�� 
		
		for(int i=y+1;i<=limy;i++)
		{
			printf("*");
			for(int k=1;k<=limx;k++) printf(" ");
			printf("*\n");
		}											//С�����±߿�
		
		for(int i=0;i<limx+2;i++) printf("*");    //���һ�б߿�  
		
		if(x==limx) 
		{
			printf("\a");
			vx=-1;
		}
		if(x==1) 
		{
			printf("\a");
			vx=1;
		}
		if(y==limy) 
		{
			printf("\a");
			vy=-1;
		}
		if(y==1) 
		{
			printf("\a");
			vy=1;
		}								//�߽��ж� 
		
		x=x+vx; 
		y=y+vy;							//��һ��С���λ�� 
		
		for(int j=0;j<10000000;j++) ;   //����ʱ�� 
	}
	return 0;
}
