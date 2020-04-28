#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int dp[10004];
bool choice[10004][102];
bool flag[10004];
int w[10004];
bool cmp(int a,int b)
{
	return a>b;
}
int main(int argc, char** argv) {
	int n,m;
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&w[i]);
	}
	sort(w,w+n,cmp);
	for(i=0;i<n;i++)
	{
		for(int v=m;v>=w[i];v--)
		{
			if(dp[v]<=dp[v-w[i]]+w[i])
			{
				dp[v]=dp[v-w[i]]+w[i];
				choice[i][v]=true;
			}
			else
			{
				choice[i][v]=false;
			}
		}
	}
	if(dp[m]!=m)
	{
		printf("No Solution\n");
		return 0;
	}
	int t,num;
	k=n,t=m,num=0;
	while(k>=0)
	{
		if(choice[k][t]!=false)
		{
			flag[k]=true;
			t-=w[k];
			num++;
		}
		else
		{
			flag[k]=false;
		}
		k--;
	}
	for(i=n;i>=0;i--)
	{
		if(flag[i])
		{
			printf("%d",w[i]);
			num--;
			if(num>0)printf(" ");
		}
		
	}
	return 0;
}
