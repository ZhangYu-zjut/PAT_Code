#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�ڽӱ�洢��ʽ��DFS���� 
#define N 1000
vector<int>adj[N];
vis[N]={false};
int n;//nΪ������ 
void DFS(int u,int depth)
{
	int j;
	vis[u]=true;
	for(j=0;j<adj[u].size();j++)//������ö������ڵĶ��� 
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
	for(i=0;i<n;i++)//����ͼ�Ķ��㣬���ж���û�б����ʣ�����ʸö��� 
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
