#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//²ã´Î±éÀú£¬AC!! 
struct node
{
	int v;
	int layer;
	int length;
	vector<int>child;
}N[200];
int node_count[200]={0};
int max_layer;
void BFS(int root)
{
	int i,j;
	queue<node>q;
	N[root].layer=1;
	q.push(N[root]);
	node_count[N[root].layer]++;
	while(!q.empty())
	{
		node temp=q.front();
		q.pop();
		if(temp.length!=0)
		{
			for(i=0;i<temp.length;i++)
			{
				int next_layer=temp.layer+1;
				for(j=1;j<200;j++) 
				{
					if(N[j].v==temp.child[i])
					break;
				}
				N[j].layer=next_layer;
				node_count[next_layer]++;
				q.push(N[j]);
			}
		}
	}
}
int main(int argc, char** argv) {
	int n,m,temp;
	int i,j,k,root;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&N[i].v,&N[i].length);
		if(N[i].v==1)
		{
			root=i;
		}
		for(j=0;j<N[i].length;j++)
		{
			scanf("%d",&temp);
			N[i].child.push_back(temp);
		}
	} 
	BFS(root);
	int max_num=0;
	for(i=1;i<200;i++)
	{
		if(node_count[i]>max_num)
		{
			max_num=node_count[i];
			max_layer=i;
		}
	}
	printf("%d %d",max_num,max_layer);
	return 0;
}

