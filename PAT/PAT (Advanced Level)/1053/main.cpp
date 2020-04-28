#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//DFS思想遍历整棵树，注意路径保存以及DFS函数的书写，值得多多思考，训练！！
//AC!!!
struct node
{
	int weight;
	vector<int>child;
}N[300];
int path[300];
int num[300];
int numnode=0;
int sum,k;
bool cmp(int a,int b)
{
	return N[a].weight>N[b].weight;
}
void DFS(int now,int numnode,int sum)
{
	if(sum>k)return;
	if(sum==k)
	{
		if(N[now].child.size()!=0)return;
		for(int i=0;i<numnode;i++)
		{
			if(i==0)printf("%d",N[path[i]].weight);
			else printf(" %d",N[path[i]].weight);
		}
		printf("\n");
		return;//输出完之后返回上一层，继续遍历。 
	}
	for(int i=0;i<N[now].child.size();i++)
	{
		int child=N[now].child[i];
		path[numnode]=child;//这句话不能少！！！ 
		DFS(child,numnode+1,sum+N[child].weight);
	}
}
int main(int argc, char** argv) {
	int i,j,n,m,temp,t,child;
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&N[i].weight);
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&temp,&t);
		for(j=0;j<t;j++)
		{
			scanf("%d",&child);
			N[temp].child.push_back(child);
		}
		sort(N[temp].child.begin(),N[temp].child.end(),cmp);
	}
	path[0]=0;
	DFS(0,1,N[0].weight);
	
	return 0;
}
