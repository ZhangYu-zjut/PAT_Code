#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//值得借鉴的地方：
//利用score数组，rank数组，利用exit1数组存储下标，并判定是否存在， 
//AC!!!! 
struct student
{
	int id,best;
	int score[4],rank[4];
}stu[10001];
int exit1[10000001];
int flag=-1;
bool cmp(student a,student b)
{
	return a.score[flag]>b.score[flag];
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int i,j,k,n,m,t;
	int best;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)//读取数据 
	{
		scanf("%d%d%d%d",&stu[i].id,&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
		stu[i].score[0]=(stu[i].score[1]+stu[i].score[2]+stu[i].score[3]+0.0)/3.0;
	}
	for(flag=0;flag<4;flag++)//排序 
	{
		sort(stu,stu+n,cmp);
		stu[0].rank[flag]=1;
		for(j=1;j<n;j++)
		{
			stu[j].rank[flag]=j+1;
			if(stu[j].score[flag]==stu[j-1].score[flag])
			{
				stu[j].rank[flag]=stu[j-1].rank[flag];
			}
		} 
	}
	//找到最好名次的下标。并把学生的下标存储起来 
	for(i=0;i<n;i++)
	{
		exit1[stu[i].id]=i+1;//某个id的学生下标为i+1,通过某个id直接找到该学生，快速。 
		int minn=stu[i].rank[0];
		stu[i].best=0;
		for(j=0;j<4;j++)
		{
			if(stu[i].rank[j]<minn)
			{
				stu[i].best=j;
				minn=stu[i].rank[j];
			}
		}
	}
	char ch[]={'A','C','M','E'};
	int id;
	for(i=0;i<m;i++)
	{
		scanf("%d",&id);
		int index=exit1[id]-1;
		if(exit1[id])
		{
			printf("%d %c\n",stu[index].rank[stu[index].best],ch[stu[index].best]); 
		}
		else
		{
			printf("N/A\n");//不能漏了换行符！！！！ 
		}
	}
	//输出 
	
	return 0;
}
