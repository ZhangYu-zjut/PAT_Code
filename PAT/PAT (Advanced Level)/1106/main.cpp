#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//求解一棵树的叶子节点的最小深度和含有最小深度的叶子个数，思路：
//与PAT_A1106思路类似，在PAT_A1106的基础上，计算每个叶子的数量和价格，并将所有叶子节点的价格加起来即可。
//BFS的思想，用结构体node存储相应的信息，不难，AC!!! 
struct node
{
	int layer;
	int amount;
	vector<int>child;
}N[100005]; 
int num[100005];
double ans=0.0;
int min_layer=100000;
int cnt=0; 
void BFS(int root)
{
	queue<int>q;
	N[root].layer=0;
	q.push(root);
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		int size=N[temp].child.size();
		int exp=N[temp].layer;
		int amt=N[temp].amount;
		if(size!=0)
		{
			for(int i=0;i<size;i++)
			{
				N[N[temp].child[i]].layer=N[temp].layer+1;
				q.push(N[temp].child[i]);
			}
		}
		else
		{
			num[exp]++;
			if(exp<min_layer)
			{
				min_layer=exp;
			}
		}
	}
}
int main(int argc, char** argv) {
	int n,i,j,k,temp,root;
	double price,inc;
	scanf("%d%lf%lf",&n,&price,&inc);
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		if(k>0)
		{
			for(j=0;j<k;j++)
			{
				scanf("%d",&temp);
				N[i].child.push_back(temp);
			}
		}
	}
	BFS(0);
	printf("%.4lf %d\n",price*pow((1+1.0*inc/100),min_layer),num[min_layer]);
	return 0;
}
