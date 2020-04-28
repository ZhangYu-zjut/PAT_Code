#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//���鼯+DFS+VECTOT  AC!!
int n,m;
const int maxn=10003;
bool vis[10004];
vector<int>G[10004];
vector<int>temp,ans;
int maxh=0; 
int father[10004];
int hashtable[10004];
int num[maxn]; 
void init(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		father[i]=i;
	}
}
int findfather(int x)
{
	int a=x;
	while(x!=father[x])
	{
		x=father[x];
	}
	return x;
}
void Union(int a,int b)
{
	int fa=findfather(a);
	int fb=findfather(b);
	if(fa!=fb)
	{
		father[fa]=fb;
	}	
} 
int calblock(int n)
{
	int i;
	fill(hashtable,hashtable+maxn,0);
	int temp=father[1];
	int ans=0;
	for(i=1;i<=n;i++)
	{
		hashtable[findfather(i)]=1;//�����findfather(i)
	}
	for(i=1;i<=n;i++)
	{
		if(hashtable[i]==1)ans++;//�����i 
	}
	return ans;
}
void DFS(int st,int pre,int height)//���height����Ҫ 
{
	if(height>maxh)//�������� 
	{
		temp.clear();//ɾ����ʱ��ֱ�ӽ������е�����Ԫ�ض�ɾ�������� 
		temp.push_back(st);
		maxh=height;
	}
	else if(height==maxh)
	{
		temp.push_back(st);
	}
	for(int i=0;i<G[st].size();i++)
	{
		if(G[st][i]==pre)continue;
		DFS(G[st][i],st,height+1); 
	}
	
}
int main(int argc, char** argv) {
	int i,j,k,a,b;
	scanf("%d",&n);
	init(n);//�����Ƚ��г�ʼ���������� 
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a,b);//��a��b������������ͳ����ͨ��ĸ����� 
	}
	int judge=calblock(n);
	int count=0,st=1,pre=st;
	if(judge==1)
	{
		DFS(st,0,1);//���ѡ�������DFS 
		ans=temp;//�������ŵ�ans�� 
		DFS(ans[0],0,1);//��ans��ȡ��ans[0]����ans[0]����DFS����������temp�� 
		for(int k=0;k<temp.size();k++)
		{
			ans.push_back(temp[k]);//��������п��ܻ����ظ���ֵ 
		}
		sort(ans.begin(),ans.end());//��vector�������� 
		printf("%d\n",ans[0]);
		for(int k=1;k<ans.size();k++)//�ظ��ı�Ų��������������ΪDFS��ʱ����ܻὫ�ظ���Ų��� 
		{
			if(ans[k]!=ans[k-1])printf("%d\n",ans[k]);
		}
	}
	else
	{
		printf("Error: %d components\n",judge);
	}
	return 0;
}
