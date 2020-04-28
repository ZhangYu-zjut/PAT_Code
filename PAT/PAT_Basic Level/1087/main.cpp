#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define N 10000
#define max_n 15000
int num[N+5000];
int main(int argc, char** argv) {
	int n,i,j;
	int count=0;
	scanf("%d",&n);
	for(i=0;i<max_n;i++)
	{
		num[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		int temp=i/2+i/3+i/5;
		//printf("temp is :%d\n",temp);
		num[temp]=1;
	}
	for(i=0;i<max_n;i++)
	{
		if(num[i]!=0)
		{
			count++;	
		}
	}
	printf("%d",count);
	return 0;
}
