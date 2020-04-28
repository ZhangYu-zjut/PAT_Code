#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int num[100005];
int main(int argc, char** argv) {
	int n;
	long long p;
	int i,j,k;
	scanf("%d%d",&n,&p);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	int ans=1;
	for(i=0;i<n;i++)
	{
		int j=upper_bound(num+i+1,num+n,(long long)num[i]*p)-num;
		ans=max(ans,j-i);
	}
/*	i=0,j=n-1;
	int ans1=0,ans2=0;
	int i1,i2,j1,j2;
	while(i<j)
	{
		long long max=num[j];
		long long min=num[i];
		if(max>p*min)
		{
			i++;
		}
		if(max<=p*min)
		{
			i1=i;
			j1=j;
			ans1=(j1-i1+1);
			break;
		}
	}
	i=0,j=n-1;
	while(i<j)
	{
		int max=num[j];
		int min=num[i];
		if(max>p*min)
		{
			j--;
		}
		if(max<=p*min)
		{
			i2=i;
			j2=j;
			ans2=(j2-i2+1);
			break;
		}
	}*/
	printf("%lld",ans);
	return 0;
}
