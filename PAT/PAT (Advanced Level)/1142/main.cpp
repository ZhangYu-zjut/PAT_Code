#include <iostream>
#include <stdio.h>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//19分，部分正确！！ 
using namespace std;
const int maxn=203;
const int inf=10000003;
int G[maxn][maxn];
int num[maxn];
int n;
bool innum[maxn];
//暴力求解 
int judge(int num[],int size)
{
	int result;
	int i,j;
	bool exit=true;
	bool max=true;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(j!=i&&G[num[i]][num[j]]==inf)
			{
				exit=false;
				return -1;
				break;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		int count=0;
		for(j=0;j<size;j++)
		{
			//存在一个点，从这个点到查询的点均可达，说明不是最大块 
			if(innum[i]==false&&G[i][num[j]]!=inf&&G[num[j]][i]!=inf&&i!=num[j])
			{
				count++;
			}
		}
		if(count==size)
		{
			return 0;
		}
	}
	return 1;
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int m,i,j,k,t,temp;
	fill(G[0],G[0]+maxn*maxn,inf);
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		G[a][b]=1;
		G[b][a]=1;
	}
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		fill(innum,innum+maxn,false);
		fill(num,num+maxn,inf);
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d",&temp);
			printf("Yes\n");
			continue;
		}
		for(j=0;j<t;j++)
		{
			scanf("%d",&temp);
			num[j]=temp;
			innum[num[j]]=true;
		}
		int ans=judge(num,t);
		if(ans==-1)printf("Not a Clique\n");
		else if(ans==0)printf("Not Maximal\n");
		else printf("Yes\n");
	}
	return 0;
}
