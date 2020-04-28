#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//邻接表存储方式的DFS遍历 
#define N 1000
vector<int>adj[N];
vis[N]={false};
int n;//n为顶点数 
void DFS(int u,int depth)
{
	int j;
	vis[u]=true;
	for(j=0;j<adj[u].size();j++)//访问与该顶点相邻的顶点 
	{
		int v=adj[u][j];
		if(vis[v]==false)
		{
			DFS(v,depth+1);
		}
	}

} 
void DFStravel()
{
	int i,j;
	for(i=0;i<n;i++)//遍历图的顶点，若有顶点没有被访问，则访问该顶点 
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
