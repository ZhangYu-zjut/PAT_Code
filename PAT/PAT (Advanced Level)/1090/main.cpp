#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//求解一棵树的最大深度和含有最大深度的叶子个数，思路：
//利用BFS的思想，利用向量vector v存储每个供应商下面的客户，并利用lawyer数组存储每个节点的层数 
//利用层次遍历，对每个节点进行遍历，并将对应的层数放在lawyer数组中 
//对lawyer数组进行降序排序，第一个值就是层数最高的值，同时对该数组进行遍历，找到层数最高的节点个数。
//对结果进行处理后输出。 
//AC!!!!
vector<int>v[100001];
int lawyer[100001];
void BFS(int root)
{
	queue<int>q;
	if(v[root].size()==0)return;
	else
	{
		q.push(root);
		lawyer[root]=0;
		while(!q.empty())
		{
			int now= q.front();
			q.pop();
			for(int i=0;i<v[now].size();i++)
			{
				lawyer[v[now][i]]=lawyer[now]+1;
				q.push(v[now][i]);
			}	
		}
	}
}
bool cmp(int a,int b)
{
	return a>b;
}
int main(int argc, char** argv) {
	int n,i,j,k,temp,root;
	double price,inc;
	scanf("%d%lf%lf",&n,&price,&inc);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(temp==-1)root=i;
		else v[temp].push_back(i);
	}
	BFS(root);
	sort(lawyer,lawyer+n,cmp);
	int max_lawyer=lawyer[0];
	int cnt=0;
	for(i=0;i<n;i++)
	{
		if(lawyer[i]==max_lawyer)
		{
			cnt++;
		}
	}
	printf("%.2lf %d\n",price*pow((1.0+inc/100),max_lawyer*1.0),cnt);
	return 0;
}
