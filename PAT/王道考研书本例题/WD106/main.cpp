#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�㷨���̣�
//�������ݣ���root[]���г�ʼ�� 
//�ж�������ĸ��ڵ��Ƿ�Ϊͬһ���ڵ㣬���ǵĻ����Ͱ������������������� 
//�ж��������ϵĸ�������Ҫ�޽���·��Ϊ������-1�� 
int tree[50];
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
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		scanf("%d",&m);
		for(i=1;i<=n;i++)
		{
			tree[i]=-1;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b)
			{
				tree[a]=b;
			}
		}
		ans=0;
		for(j=1;j<=n;j++)
		{
			if(tree[j]==-1)
			{
				ans++;
			}
		}
		printf("%d\n",ans-1);
	}
	return 0;
}
