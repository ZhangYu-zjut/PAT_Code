#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//pa_B 1015 德才论 （25 分）AC!!!
struct student
{
	int id;
	int de;
	int cai;
	int total=0;
	int kind;
}stu[100010];
bool cmp(student a,student b)
{
	if(a.kind!=b.kind)
	{
		return a.kind<b.kind;
	} 
	else
	{
		if(a.total!=b.total)
		{
			return a.total>b.total;	
		}
		else
		{
			if(a.de!=b.de)
			{
				return a.de>b.de;
			}
			else
			{
				return a.id<b.id;
			}
		}
	}
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n,low_sco,high_sco;
	int i,j,k;
	while(scanf("%d%d%d",&n,&low_sco,&high_sco)!=EOF)
	{
		int count=0;
		for(i=0;i<n;i++) 
		{
			scanf("%d%d%d",&stu[i].id,&stu[i].de,&stu[i].cai);
			if(stu[i].de>=high_sco&&stu[i].cai>=high_sco)
			{
				stu[i].kind=1;
				count++;
			}
			if(stu[i].de>=high_sco&&stu[i].cai<high_sco&&stu[i].cai>=low_sco)
			{
				stu[i].kind=2;
				count++;
			}
			if(stu[i].de<high_sco&&stu[i].cai<high_sco&&stu[i].de>=stu[i].cai&&stu[i].de>=low_sco&&stu[i].cai>=low_sco)
			{
				stu[i].kind=3;
				count++;
			}
			if((stu[i].de<high_sco&&stu[i].cai<high_sco&&stu[i].de<stu[i].cai&&stu[i].de>=low_sco&&stu[i].cai>=low_sco)||(stu[i].de<high_sco&&stu[i].de>=low_sco&&stu[i].de<stu[i].cai))
			{//满足德分小于优先线且德分小于才分即可 
				stu[i].kind=4;
				count++;
			}
			if(stu[i].de<low_sco||stu[i].cai<low_sco)
			{
				stu[i].kind=5;
			}
			stu[i].total=stu[i].de+stu[i].cai;
			
		}
		sort(stu,stu+n,cmp);
		printf("%d\n",count);
		for(i=0;i<count;i++) 
		{
			printf("%d %d %d\n",stu[i].id,stu[i].de,stu[i].cai);
		}
	}
	return 0;
}
