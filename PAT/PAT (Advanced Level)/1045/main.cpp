#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//本质上还是动态规划，只不过多加了一个映射！！AC!! 
int num2[100004];
int hashtable[10004];
int dp[100004];
int main(int argc, char** argv) {
	int n,temp,m,k;
	scanf("%d%d",&n,&k);
	int i,j;
	for(i=1;i<=10000;i++)
	{
		hashtable[i]=-1;
	}
	for(i=0;i<k;i++)
	{
		scanf("%d",&temp);
		hashtable[temp]=i;
	}
	scanf("%d",&m);
	int length=0;
	for(i=0;i<m;i++)
	{
		scanf("%d",&temp);
		if(hashtable[temp]>=0)
		{
			num2[length++]=hashtable[temp];
		}
	}

	int ans=-1;
	for(i=0;i<length;i++)
	{
		dp[i]=1;
		for(j=0;j<i;j++)
		{
			if(num2[i]>=num2[j]&&dp[i]<dp[j]+1)
			{
				dp[i]=dp[j]+1;
			}
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
