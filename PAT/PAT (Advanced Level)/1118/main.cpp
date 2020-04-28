#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//思路： 
//利用并查集的思想，将属于同一棵树的鸟看做一个集合，每个集合都有一个根节点。不同集合的根节点个数即为树的个数 
//在查找根节点的时候，需要对路径进行压缩，不然会导致一个测试点不通过！！
//AC!!! 
#define N 10001
int father[N];
int isroot[N];
vector<int>v[10001];
set<int>s;
int findroot(int x)//找到x的根节点并返回
{
	int a=x; 
	while(x!=father[x])//找到根节点 
	{
		x=father[x];
	}
	while(a!=father[a])//路径压缩，在找根节点的过程中，将原始x所在路径上的所有节点的父节点修改为根节点。 
	{
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
} 
void Union(vector<int>v)//若a和b的根节点不相同，将a和b进行合并
{
	int fa=findroot(v[0]);
	for(int i=1;i<v.size();i++)
	{
		int fb=findroot(v[i]);
		father[fb]=fa;
	}
} 
void init(int n)//对节点信息进行初始化 
{
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
		isroot[i]=false;
	}
}
int main(int argc, char** argv) {
	int i,j,k,temp;
	freopen("test.txt","r",stdin);
	int a,b,m,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		for(j=0;j<k;j++)
		{
			scanf("%d",&temp);
			v[i].push_back(temp);
			s.insert(temp);
		}
	}
	init(s.size());
	for(i=0;i<n;i++)
	{
		Union(v[i]);
	}
	for(set<int>::iterator it=s.begin();it!=s.end();it++)
	{
		isroot[findroot(*it)]=true;
	}
	int tree_count=0;
	for(set<int>::iterator it=s.begin();it!=s.end();it++)
	{
		if(isroot[*it])
		{
			tree_count++;
		}
	}
	int bird_count=s.size();
	printf("%d %d\n",tree_count,bird_count);
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		if(findroot(a)==findroot(b))printf("Yes\n");
		else printf("No\n");	
	}
	return 0;
}
