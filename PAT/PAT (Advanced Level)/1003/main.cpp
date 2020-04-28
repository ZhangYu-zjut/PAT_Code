#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//最短路径算法，加上一些其他条件，要熟练掌握，能够独立写代码
//AC!!!! 
const int INF=1000000;
const int MAXV=500;
int n,m,s,e;
int G[MAXV][MAXV],d[MAXV];
bool vis[MAXV]={false};

int weight[MAXV],w[MAXV];//新增加的部分 
int num[MAXV];//最短路径的条数 
void Dijkstra(int s)
{
	fill(d,d+MAXV,INF);
	fill(num,num+MAXV,0);
	fill(w,w+MAXV,0);
	d[s]=0;
	num[s]=1;
	w[s]=weight[s];
	int i,j,k;
	for(i=0;i<n;i++)
	{
		int u=-1,MIN=INF;
		for(j=0;j<n;j++)
		{
			if(vis[j]==false&&d[j]<MIN)
			{
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1)return;
		vis[u]=true;
		for(int v=0;v<n;v++)
		{
			if(vis[v]==false&&G[u][v]!=EOF)
			{
				if(G[u][v]+d[u]<d[v])
				{
					d[v]=G[u][v]+d[u];
					num[v]=num[u];
					w[v]=weight[v]+w[u];
				}
				else if(G[u][v]+d[u]==d[v])
				{
					num[v]+=num[u];
					if(weight[v]+w[u]>w[v])
					{
						w[v]=weight[v]+w[u];
					}
				}
			}
		}
	}
} 
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int i,j,k;
	int a,b,c;
	fill(G[0],G[0]+MAXV*MAXV,INF);
	scanf("%d%d%d%d",&n,&m,&s,&e);
	for(i=0;i<n;i++)
	{
		scanf("%d",&weight[i]);
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		G[a][b]=c;
		G[b][a]=c;
	}
	Dijkstra(s);
	printf("%d %d",num[e],w[e]);
	return 0;
}
