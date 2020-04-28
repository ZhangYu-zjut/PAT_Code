#include <iostream>
#include <stdio.h>

using namespace std;
const int MAXV=100;
const int INF=1000000;
int G[MAXV][MAXV],d[MAXV];
int pre[MAXV];
int n,m,s;//n�����㣬m���ߣ�sΪȨֵ 
bool vis[MAXV];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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
void Dijkstra(int s)
{
	fill(d,d+MAXV,INF);
	d[s]=0;
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
			if(vis[v]==false&&G[u][v]!=INF&&d[u]+G[u][v]<d[v])
			{
				d[v]=d[u]+G[u][v];
				pre[v]=u;
			}
		} 
	}
	
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int i,j,k;
	int a,b,c;
	//scanf("%d%d%d",&n,&m,&s);
	cin>>n>>m>>s;//n�����㣬m���� 
	fill(G[0],G[0]+MAXV*MAXV,INF);
	for(i=0;i<m;i++)
	{
		//scanf("%d%d%d",&a,&b,&c);
		cin>>a>>b>>c;
		G[a][b]=c;	
	}
	Dijkstra(s);
	for(i=0;i<n;i++)
	{
		printf("������ %d ����̾���Ϊ %d\n ",i,d[i]);
	} 
	printf("��ԭ��������ڵ�5�����·��Ϊ:\n");
	DFS(0,5);
	return 0;
}
