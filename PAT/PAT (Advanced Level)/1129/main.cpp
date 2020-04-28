#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//两个测试点超时！！ 
struct node
{
	int id;
	int fre=0;
}N[50002];
bool cmp(node a,node b)
{
	if(a.fre!=b.fre)
	{
		return a.fre>b.fre;
	}
	else return a.id<b.id;
}
int num[50004];
int main(int argc, char** argv) {
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j,k,temp;
	int count=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(i>0)
		{
			sort(N,N+count,cmp);
			printf("%d:",temp);
			for(j=0;j<m;j++)
			{
				if(N[j].fre!=0)
				{
					printf(" %d",N[j].id);
				}
			}
			printf("\n");
		}
		bool find=false;
		for(k=0;k<count;k++)
		{
			if(N[k].id==temp)
			{
				N[k].fre++;
				find=true;
			}
		}
		if(!find)
		{
			N[count].id=temp;
			N[count].fre++;
			count++;
		}
	}
	return 0;
}
