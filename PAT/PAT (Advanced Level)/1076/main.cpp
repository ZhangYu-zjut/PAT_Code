#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//图的遍历，用BFS和邻接矩阵完成
//注意两个问题：
//scanf的时候一定要加&，初始层的序号为0，而不是1！ 
//AC!!!
struct node
{
	int s;
	int layer;
}N[1003];
int max_layer;
int cnt;
bool inq[1003];
vector<node>adj[1003];
void BFS(int s)
{
	int i;
	node a;
	a.s=s;
	a.layer=0;
	queue<node>q;
	q.push(a);
	inq[s]=true;
	while(!q.empty())
	{
		node temp = q.front();
		q.pop();
		for(i=0;i<adj[temp.s].size();i++)
		{
			int new_layer=temp.layer+1;
			adj[temp.s][i].layer=new_layer;
			if(new_layer<=max_layer&&inq[adj[temp.s][i].s]==false)
			{
				cnt++;
				q.push(adj[temp.s][i]);
				inq[adj[temp.s][i].s]=true;
			}
		} 
	}
} 
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	int i,j,k,n,temp,m;
	
	scanf("%d%d",&n,&max_layer);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(j=0;j<k;j++)
		{
			node innode;
			scanf("%d",&temp);
			innode.s=i;
			adj[temp].push_back(innode);
		}
	}
	int st;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&st);
		cnt=0;
		fill(inq,inq+1003,false);
		BFS(st);
		printf("%d\n",cnt);
	}
	return 0;
}
