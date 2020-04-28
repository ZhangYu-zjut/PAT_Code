#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PAT_B1053 住房空置率 （20 分）AC!!!!
#define N 1010
double num[N];
int judge[N];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n,d;
	double e;
	int i,j,k;
	while(scanf("%d%lf%d",&n,&e,&d)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			judge[i]=-1;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			int count=0;
			for(j=0;j<k;j++)
			{
				scanf("%lf",&num[j]);
				if(num[j]<e)
				{
					count++;
				}
			}
			if(count>0.5*k)
			{
				judge[i]=1;
			}
			if(k>d&&count>0.5*k)
			{
				judge[i]=0;
			}
		}
		int empty=0;
		int may_empty=0;
		for(i=0;i<n;i++)
		{
			if(judge[i]==0)
			{
				empty++;
			}
			if(judge[i]==1)
			{
				may_empty++;
			}
		}
		printf("%.1lf%% ",100.0*may_empty/n);
		printf("%.1lf%%\n",100.0*empty/n);
	}
	return 0;
}
