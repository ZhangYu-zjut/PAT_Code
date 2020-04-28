#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n,m;
const int inf=1000000;
const int maxn=1000;
vector<int>v[100004];
int num[100005];
bool vis[100004];
set<int>s;
bool ans=true;
void DFS(int x)
{
	int i;
	vis[x]=true;
	for(i=0;i<v[x].size();i++)
	{
		if(vis[v[x][i]]==false)
		{
			if(num[x]==num[v[x][i]])
			{
				ans=false;
				return;
			}
			DFS(v[x][i]);
		}
	}
}
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	int i,j,k,t;
	int a,b;
	//fill(G[0],G[0]+maxn*maxn,inf);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		//v[b].push_back(a);
						
	}
	scanf("%d",&k);
	for(t=0;t<k;t++)
	{
		fill(vis,vis+10003,false);
		s.clear();
		for(i=0;i<n;i++){
			scanf("%d",&num[i]);
			s.insert(num[i]);
		}
		ans=true;
		int allcolor=s.size();
		for(i=0;i<n;i++)
		{
			if(vis[i]==false)
			{
				DFS(i);
			}
		}
		if(!ans)
		{
			printf("No\n");
		}
		if(ans)
		{
			printf("%d-coloring\n",allcolor);
		}
	}
		
	
	return 0;
}
