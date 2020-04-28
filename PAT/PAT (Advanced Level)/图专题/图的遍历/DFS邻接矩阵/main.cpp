#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//矩阵存储两个点之间的信息 
#define N 10000
#define inf 10000000
int edge[N][N];
int n;//n为顶点数 
bool vis[N]={false};
void DFS(int u,int depth)//对于某一个顶点，遍历跟它连接的点 
{
	vis[u]=true;
	//这里可以放对于顶点u的一些操作 
	for(int j=0;j<n;j++)
	{
		if(vis[j]==false&&edge[u][j]!=inf)
		{
			DFS(j,depth+1);
		}
	}
}
void travelDFS()//对于图的所有顶点，若没有访问过，则对该顶点进行访问 
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(vis[i]==false)
		{
			DFS(i,1);
		} 
	}
}
int main(int argc, char** argv) {
	return 0;
}
