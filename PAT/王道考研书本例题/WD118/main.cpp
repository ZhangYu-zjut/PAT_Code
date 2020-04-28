#include <iostream>
#include <stdio.h>
#define N 100
#define inf 100000
#define debug 0
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int i,j,k,n,m;
	int edge[N][N];
	int a,b,c;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0&&m!=0)
	{
		for(i=1;i<=n;i++)//对边值进行初始化 
		{
			for(j=1;j<=n;j++)
			{
				edge[i][j]=inf;
				edge[i][i]=0;
			}			
		}
	
		for(i=1;i<=m;i++)//对边值进行更新
		{
			scanf("%d%d%d",&a,&b,&c);
			edge[a][b]=c;
			edge[b][a]=c;
		}	 

		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(edge[i][k]==inf||edge[k][j]==inf)//新加入的节点到i或者j的距离为无穷大,对原来的距离不进行更新 
					{
						continue;
					}
					if(edge[i][j]==inf||edge[i][k]+edge[k][j]<edge[i][j])//加入的节点到i或者j的距离为有限、且新路径距离更短或者原距离无穷大,则对原来的距离进行更新 
					{
						edge[i][j]=edge[i][k]+edge[k][j];
					}
				}
			}
		}
		#if debug 
		for(i=1;i<=n;i++)//测试 
		{
			for(j=1;j<=n;j++)
			{
				printf("edge[%d][%d] is %d\n",i,j,edge[i][j]);
			}			
		}
		#endif
		printf("%d\n",edge[1][n]);
	}
	return 0;
}
