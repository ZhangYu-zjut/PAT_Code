#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//图的DFS遍历，不难，注意联通时候边数=点数-1 
//AC!!!

int n,m;
const int maxn=1003;
const int inf=1000000;
int G[maxn][maxn];
int num[maxn][maxn];
bool vis[maxn];
int edge;
void DFS(int x)
{
	vis[x]=true;
	int i;
	for(i=1;i<=n;i++)
	{
		if(vis[i]==false&&G[x][i]!=inf)
		{
			edge++;
			DFS(i);
		}
	}
}
int main(int argc, char** argv) {
	int i,j,k;
	fill(G[0],G[0]+maxn*maxn,inf);
	fill(num[0],num[0]+maxn*maxn,inf);
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		G[a][b]=1;
		G[b][a]=1;
		num[a][b]=1;
		num[b][a]=1;
	}
	for(i=0;i<k;i++)
	{
		for(int t=1;t<=n;t++)
		{
			for(int g=1;g<=n;g++)
			{
				G[t][g]=num[t][g];
				G[g][t]=num[t][g];
			}
		}
		int miss;
		edge=0;
		fill(vis,vis+maxn,false);
		scanf("%d",&miss);
		for(j=1;j<=n;j++)
		{
			G[miss][j]=inf;
			G[j][miss]=inf;
		}
		for(j=1;j<=n;j++)
		{
			if(vis[j]==false&&j!=miss)
			{
				DFS(j);
			}
		}
		int ans=(n-2-edge);
		if(ans<=0)printf("0\n");
		else printf("%d\n",ans);
	}
	return 0;
}
