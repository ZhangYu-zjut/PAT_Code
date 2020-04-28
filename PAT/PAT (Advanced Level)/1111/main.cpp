#include <iostream>
#include <stdio.h>
#include <string>
#include <vector> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//为什么还是有两个测试点没过？。 
const int INF=1000006;
const int MAXV=501;
int n,m,st,ed;
int G[MAXV][MAXV],d[MAXV];
bool vis[MAXV]={false};
bool vis2[MAXV]={false};
int cost[MAXV][MAXV],c[MAXV];

vector<int>pre[MAXV];
vector<int>pre2[MAXV];
vector<int>path,tempPath;
vector<int>path1,path2;
int min_node=INF;
int min_node2=INF;
string a;
string b;
void Dijkstra(int s)
{
	fill(d,d+MAXV,INF);
	fill(c,c+MAXV,INF); 
	d[s]=0;
	c[s]=0;
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
			if(vis[v]==false&&G[u][v]!=INF)
			{
				if(G[u][v]+d[u]<d[v])
				{
					d[v]=G[u][v]+d[u];
					c[v]=cost[u][v]+c[u];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(G[u][v]+d[u]==d[v])
				{
					if(c[v]>cost[u][v]+c[u])
					{
						c[v]=cost[u][v]+c[u];
						pre[v].push_back(u);
					}
				}
			}
		}
	}
}

void Dijkstra2(int s)
{
	fill(d,d+MAXV,INF);
	fill(c,c+MAXV,INF); 
	d[s]=0;
	c[s]=0;
	int i,j,k;
	for(i=0;i<n;i++)
	{
		int u=-1,MIN=INF;
		for(j=0;j<n;j++)
		{
			if(vis2[j]==false&&c[j]<MIN)
			{
				u=j;
				MIN=c[j]; 
			} 
		}
		if(u==-1)return;
		vis2[u]=true;
		for(int v=0;v<n;v++)
		{
			if(vis2[v]==false&&cost[u][v]!=INF)
			{
				if(cost[u][v]+c[u]<c[v])
				{
					d[v]=G[u][v]+d[u];
					c[v]=cost[u][v]+c[u];
					pre2[v].push_back(u);
				}
				else if(cost[u][v]+c[u]==c[v])
				{
					if(G[u][v]+d[u]<d[v])
					{
						d[v]=G[u][v]+d[u];
						pre2[v].push_back(u);
					}
				}
			}
		}
	}
}

void DFS_new(int s,vector<int> &path,int judge)
{
	if(judge==0)
	{
		if(s==st)
		{
			tempPath.push_back(s);
			int num_node=tempPath.size();
			if(num_node<min_node)
			{
				min_node=num_node;
				path = tempPath;
			}
			tempPath.pop_back();
			return;
		}
		tempPath.push_back(s);
		for(int j=0;j<pre[s].size();j++)
		{
			DFS_new(pre[s][j],path,judge);
		}
		tempPath.pop_back();
	}
	else
	{
		if(s==st)
		{
			tempPath.push_back(s);
			int num_node=tempPath.size();
			if(num_node<min_node2)
			{
				min_node2=num_node;
				path = tempPath;
			}
			tempPath.pop_back();
			return;
		}
		tempPath.push_back(s);
		for(int j=0;j<pre2[s].size();j++)
		{
			DFS_new(pre2[s][j],path,judge);
		}
		tempPath.pop_back();
	}
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	int u,v,one_way,w,time;
	int i,j,k;
	fill(G[0],G[0]+MAXV*MAXV,INF);
	fill(cost[0],cost[0]+MAXV*MAXV,INF);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d%d%d",&u,&v,&one_way,&w,&time);
		if(one_way==1)
		{
			G[u][v]=w;
			cost[u][v]=time;
		}
		else
		{
			G[u][v]=w;
			G[v][u]=w;
			cost[u][v]=time;
			cost[v][u]=time;
		}
	}
	scanf("%d%d",&st,&ed);

	Dijkstra(st);
	DFS_new(ed,path1,0);
	int min_dis=d[ed];//要将第一次Dijkstra下的最短距离保存一下！！！ 

	Dijkstra2(st);
	DFS_new(ed,path2,1);

	if(path2==path1)
	{
		printf("Distance = %d; Time = %d: ",min_dis,c[ed]);
		for(i=path1.size()-1;i>=0;i--)
		{
			if(i==0)printf("%d",path1[i]);
			else printf("%d -> ",path1[i]);
		}
	}
	else
	{
		printf("Distance = %d: ",min_dis);
		for(i=path1.size()-1;i>=0;i--)
		{
			if(i==0)printf("%d",path1[i]);
			else printf("%d -> ",path1[i]);
		}
		printf("\nTime = %d: ",c[ed]);
		for(i=path2.size()-1;i>=0;i--)
		{
			if(i==0)printf("%d",path2[i]);
			else printf("%d -> ",path2[i]);
		}
	}
	return 0;
}
