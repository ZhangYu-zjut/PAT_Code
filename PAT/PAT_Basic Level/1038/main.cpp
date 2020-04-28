#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define N 100000
int score[N];
int search[N];
int num[101];
int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<101;i++)
	{
		num[i]=0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&score[i]);
		num[score[i]]++;
	}
	int k;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d",&search[i]);
	}
	for(j=0;j<k;j++)
	{
		if(j<k-1)
		{
			printf("%d ",num[search[j]]);
		}
		if(j==k-1)
		{
			printf("%d",num[search[j]]);
		}

	}
	return 0;
}
