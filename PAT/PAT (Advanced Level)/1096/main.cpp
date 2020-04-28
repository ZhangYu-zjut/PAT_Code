#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//寻找连续的因子
//直接暴力可以解决,不要想复杂！！！ 
int main(int argc, char** argv) {
	int n;
	int i,j,k;
	scanf("%d",&n); 
	int sqr=(int)sqrt(n);
	long long temp=1,len=0,lens=-1;
	for(i=2;i<=sqr;i++)
	{
		temp=1;
		for(j=i;j<=sqr;j++)
		{
			temp*=j;
			if(n%temp!=0)break;
			else
			{
				if(j-i+1>len)
				{
					lens=i;
					len=j-i+1;
				}
			}
		}
	}
	if(len==0)
	{
		printf("%d\n%d",1,n);
		return 0;
	}
	else
	{
		printf("%lld\n",len);
		for(i=lens;i<len+lens;i++)
		{
			if(i==lens)printf("%d",i);
			else printf("*%d",i);
		}
	}

	return 0;
}
