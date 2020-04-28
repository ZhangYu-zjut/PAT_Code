#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Ç§ÐÁÍò¿àµÄAC!!! 
int num[10001];
int ans[10001][10001];

bool cmp(int a,int b)
{
	return a>b;
}
int main(int argc, char** argv) {
	int N;
	scanf("%d",&N);
	int i,j,k,m,n;
	int a,b;
	int MIN=100000;
	int temp=sqrt(N);
	for(i=1;i<=temp;i++)//m*n;
	{
		if(N%i==0)
		{
			b = N/i;
			if(b-i<MIN)
			{
				MIN = b-i;
				m = b;
				n = i;
			}
		}
	}

	for(i=0;i<N;i++)
	{
		scanf("%d",&num[i]);
	}
	if(N==1)
	{
		printf("%d",num[0]);
		return 0;
	}
	sort(num,num+N,cmp);
	int count=0;
	ans[0][0]=num[0];
	i=1,j=1;
	int R=n,D=m,L=1,U=1;
	while(count<N)
	{
		while(count<N&&j<R)
		{
			ans[i][j]=num[count];
			count++;
			j++;
		}
		while(count<N&&i<D)
		{
			ans[i][j]=num[count];
			count++;
			i++;
		}
		while(count<N&&j>L)
		{
			ans[i][j]=num[count];
			count++;
			j--;
		}
		while(count<N&&i>U)
		{
			ans[i][j]=num[count];
			count++;
			i--;
		}
		R--,D--,L++,U++;
		i++,j++;
		if(count==N-1)
		{
			ans[i][j]=num[count];
			count++;
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j==1)printf("%d",ans[i][j]);
			else printf(" %d",ans[i][j]);
		}	
		if(i<=m-1)printf("\n");	
	}
	return 0;
}
