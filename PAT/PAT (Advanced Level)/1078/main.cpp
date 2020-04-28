#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//注意当x=1不是素数的情况，hash的模拟，不难，Quadratic probing为二次探查法。AC!! 
bool hashtable[10004];
int num[10004];
bool isprime(int x)
{
	if(x==1)return false;//特殊情况！！！！ 
	int temp=sqrt(1.0*x);
	for(int i=2;i<=temp;i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
int main(int argc, char** argv) {
	int m,n;
	int i,j,k;
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	int length;
	while(!isprime(m))
	{
		m++;
	}
	for(i=0;i<n;i++)
	{
		bool find=false;
		int ans=0;
		for(j=0;j<=m;j++)
		{
			if(hashtable[(num[i]+j*j)%m]==false)
			{
				hashtable[(num[i]+j*j)%m]=true;
				find=true;
				ans=(num[i]+j*j)%m;
				break;//注意找到了以后要马上跳出循环！！！ 
			}
		}
		if(find)
		{
			if(i==0)printf("%d",ans);
			else printf(" %d",ans);
		}
		else
		{
			printf(" -");
		}
	}
	return 0;
}
