#include <iostream>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int num[1001][1001];
int main(int argc, char** argv) {
	freopen("test.txt", "r", stdin);
	int t, k;
	int i, j, m,n,g;
	int total;
	int n1, n2,b,bound;
	//printf("hell"); 
	while (scanf("%d%d%d", &m,&n,&bound) != EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&num[i][j]);
			}
		}
		bool find=false;
		int count=0;
		int column=0;
		int row=0;
		int color=0;
		for(i=1;i<n-1;i++)
		{
			for(j=1;j<m-1;j++)
			{
				int time=0;
				for(t=-1;t<2;t++)
				{
					for(g=-1;g<2;g++)
					{
						if((num[i][j]-num[i-t][j-g])>bound)
						{
							time++;
						}
					}
				}
				if(time==8)
				{
					find=true;
					column=j+1;
					row=i+1;
					color=num[i][j];
					count++;
				} 
			}
		} 
		if(find==false)
		{
			printf("Not Exist\n");
		}
		else
		{
			if(count==1)
			{
				printf("(%d, %d): %d\n",column,row,color);
			}
			if(count>1)
			{
				printf("Not Unique\n");
			}
		}
	}
	return 0;
}
