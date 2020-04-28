#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//˼·�� 
//���ò��鼯��˼�룬������ͬһ����������һ�����ϣ�ÿ�����϶���һ�����ڵ㡣��ͬ���ϵĸ��ڵ������Ϊ���ĸ��� 
//�ڲ��Ҹ��ڵ��ʱ����Ҫ��·������ѹ������Ȼ�ᵼ��һ�����Ե㲻ͨ������
//AC!!! 
#define N 10001
int father[N];
int isroot[N];
vector<int>v[10001];
set<int>s;
int findroot(int x)//�ҵ�x�ĸ��ڵ㲢����
{
	int a=x; 
	while(x!=father[x])//�ҵ����ڵ� 
	{
		x=father[x];
	}
	while(a!=father[a])//·��ѹ�������Ҹ��ڵ�Ĺ����У���ԭʼx����·���ϵ����нڵ�ĸ��ڵ��޸�Ϊ���ڵ㡣 
	{
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
} 
void Union(vector<int>v)//��a��b�ĸ��ڵ㲻��ͬ����a��b���кϲ�
{
	int fa=findroot(v[0]);
	for(int i=1;i<v.size();i++)
	{
		int fb=findroot(v[i]);
		father[fb]=fa;
	}
} 
void init(int n)//�Խڵ���Ϣ���г�ʼ�� 
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
