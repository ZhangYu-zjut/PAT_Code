#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct student
{
	int id;
	int total=-1;
	int score[6]={-1,-1,-1,-1,-1,-1};
	int perfect=0;
	int sub[6]={0};
	int rank;
}stu[100004];
int full[6];
bool cmp(student a,student b)
{
	if(a.total!=b.total)return a.total>b.total;
	else
	{
		if(a.perfect!=b.perfect)
		{
			return a.perfect>b.perfect;
		}
		else
		{
			return a.id<b.id;
		} 
	} 
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	int i,j;
	for(i=1;i<=k;i++)
	{
		scanf("%d",&full[i]);
	}
	for(i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		stu[a].id=a;
		if(c==-1)
		{
			stu[a].score[b]=0;
		}
		if(c>stu[a].score[b])
		{
			stu[a].score[b]=c;
		}	
		if(c==full[b])stu[a].perfect++;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			if(stu[i].score[j]!=-1)
			{
				stu[i].total+=stu[i].score[j];
			}
		}
	}
	sort(stu+1,stu+n+1,cmp);
	stu[1].rank=1;
	for(i=2;i<=n;i++)
	{
		if(stu[i].total==stu[i-1].total)
		{
			stu[i].rank=stu[i-1].rank;
		}
		else
		{
			stu[i].rank=i;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(stu[i].total>0)
		{
			printf("%d %05d %d",stu[i].rank,stu[i].id,stu[i].total+1);
			for(j=1;j<=k;j++)
			{
				if(stu[i].score[j]==-1)
				{
					printf(" -");
				}
				else
				{
					printf(" %d",stu[i].score[j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
