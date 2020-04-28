#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student
{
	char id[7];
	int score;
	char from[7];
}stu[100002];
struct school
{
	int rank;
	char name[7];
	double total_score=0.0;
	int stu_num=0;	
}sch[100002];
bool mark[100002];
char id_temp[10];
char from_temp[10];
bool cmp2(school a,school b)
{
	if(a.total_score!=b.total_score)
	{
		return a.total_score>b.total_score;
	}
	else
	{
		if(a.stu_num!=b.stu_num)
		{
			return a.stu_num>b.stu_num;
		}
		else
		{
			return 1;//则按单位码的字典序输出
		}
	}
	
}
bool char_cmp(char a[],char b[])
{
	int size1=strlen(a);
	int size2=strlen(b);
	if(size1!=size2)
	{
		return false;
	}
	else
	{
		int i,j;
		for(i=0;i<size1;i++)
		{
			if(a[i]!=b[i])
			{
				return false;
			}
		}
		return true;
	}
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n;
	int i,j,k,m;

	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			mark[i]=false;
			scanf("%s%d%s",stu[i].id,&stu[i].score,stu[i].from);
			//scanf("%s",from_temp);
			for(j=0;j<strlen(stu[i].from);j++)
			{
				if(stu[i].from[j]>='A'&&stu[i].from[j]<='Z')
				{
					stu[i].from[j]+=32;
				}
			}	
		}
		int temp=0;
		k=0;//必须赋初值。 
		for(i=0;i<n;i++)//当n很大时会造成程序运行时间超时 
		{
			if(mark[i]==true)
			{
				continue;
			}
		/*	if(mark[i]==false)
			{
				mark[i]=true;
			}*/
			for(m=0;m<strlen(stu[i].from);m++)
			{
				sch[k].name[m]=stu[i].from[m];
			}
			for(j=i;j<n;j++)
			{
				if(mark[j]==false&&!strcmp(stu[j].from,stu[i].from))//char_cmp(stu[j].from,stu[i].from)
				{
					mark[j]=true;
					if(stu[j].id[0]=='T')
					{
						sch[k].total_score+=1.5*stu[j].score;
					}
					if(stu[j].id[0]=='A')
					{
						sch[k].total_score+=stu[j].score;
					}
					if(stu[j].id[0]=='B')
					{
						sch[k].total_score+=stu[j].score/1.5;
					}
					sch[k].stu_num++;
				}
				 
			}
			k++;
		}
		int total=k;
		sort(sch,sch+k,cmp2);
		for(int h=0;h<total;h++)
		{
			sch[h].rank=h+1;
		}
		for(i=0;i<total;i++)
		{
			for(j=i+1;j<total;j++)
			{
				if((int)sch[j].total_score==(int)sch[i].total_score) 
				{
					sch[j].rank=sch[i].rank;
				}				
			}
		}
	/*	for(i=0;i<n;i++)
		{
			printf("%s %d %s\n",stu[i].id,stu[i].score,stu[i].from);
		}*/
		
		printf("%d\n",total);
		for(i=0;i<total;i++)
		{
			printf("%d %s %d %d\n",sch[i].rank,sch[i].name,(int)sch[i].total_score,sch[i].stu_num);
		}
	}
	return 0;
}
