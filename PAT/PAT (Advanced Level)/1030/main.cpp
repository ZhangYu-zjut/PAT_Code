#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int INF=1000000;
const int MAXV=600;
int n,m,st,ed;
int G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV]={false};
int cost[MAXV][MAXV];
int c[MAXV];
int pre[MAXV];
vector<int>path[MAXV];
vector<int>temp[MAXV];
void Dijkstra(int s)
{
	fill(c,c+MAXV,INF);
	fill(d,d+MAXV,INF);
	d[s]=0;
	c[s]=0;
	int i,j;
	for(i=0;i<n;i++)
	{
		pre[i]=i;
	}
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
			if(vis[v]==false&&G[u][v]!=INF)
			{
				if(d[u]+G[u][v]<d[v])
				{
					d[v]=d[u]+G[u][v];
					c[v]=c[u]+cost[u][v];
					pre[v]=u;
				}
				else if(d[u]+G[u][v]==d[v])
				{
					if(c[u]+cost[u][v]<c[v])
					{
						c[v]=c[u]+cost[u][v];
						pre[v]=u;
					}
				}
			}
		}
	}
	
}
void DFS(int s,int v)
{
	if(s==v)
	{
		printf("%d ",s);
		return;
	}
	DFS(s,pre[v]);
	printf("%d ",v);
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	cin>>n>>m>>st>>ed;
	int i,j,k;
	int u,v,w,cos;
	fill(G[0],G[0]+MAXV*MAXV,INF);//图的初始化 
	for(i=0;i<m;i++)
	{
		cin>>u>>v>>w>>cos;
		G[u][v]=w;
		G[v][u]=w;
		cost[u][v]=cos;
		cost[v][u]=cos;
	}
	Dijkstra(st);
	DFS(st,ed);
	cout<<"is\n";
	//cout<<;//输出最短路径 
	cout<<d[ed]<<" "<<c[ed];
	return 0;
}
