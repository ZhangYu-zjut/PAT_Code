#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct goods
{
	int id;
	int no[10010];
	int len=0;
}g[100010];
int num[10010];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int i,j,m,n,s;
	int a,b,k,h;
	int temp,t,p;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&g[i].id,&g[i].no[g[i].len]);
			g[i].len++;
		}

		for(i=0;i<m;i++)//m个大循环 
		{
			bool secure=true;
			scanf("%d",&k);
			for(j=0;j<k;j++)
			{
				scanf("%d",&num[j]);
			}
			for(j=0;j<k;j++)//k个小循环 
			{
				for(t=0;t<n;t++)//从危险品中进行寻找 
				{
					if(g[t].id==num[j])//找到对应编号 
					{
						for(h=0;h<g[t].len;h++)//对应的货物是否存在 
						{
							for(p=0;p<k;p++)
							{
								if(num[p]==g[t].no[h])
								{
									secure=false;
								}
							}
						}
					}
				}
			}
			secure==true?printf("Yes\n"):printf("No\n");
		}
	}
	return 0;
}
