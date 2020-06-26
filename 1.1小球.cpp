#include<stdio.h>
#include<stdlib.h>
int main()
{
	int vx,vy,x=1,y=1,limx,limy;
	printf("请输入边界，如：40 15\n");
	scanf("%d %d",&limx,&limy);
	while(1)
	{
		system("cls");
		
		for(int i=0;i<limx+2;i++) printf("*");    //第一行边框 
		
		printf("\n");                                 
		for(int i=1;i<y;i++) 
		{
			printf("*");
			for(int k=1;k<=limx;k++) printf(" ");
			printf("*\n");
		}                                           //小球以上边框 
		
		printf("*");
		for(int i=2;i<x;i++)  printf(" ");     
		printf("o");
		for(int i=x+1;i<=limx+1;i++)  printf(" ");
		printf("*\n");								//小球同行边框及小球 
		
		for(int i=y+1;i<=limy;i++)
		{
			printf("*");
			for(int k=1;k<=limx;k++) printf(" ");
			printf("*\n");
		}											//小球以下边框
		
		for(int i=0;i<limx+2;i++) printf("*");    //最后一行边框  
		
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
		}								//边界判断 
		
		x=x+vx; 
		y=y+vy;							//下一个小球的位置 
		
		for(int j=0;j<10000000;j++) ;   //控制时间 
	}
	return 0;
}
