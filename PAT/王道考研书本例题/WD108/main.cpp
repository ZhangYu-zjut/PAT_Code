#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�㷨���̣�
//�������ݣ���root[]���г�ʼ�� 
//�ж�������ĸ��ڵ��Ƿ�Ϊͬһ���ڵ㣬���ǵĻ����Ͱ������������������� 
//�ж��������ϵĸ�������Ҫ�޽���·��Ϊ������-1�� 
#define N 10000002
int tree[N];
int sum[N];//���ÿ�����ڵ����ڼ��ϵĽڵ��� 
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
				sum[b]=sum[b]+sum[a];//�������Ϻϲ��󣬽�����һ�����ϵĽڵ����ӵ���һ�����ϵĸ��ڵ��С� 
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
