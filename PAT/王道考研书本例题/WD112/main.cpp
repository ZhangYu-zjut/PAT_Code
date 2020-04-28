#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�㷨˼·�� 
//����ߵĽṹ������������ 
//����Ȩֵ������˳�����б� 
//��˳��������еıߣ�ȡ��Ȩֵ��С�ıߣ��ж������ڵ��Ƿ�Ϊͬһ���Ͻڵ㣬�����ǣ��򽫽ڵ�ϲ�������Ȩֵ�ӵ����Ĵ��С� 
//�ж����еĽڵ��Ƿ�����ͬһ���ϣ������ǣ��򲻴�����С�������� 
//���ǣ������Ĵ���� 
#define N 500
int tree[N];

struct edge
{
	int a,b;//���������ڵ�ı��
	int cost; 
}Edge[N]; 
bool cmp(edge a,edge b)
{
	return a.cost<b.cost;
}
int findRoot(int x)//�ҵ�ĳ��x�ڵ�ĸ��ڵ�
{
	if(tree[x]==-1)return x;
	else
	{
		int temp = findRoot(tree[x]);//�ҵ�ĳ��x�ڵ�ĸ��ڵ�
		tree[x]=temp;//�����ýڵ��˫�׽ڵ��޸�Ϊ���ڵ㡣 
		return temp;
	}
} 
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int i,j,n;
	int a,b;
	int root[500];//��Ÿ����ڵ�ĸ��ڵ���Ϣ 
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		int ans=0;//������Ľ�� 
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
				ans+=Edge[i].cost;//�ϲ��ڵ��ʱ��Ȩֵ��� 
			}
		}
		//�ж����еĵ��Ƿ�����ͬһ����
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
		else printf("����������С������\n");

	}
	return 0;
}
