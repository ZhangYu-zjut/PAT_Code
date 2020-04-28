#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//跟PAT_A1002思路类似，不再阐述，AC!! 
double a[2000]={},b[2000]={},ans[3000]={};
int main(int argc, char** argv) {
	fill(a,a+2000,0.0);
	fill(b,b+2000,0.0);
	fill(ans,ans+3000,0.0);
	int n,m,i,j,k,temp;
	double coff;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%lf",&temp,&coff);
		a[temp]=coff;
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%lf",&temp,&coff);
		b[temp]=coff;
	}
	for(i=0;i<1100;i++)
	{
		for(j=0;j<1100;j++)
		{
			if(a[i]!=0&&b[j]!=0)
			{
				ans[i+j]+=a[i]*b[j];
			}
		} 
	}
	int count=0;
	for(i=0;i<3000;i++)
	{
		if(ans[i]!=0)count++;
	}
	printf("%d",count);
	for(i=2999;i>=0;i--)
	{
		if(ans[i]!=0)
		{
			printf(" %d %.1lf",i,ans[i]);
		}
	}
	return 0;
}
