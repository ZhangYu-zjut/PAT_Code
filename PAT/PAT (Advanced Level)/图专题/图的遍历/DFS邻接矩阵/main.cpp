#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//����洢������֮�����Ϣ 
#define N 10000
#define inf 10000000
int edge[N][N];
int n;//nΪ������ 
bool vis[N]={false};
void DFS(int u,int depth)//����ĳһ�����㣬�����������ӵĵ� 
{
	vis[u]=true;
	//������ԷŶ��ڶ���u��һЩ���� 
	for(int j=0;j<n;j++)
	{
		if(vis[j]==false&&edge[u][j]!=inf)
		{
			DFS(j,depth+1);
		}
	}
}
void travelDFS()//����ͼ�����ж��㣬��û�з��ʹ�����Ըö�����з��� 
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
