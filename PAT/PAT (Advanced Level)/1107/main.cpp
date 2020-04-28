#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//代码有问题 
const int N=1003;
int node_cnt[N];//记录每个集合的元素个数，初始均为0 
int isroot[N];//记录每个集合的元素个数，初始均为0 
int father[N]; //记录每个集合的元素个数，初始均为0 
int course[N];
int ans;
int findroot(int x)
{
	while(x!=father[x])
	{
		x= father[x];
	}
	return x;
}
void Union(int a,int b)
{
	int fa=findroot(a);
	int fb=findroot(b);
	//for(int i=0;i<v.size();i++)
	{
		if(fb!=fa)
		{
			father[fb]=fa;
		}
	}
}
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
		isroot[i]=false;
	}
}
bool cmp(int a,int b)
{
	return a>b;
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int i,j,k,temp;
	int n;
	scanf("%d",&n);
	init(n);//初始化和合并操作的时候出现问题！！！！ 
	for(i=1;i<=n;i++)
	{
		scanf("%d:",&k);
		//getchar();
		//getchar();
		for(j=0;j<k;j++)
		{
			scanf("%d",&temp);
			if(course[temp]==0)
			{
				course[temp]=i;
			}
			Union(i,findroot(course[temp]));
		}
	}
	for(i=1;i<=n;i++)
	{
		isroot[findroot(i)]++;

	}
	
	for(i=1;i<=n;i++)
	{
		if(isroot[i]!=0)
		{
			ans++;
		}
	}
	printf("%d\n",ans);
	sort(isroot+1,isroot+n+1,cmp);
	for(i=1;i<=ans;i++)
	{
		if(i==0)printf("%d",isroot[i]);
		else printf(" %d",isroot[i]);
	}
	return 0;
}
