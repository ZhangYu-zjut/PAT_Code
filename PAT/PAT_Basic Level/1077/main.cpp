#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//只过了1个测试点. 
int num[10];
struct group
{
	int s;
	int score[5];
	int length;
	double ave;
	int final;
}S[1000];
int main(int argc, char** argv) {
	int n,m,i,j;
	
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		int k=0;
		scanf("%d",&S[i].s);
		for(j=0;j<5;j++)
		{
			scanf("%d",&num[j]);
			if(num[j]>=0&&num[j]<=m)
			{
				S[i].score[k++]=num[j];
				
			}
		}
		S[i].length=k;
	}
	
	double temp;
	for(i=0;i<n;i++)
	{
		int sum=0;
		sort(S[i].score,S[i].score+S[i].length);
		for(j=1;j<S[i].length-1;j++)
		{
			sum+=S[i].score[j];
		}
		S[i].ave=(1.0*sum/(S[i].length-2));
		S[i].final=(int)((S[i].ave+S[i].s+0.0)/2.0+0.5);
		printf("%d\n",S[i].final);
	}
	printf("%c",'a'+30); 
	return 0;
}
