#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//结果有一些问题，表现为：没有按照停站数量最少的进行更新，也没有按照换乘最小的进行更新
//line的表示上有点问题 
int line[10000][10000];
vector<int>v[10000];
const int inf=1000000;
bool vis[100000];
int maxcnt1=inf;
int maxcnt2=inf;
int n;
int st,ed;
vector<int>path,pathtemp,lineans;
int prenode;
int preline,curline;
int num[200];
vector<int>::iterator it;
void DFS(int pre,int index,int cnt,int change)
{
	//printf("index is %d\n",index);//3011-3812-3013-3011-3812-3013
	vis[index]=true;
	if(index==ed)
	{
		vis[index]=false;
		if(cnt<maxcnt1)
		{
			maxcnt1=cnt;
			maxcnt2=change;
			pathtemp.push_back(index);
			path=pathtemp;
			pathtemp.pop_back();
		}
		if(cnt==maxcnt1)
		{
			if(change<maxcnt2)
			{
				maxcnt2=change;
				pathtemp.push_back(index);
				path=pathtemp;
				pathtemp.pop_back();
			}
		}
		return;
	}
	for(int i=0;i<v[index].size();i++)
	{
		int next=v[index][i];
		if(vis[next]==false&&pre==index)
		{
			pathtemp.push_back(index);
			DFS(index,next,cnt+1,change);
			pathtemp.pop_back();
			continue;
		}
		preline=line[pre][index];
		curline=line[index][next];
		if(vis[next]==false&&preline!=curline)
		{
			pathtemp.push_back(index);
			DFS(index,next,cnt+1,change+1);
			pathtemp.pop_back();
		}
		if(vis[next]==false&&preline==curline)
		{
			DFS(index,next,cnt+1,change);
		}
	}

}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int m,i,j,k,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(j=1;j<=k;j++)
		{
			scanf("%d",&num[j]);
		}
		for(j=1;j<=k;j++)
		{
			if(j==1)v[num[j]].push_back(num[j+1]);
			else if(j==k)v[num[j]].push_back(num[j-1]);
			else
			{
				v[num[j]].push_back(num[j+1]);
				v[num[j]].push_back(num[j-1]);
			}
		}
		for(j=1;j<=k;j++)
		{
			for(t=j+1;t<=k;t++)
			{
				line[num[j]][num[t]]=i;
				line[num[t]][num[j]]=i;
			}
		}
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		maxcnt1=inf;
		maxcnt2=inf;
		fill(vis,vis+10000,false);
		scanf("%d%d",&st,&ed);
		int cnt1=1,cnt2=inf;
		DFS(st,st,0,0);
		cnt1=maxcnt1;
		printf("%d\n",cnt1);
		int pr,now;
		printf("size of path is%d\n",path.size());
		for(j=0;j<path.size()-1;j++)
		{
			if(j==0)pr=line[path[j]][path[j+1]];
			printf("Take Line#%d from %d to %d.\n",line[path[j]][path[j+1]],path[j],path[j+1]);
		}
		printf("change is%d\n",maxcnt2);
	}
	return 0;
}
