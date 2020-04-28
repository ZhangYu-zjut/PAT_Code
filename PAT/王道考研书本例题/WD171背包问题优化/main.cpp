#include <iostream>
#include <stdio.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//将原来的二维数组转化为一维数组 
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
	int t,m;//m为物品个数，t为总重量 
	int dp[1010];
	scanf("%d%d",&t,&m);
	int i,j,k;
	for(i=0;i<=t;i++)//将原来的m改为t 
	{
		dp[i]=0;
	}
	for(i=0;i<=m;i++)
	{
		scanf("%d%d",&G[i].cost,&G[i].value);
	}
	for(i=1;i<=m;i++)
	{
		for(j=t;j>=G[i].cost;j--)
		{
			dp[j]=max(dp[j],dp[j-G[i].cost]+G[i].value);
		}
		//删除了原来的代码 
	}
	printf("%d",dp[t]);
	return 0;
}
