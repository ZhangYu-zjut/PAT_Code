#include <iostream>
#include <stdio.h>
#define N 100
#define inf 100000
#define debug 0
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int i,j,k,n,m;
	int edge[N][N];
	int a,b,c;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0&&m!=0)
	{
		for(i=1;i<=n;i++)//�Ա�ֵ���г�ʼ�� 
		{
			for(j=1;j<=n;j++)
			{
				edge[i][j]=inf;
				edge[i][i]=0;
			}			
		}
	
		for(i=1;i<=m;i++)//�Ա�ֵ���и���
		{
			scanf("%d%d%d",&a,&b,&c);
			edge[a][b]=c;
			edge[b][a]=c;
		}	 

		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(edge[i][k]==inf||edge[k][j]==inf)//�¼���Ľڵ㵽i����j�ľ���Ϊ�����,��ԭ���ľ��벻���и��� 
					{
						continue;
					}
					if(edge[i][j]==inf||edge[i][k]+edge[k][j]<edge[i][j])//����Ľڵ㵽i����j�ľ���Ϊ���ޡ�����·��������̻���ԭ���������,���ԭ���ľ�����и��� 
					{
						edge[i][j]=edge[i][k]+edge[k][j];
					}
				}
			}
		}
		#if debug 
		for(i=1;i<=n;i++)//���� 
		{
			for(j=1;j<=n;j++)
			{
				printf("edge[%d][%d] is %d\n",i,j,edge[i][j]);
			}			
		}
		#endif
		printf("%d\n",edge[1][n]);
	}
	return 0;
}
