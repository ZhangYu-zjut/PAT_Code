#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//���ܶ��ٻ�·����һ�����������ÿ��������ܹ��ص�ԭʼ�㣬����ÿ������ֻ����һ�εĻ�·
//ע�⣺��ĩ�����Ҫ��ͬ�����ܶ�ξ���ͬһ���㣬�м�ǰ���֮�����ɴﵽ������ 
//AC!!!
int n,m;
const int maxn=300;
const int inf=100006;
int G[maxn][maxn];
bool vis[maxn]; 
int num[maxn];
int hashtable[maxn];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int i,j,k,a,b,t;
	fill(G[0],G[0]+maxn*maxn,inf);
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		G[a][b]=1;
		G[b][a]=1;
	}
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		fill(hashtable,hashtable+maxn,0);
		fill(num,num+maxn,0);
		bool ans=true;
		scanf("%d",&t);
		for(j=0;j<t;j++)
		{
			scanf("%d",&num[j]);
			if(j!=t-1)hashtable[num[j]]+=1;
		}
		if(num[0]!=num[t-1])
		{
			ans=false;
		}
		for(j=1;j<=n;j++)
		{
			if(hashtable[j]!=1)
			{
				ans=false;
			}
		}
		for(j=0;j<t-1;j++)
		{
			if(G[num[j]][num[j+1]]==inf)
			{
				ans=false;
			}
		}
		if(ans==true)printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
