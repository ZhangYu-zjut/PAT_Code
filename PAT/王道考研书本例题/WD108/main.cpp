#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//算法过程：
//读入数据，对root[]进行初始化 
//判定两个点的根节点是否为同一个节点，不是的话，就把两个集合连接起来。 
//判定各个集合的根数量，要修建的路即为根数量-1。 
#define N 10000002
int tree[N];
int sum[N];//存放每个根节点所在集合的节点数 
int findRoot(int x)
{
	
	if(tree[x]==-1)return x;
	else
	{
		int temp = findRoot(tree[x]);
		tree[x]=temp;
		return temp;
	}
	
} 

int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n,m,ans;
	int i,j;
	int a,b;
	int temp2;
	while(scanf("%d",&m)!=EOF)
	{

		for(i=1;i<=N;i++)
		{
			tree[i]=-1;
			sum[i]=1;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b)
			{
				tree[a]=b;
				sum[b]=sum[b]+sum[a];//两个集合合并后，将其中一个集合的节点数加到另一个集合的根节点中。 
			}
		}
		ans=0;
		int maxsum=2;
		for(j=1;j<=N;j++)
		{
			if(tree[j]==-1&&sum[j]>maxsum)
			{
				maxsum = sum[j];
			}
		}
		printf("%d\n",maxsum);
	}
	return 0;
}
