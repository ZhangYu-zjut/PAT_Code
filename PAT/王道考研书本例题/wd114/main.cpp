#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�㷨˼·�� 
//����ߵĽṹ������������ 
//����Ȩֵ������˳�����б� 
//��˳��������еıߣ�ȡ��Ȩֵ��С�ıߣ��ж������ڵ��Ƿ�Ϊͬһ���Ͻڵ㣬�����ǣ��򽫽ڵ�ϲ�������Ȩֵ�ӵ����Ĵ��С� 
//�ж����еĽڵ��Ƿ�����ͬһ���ϣ������ǣ��򲻴�����С�������� 
//���ǣ������Ĵ���� 
#define N 100
int tree[N];

struct point
{
	double x,y;
}
Point[N];


struct edge
{
	int a,b;//���������ڵ�ı��
	double cost; //����Ϊdouble 
}Edge[N]; 
bool cmp(edge a,edge b)
{
	return a.cost<b.cost;
}
double distance(double x1,double x2,double y1,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
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
		
		for(j=1;j<=n;j++)
		{
			tree[j]=-1;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",&Point[i].x,&Point[i].y);
		}
		int k=1;//k��1��ʼ 
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				double dis = distance(Point[i].x,Point[j].x,Point[i].y,Point[j].y);
				Edge[k].a=i;
				Edge[k].b=j;
				Edge[k].cost=dis;
				k++;
			}
		}
		sort(Edge,Edge+k,cmp);
		double ans=0.0;//������Ľ����ע��Ϊdouble 
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
			printf("%.2lf\n",ans);//������λС�� 
		}
		else printf("����������С������\n");

	}
	return 0;
}
