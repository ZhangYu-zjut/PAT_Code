#include <iostream>
#include <stdio.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int MAXV=520;
const int INF=1000006;
int n,m,st,ed;
int G[MAXV][MAXV],d[MAXV];
bool vis[MAXV]={false};
int cost[MAXV][MAXV];
int cap[MAXV],c[MAXV];
int pre[MAXV];
bool judge_max;
int point_num=0;
int cap_sum=0;
void Dijkstra(int s)
{
	fill(d,d+MAXV,INF);
	fill(c,c+MAXV,INF);
	d[s]=0;
	c[s]=0;
	int i,j;
	for(i=0;i<=n;i++)
	{
		int u=-1,MIN=INF;
		for(j=0;j<=n;j++)
		{
			if(vis[j]==false&&d[j]<MIN)
			{
				u=j;
				MIN=d[j];
			}	
		}
		if(u==-1)return;
		vis[u]=true;
		
		for(int v=0;v<=n;v++)
		{
			if(vis[v]==false&&G[u][v]!=INF)
			{
				if(d[u]+G[u][v]<d[v])
				{
					d[v]=d[u]+G[u][v];
					c[v]=c[u]+cap[v];
					pre[v]=u;
					//point_num++;
				} 
				else if(d[u]+G[u][v]==d[v])
				{
					if(judge_max==true)
					{
						if(c[u]+cap[v]>c[v])
						{
							c[v]=c[u]+cap[v];
							pre[v]=u;							
						}
					}
					else
					{
						if(c[u]+cap[v]<c[v])
						{
							c[v]=c[u]+cap[v];
							pre[v]=u;
						}
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
		printf("%d",s);
		return;
	}
	DFS(s,pre[v]);
	printf("->%d",v);
}
void DFS2(int s,int v)//计算点个数 
{
	if(s==v)
	{
		return;
	}
	DFS2(s,pre[v]);
	point_num++;
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int max_cap;
	int i,j,k;
	int u,v,t;
	fill(G[0],G[0]+MAXV*MAXV,INF);
	cin>>max_cap>>n>>ed>>m;
	for(i=1;i<=n;i++)cin>>cap[i];
	cap[0]=0;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>t;
		G[u][v]=t;
		G[v][u]=t;
	}
	if(cap[ed]==0)
	{
		judge_max=true;
	}
	else
	{
		judge_max=false;
	}
	Dijkstra(0);
	DFS2(0,ed);
	int left;
	if(judge_max==true)
	{
		left=point_num*0.5*max_cap-c[ed];
		cout<<left<<" ";
	}
	else
	{
		cout<<0<<" ";
	}
	DFS(0,ed);
	if(judge_max==true)
	{
		cout<<" "<<0;
	}
	else
	{
		left=c[ed]-point_num*0.5*max_cap;
		cout<<" "<<left;
	}
	return 0;
}
