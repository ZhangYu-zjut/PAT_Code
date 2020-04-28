#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int str[1010];
bool isprime(int x)
{
	if(x==1)return false;
	int temp=sqrt(1.0*x);
	for(int i=2;i<=temp;i++)
	{
		if(x%i==0)return false;	
	} 
	return true;
} 
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n,d;
	while(scanf("%d%d",&n,&d)!=EOF&&(n>0))
	{
		int i=0,j,sum=0;
		if(n==1)printf("No\n");
		else
		{
			while(n>0)
			{
				str[i++]=n%d;
				n/=d;
			}
			for(j=0;j<i;j++)
			{
				sum=sum*d+(str[j]);
			}
			if(isprime(sum)&&isprime(n))printf("Yes\n");
			else printf("No\n");
			}	
	}
	return 0;
}
