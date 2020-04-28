#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int num[100];
int dp[100];
int main(int argc, char** argv) {
	int n;
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	for(i=0;i<n;i++)
	{
		dp[i]=1;
		for(j=0;j<i;j++)
		{
			if(num[j]>=num[i]&&dp[j]+1>dp[i])
			{
				dp[i]=dp[j]+1;
			}
		}
	}
	int max=0;
	int ans=0;
	for(i=0;i<n;i++)
	{
		if(dp[i]>max)
		{
			max=dp[i];
		}
	}
	printf("%d",max);
	return 0;
}
