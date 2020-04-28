#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//˼·������direction��¼������i��j��¼��ǰ��δ��λ�á�ÿ�ζ��µ�λ�ý����жϣ����û��Խ�磬����ֵû�б���ֵ������и�ֵ��
//���������direction[i][0]���з���任��ֱ�����е�����Ԫ�ض�����ֵ�����������. 
int matrix[10000][10000]; 
int num[10000];
int direction[4][2]={
{0,1},{1,0},{0,-1},{-1,0}
};
bool cmp(int a,int b)
{
	return a>b;
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n,i,j,k,N,m;
	int sum=100;
	
	while(scanf("%d",&N)!=EOF)
	{
		for(int i=(int)sqrt(N);i>0;i--)
		{
			if(N%i==0)
			{
				m=N/i;
				n=N/m; 
				break;
			}
		}
		for(i=0;i<N;i++)
		{
			scanf("%d",&num[i]);
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				matrix[i][j]=0;
			}
		}
		sort(num,num+N,cmp);
		int i=0,j=-1;
		int direct=0;
		int k;
		for(k=0;k<N;k++)
		{
			int ii=i+direction[direct%4][0];
			int jj=j+direction[direct%4][1];
			if(ii<0||ii>=m||jj<0||jj>=n||matrix[ii][jj]!=0)
			{
				direct++;
			}
			i+=direction[direct%4][0];
			j+=direction[direct%4][1];
			matrix[i][j]=num[k];
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(j==0)
					printf("%d",matrix[i][j]);
				else
				{
					printf(" %d",matrix[i][j]);
				}
			}
			printf("\n");
		}
		
	} 
	return 0;
}
