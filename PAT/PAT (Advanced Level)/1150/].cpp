#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//没有访问所有点，或者没有回到原点，或者中间的路径不可达，都输出NO 
//AC!!!!
int n,m;
const int inf=1000000;
const int maxn=300;
const int mindis=inf;
int G[maxn][maxn];
int path[maxn];
int num[maxn];
int vis[maxn];

map<int,int>mp;
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);//n个点，m条边 
	int i,j,k,t;
	int a,b,c;
	int kind=0;
	int index;
	int distance;
	fill(G[0],G[0]+maxn*maxn,inf);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		G[a][b]=c;
		G[b][a]=c;
	}
	scanf("%d",&k);
	for(i=1;i<=k;i++)
	{
		scanf("%d",&t);
		int count=0;
		int visit=1;
		kind=0;
		fill(vis,vis+maxn,false);
		distance=0;
		for(j=1;j<=t;j++)
		{
			scanf("%d",&num[j]);
		}
		for(j=1;j<=t-1;j++)
		{
			if(vis[num[j]]==false)vis[num[j]]=true;
			else visit++;
			if(G[num[j]][num[j+1]]==inf)
			{
				distance=inf;
				kind=3;
			}
			else
			{
				distance+=G[num[j]][num[j+1]];		
			}
		}
		if(num[1]!=num[t])
		{
			kind=3;
		}
		for(j=1;j<=n;j++)
		{
			if(vis[j])
			{
				count++;
			}
		}
		if(count!=n)
		{
			kind=3;
		 } 
		if(count==n&&num[1]==num[t]&&distance!=inf&&visit==1&&kind==0)
		{
			kind=1;
		}
		/*if(i==4)
		{
			printf("count %d visit %d kind %d\n",count ,visit,kind);
		}*/
		if(count==n&&num[1]==num[t]&&distance!=inf&&visit>1&&kind==0)
		{
			kind=2;
		}
		if(distance>=inf)
		{
			printf("Path %d: NA ",i);
		}
		else
		{
			printf("Path %d: %d ",i,distance);
		} 
		if(kind==1)printf("(TS simple cycle)\n");
		if(kind==2)printf("(TS cycle)\n");
		if(kind==3)printf("(Not a TS cycle)\n");
		if(kind==2)
		{
			if(distance<mindis)
			{
				index=i;
				mp[i]=distance;	
				mindis=distance;
			}		
		}
	}
	printf("Shortest Dist(%d) = %d\n",index,mp[index]);
	return 0;
}
