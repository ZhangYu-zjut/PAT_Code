#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PAT_B 1065 单身狗 （25 分）AC!!!!
int num[100010]; 
int cmp[100010];
int single[100010];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int i,j,m,n,s;
	int a,b;
	int temp;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<100000;i++)
		{
			num[i]=-1;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			num[a]=b;
			num[b]=a;
		}	
		scanf("%d",&m);
		int count=0;
		int t=0;
		for(i=0;i<m;i++)
		{
			scanf("%d",&cmp[i]);
		}
		for(i=0;i<m;i++)
		{
			bool find=false;
			if(num[cmp[i]]==-1)
			{
				single[t]=cmp[i];
				t++;
			}
			else
			{
				for(j=0;j<m;j++)
				{
					if(cmp[j]==num[cmp[i]] || num[cmp[j]]==cmp[i])
					{
						find=true;
					}
				}
				if(find==false)
				{
					single[t]=cmp[i];
					t++;
				}
			}
		}
		sort(single,single+t);
		printf("%d\n",t);
		for(i=0;i<t;i++)
		{
			if(i==0)
			{
				printf("%04d",single[i]);
			}
			else
			{
				printf(" %04d",single[i]);
			}
		} 
		//printf("\n");这句话一定要删除 
	}
	return 0;
}
