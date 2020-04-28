#include <iostream>
#include <stdio.h>
#include <string>
#include <vector> 
#include <map>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//有一个测试点没过！！ 
const int INF=1000006;
const int MAXV=501;
int n,m,st,ed;
int G[MAXV][MAXV],d[MAXV];
bool vis[MAXV]={false};
bool vis2[MAXV]={false};
int cost[MAXV],c[MAXV];//这里的cost代表每个节点的开心值，要最大。 

vector<int>pre[MAXV];
vector<int>path,tempPath;
vector<int>path1;
int min_node=INF;
int id=0;
map<string,int>str2int;
map<int,string>int2str;
int num[MAXV];
int strtoint(string str)
{
	int i,j;
	if(str2int.find(str)!=str2int.end())
	{
		return str2int[str];
	}
	else
	{
		str2int[str]=id;
		int2str[id]=str;
		return id++;
	} 
}
void Dijkstra(int s)
{
	fill(d,d+MAXV,INF);
	fill(c,c+MAXV,0); 
	d[s]=0;
	c[s]=cost[s];
	num[s]=1;
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
					c[v]=cost[v]+c[u];
					pre[v].clear();
					pre[v].push_back(u);
					num[v]=num[u];	
				}
				else if(G[u][v]+d[u]==d[v])
				{
					if(cost[v]+c[u]>c[v])
					{
						c[v]=cost[v]+c[u];
						pre[v].push_back(u);
					}
					num[v]+=num[u];
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
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	string start;
	scanf("%d%d",&n,&m);
	cin>>start;
	st=strtoint(start);
	int u,v,one_way,w,time;
	int i,j,k;
	fill(G[0],G[0]+MAXV*MAXV,INF);
	fill(cost,cost+MAXV,0);
	for(i=0;i<n-1;i++)
	{
		int int_temp,hap;
		string str_temp;
		cin>>str_temp>>hap;
		int_temp=strtoint(str_temp);
		cost[int_temp]=hap;
	}
	string a,b;
	int id1,id2;
	int length;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		cin>>length;
		id1=strtoint(a);
		id2=strtoint(b);
		
		if(a=="ROM"){
			ed=id1;			
		}
		if(b=="ROM"){
			ed=id2;
		}
		G[id1][id2]=length;
		G[id2][id1]=length;
	}
	Dijkstra(st);
	DFS_new(ed,path1,0);
	printf("%d %d %d %d\n",num[ed],d[ed],c[ed],c[ed]/(min_node-1));
	for(i=path1.size()-1;i>=0;i--)
	{
			if(i==0)cout<<int2str[path1[i]];
			else cout<<int2str[path1[i]]<<"->";
	}
	return 0;
}
