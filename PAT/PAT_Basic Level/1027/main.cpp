#include <iostream>
#include <stdio.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int N;
	char c;
	scanf("%d %c",&N,&c);
	int i,j,n;
	for(i=1;i<25;i++)//首先找出满足要求的n 
	{
		if(2*i*i-1<=N&&N<2*(i+1)*(i+1)-1)
		{
			n=i;
		}
	}
	for(i=0;i<n;i++)//打印漏斗的上部 
	{
		for(j=0;j<i;j++)//打印空格 
		{
			printf(" ");
		}
		for(j=0;j<2*n-1-2*i;j++)//打印符号 
		{
			printf("%c",c);
		}
		printf("\n");
	}
	for(i=n-2;i>=0;i--)//打印漏斗的下部 
	{
		for(j=0;j<i;j++)
		{
			printf(" ");
		}
		for(j=0;j<2*n-1-2*i;j++)
		{
			printf("%c",c);
		}
		printf("\n");
	}
	int left=N-(2*n*n-1);
	
	left==0?printf("0"):printf("%d",left);
	return 0;
}
