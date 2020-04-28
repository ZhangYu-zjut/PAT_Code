#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//算法思路： 
//定义边的结构，并读入数据 
//按照权值递增的顺序排列边 
//按顺序遍历所有的边：取出权值最小的边，判定两个节点是否为同一集合节点，若不是，则将节点合并，并将权值加到最后的答案中。 
//判断所有的节点是否属于同一集合，若不是，则不存在最小生成树。 
//若是，则将最后的答案输出 
#define N 500
int tree[N];

struct edge
{
	int a,b;//定义两个节点的编号
	int cost; 
}Edge[N]; 
bool cmp(edge a,edge b)
{
	return a.cost<b.cost;
}
int findRoot(int x)//找到某个x节点的根节点
{
	if(tree[x]==-1)return x;
	else
	{
		int temp = findRoot(tree[x]);//找到某个x节点的根节点
		tree[x]=temp;//并将该节点的双亲节点修改为根节点。 
		return temp;
	}
} 
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int i,j,n;
	int a,b;
	int root[500];//存放各个节点的根节点信息 
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		int ans=0;//存放最后的结果 
		for(j=1;j<=n;j++)
		{
			tree[j]=-1;
		}
		for(i=1;i<=n*(n-1)/2;i++)
		{
			scanf("%d%d%d",&Edge[i].a,&Edge[i].b,&Edge[i].cost);
		}
		sort(Edge,Edge+n*(n-1)/2,cmp);
		for(i=1;i<=n*(n-1)/2;i++)
		{
			a=findRoot(Edge[i].a);
			b=findRoot(Edge[i].b);
			if(a!=b)
			{
				tree[a]=b;
				ans+=Edge[i].cost;//合并节点的时候将权值相加 
			}
		}
		//判定所有的点是否属于同一集合
		bool mst=true;
		for(j=1;j<=n-1;j++)
		{
			if(findRoot(j)!=findRoot(j+1))
			{
				mst =false;
				break;
			}
		}
		if(mst==true)
		{
			printf("%d\n",ans);
		}
		else printf("不能生成最小生成树\n");

	}
	return 0;
}
