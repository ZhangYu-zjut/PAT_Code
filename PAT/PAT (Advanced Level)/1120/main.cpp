#include <iostream>
#include <stdio.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define N 10020
int num[N];
int fri[N]={0};
int count=0;
int main(int argc, char** argv) {
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			int sum=0;
			while(1)
			{
				int temp=num[i]%10;
				num[i]/=10;
				sum+=temp;
				if(num[i]<1)
				{
					break;
				}
			}
			fri[sum]=sum;
		}
		for(i=0;i<N;i++)
		{
			if(fri[i]!=0)
			{
				count++;
			}
		}
		printf("%d\n",count);
		bool first=true;
		for(i=0;i<N;i++)
		{
			if(fri[i]!=0&&first==false)
			{
				printf(" %d",fri[i]);
			}
			if(fri[i]!=0&&first==true)
			{
				printf("%d",fri[i]);
				first=false;
			}	

		}
	} 
	return 0;
}
