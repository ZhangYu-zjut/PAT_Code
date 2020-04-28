#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//并查集+DFS+VECTOT  AC!!
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
		hashtable[findfather(i)]=1;//这个是findfather(i)
	}
	for(i=1;i<=n;i++)
	{
		if(hashtable[i]==1)ans++;//这个是i 
	}
	return ans;
}
void DFS(int st,int pre,int height)//这个height很重要 
{
	if(height>maxh)//更新条件 
	{
		temp.clear();//删除的时候直接将向量中的所有元素都删除！！！ 
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
	init(n);//必须先进行初始化！！！！ 
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a,b);//把a和b连接起来！！统计连通块的个数。 
	}
	int judge=calblock(n);
	int count=0,st=1,pre=st;
	if(judge==1)
	{
		DFS(st,0,1);//随便选个点进行DFS 
		ans=temp;//将结果存放到ans中 
		DFS(ans[0],0,1);//从ans中取出ans[0]，对ans[0]进行DFS，结果存放在temp中 
		for(int k=0;k<temp.size();k++)
		{
			ans.push_back(temp[k]);//插入过程中可能会有重复的值 
		}
		sort(ans.begin(),ans.end());//对vector进行排序 
		printf("%d\n",ans[0]);
		for(int k=1;k<ans.size();k++)//重复的编号不输出！！！！因为DFS的时候可能会将重复序号插入 
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
