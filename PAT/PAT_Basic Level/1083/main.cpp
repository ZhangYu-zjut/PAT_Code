#include <iostream>
#include <stdio.h>
#define N 10005
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PAT_B1083 是否存在相等的差 （20 分）AC!!!!
int num[N];
int count[N];

int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<=n;i++)
	{
		count[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		if(num[i]-i<0)
		{
			count[-(num[i]-i)]++;
		}
		else
		{
			count[(num[i]-i)]++;
		}
	}
	for(i=n;i>=0;i--)
	{

		if(count[i]>1)
		{
			printf("%d %d\n",i,count[i]);
		}
	}
	return 0;
}
