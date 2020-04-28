#include <iostream>
#include <stdio.h>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//首先要判断一下这个图是否是连通图！！ 
//AC!!
using namespace std;
const int maxn=503;
const int inf=1000003;
int G[maxn][maxn];
int degree[maxn];
bool vis[maxn];
int odd=0;
int cnt=0,n;
void DFS(int x)
{
	int i;
	vis[x]=true;
	cnt++;
	for(i=1;i<=n;i++)
	{
		if(vis[i]==false&&G[x][i]!=inf)
		{
			DFS(i);
		}
	}
} 
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int m;
	int i,j,k,a,b,c;
	fill(vis,vis+maxn,0);
	fill(degree,degree+maxn,0);
	fill(G[0],G[0]+maxn*maxn,inf);
	scanf("%d%d",&n,&m); 
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		G[a][b]=1;
		G[b][a]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(G[i][j]!=inf)
			{
				degree[i]+=1;
			}
		}
		if(degree[i]%2!=0)
		{
			odd++;
		}
	}
	bool connect=true;
	for(i=1;i<=n;i++)
	{
		if(vis[i]==false)
		{
			DFS(i);
		}
		if(cnt!=n)
		{
			connect=false;
		}
	}
	
	for(i=1;i<=n;i++)
	{
		if(i==1)printf("%d",degree[i]);
		else printf(" %d",degree[i]);
	}
	printf("\n");
	if(connect==false)
	{
		printf("Non-Eulerian\n");
		return 0;
	}
	if(odd==0)printf("Eulerian\n");
	else if(odd==2)printf("Semi-Eulerian\n");
	else printf("Non-Eulerian\n");

	return 0;
}
