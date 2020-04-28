#include <iostream>
#include <stdio.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct goods
{
	int cost;
	int value;
}G[200];
int max(int x,int y)
{
	return (x>y?x:y);	
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int t,m;
	int dp[110][1010];
	scanf("%d%d",&t,&m);
	int i,j,k;
	for(i=0;i<=m;i++)
	{
		dp[0][i]=0;
	}
	for(i=0;i<=m;i++)
	{
		scanf("%d%d",&G[i].cost,&G[i].value);
	}
	for(i=1;i<=m;i++)
	{
		for(j=t;j>=G[i].cost;j--)
		{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-G[i].cost]+G[i].value);
		}
		for(j=G[i].cost-1;j>=0;j--)
		{
			dp[i][j]=dp[i-1][j];
		}
	}
	printf("%d",dp[m][t]);
	return 0;
}
