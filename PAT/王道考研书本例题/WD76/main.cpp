#include <iostream>
#include <stdio.h> 
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//1.judge whether a number is prime
//2.利用素数筛选法输出小于n的，个位为1的素数 
bool judge(int n)
{
	if(n<=1)
	{
		return false;
	}
	int i;
	int bound = (int)sqrt(n)+1;
	for(i=2;i<bound;i++)
	{
		if(n%i==0)
		{
			return false; 
		} 
	}
	return true;
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n;
	int i,j;
	bool flag[10010];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)//初始化 
		{
			flag[i]=true;
		}
		for(i=2;i<n;i++)
		{
			if(flag[i]==true)
			{
				if(judge(i)==true)
				{
					flag[i]==true;//确实是素数 
					for(j=2;j<n;j++)//标记该素数整数倍的数为非素数 
					{
						if(i*j<n)
						{
							flag[i*j]=false;
						}						
					}
				}
				else
				{
					flag[i]==false;
				}
			}
		}
		bool zero=true;//判定是否存在这样的数 
		for(i=2;i<n;i++)
		{
			if(i%10==1 && flag[i]==true)
			{
				zero = false;
				printf("%d ",i);
			} 
		} 
		
		if(zero==true)
		{
			printf("-1");
		} 
		printf("\n");
		/*
		if(judge(n)==true)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
		*/
		
	}
	return 0;
}
