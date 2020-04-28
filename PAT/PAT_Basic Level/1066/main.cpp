#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int num[600];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n,m,a,b,i,j;
	int change;
	scanf("%d%d%d%d%d",&m,&n,&a,&b,&change);
	for(i=0;i<m;i++)
	{
		int k=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&num[k]);
			if(num[k]>=a&&num[k]<=b)
			{
				num[k]=change;
			}
			if(j==0)
			{
				printf("%03d",num[k]);
			}
			if(j>0)
			{
				printf(" %03d",num[k]);
			}
			k++;
		}
		printf("\n");
	}
	return 0;
}
