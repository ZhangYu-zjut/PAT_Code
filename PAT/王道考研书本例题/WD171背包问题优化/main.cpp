#include <iostream>
#include <stdio.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//��ԭ���Ķ�ά����ת��Ϊһά���� 
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
	int t,m;//mΪ��Ʒ������tΪ������ 
	int dp[1010];
	scanf("%d%d",&t,&m);
	int i,j,k;
	for(i=0;i<=t;i++)//��ԭ����m��Ϊt 
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
		//ɾ����ԭ���Ĵ��� 
	}
	printf("%d",dp[t]);
	return 0;
}
