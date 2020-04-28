#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AC!!!
struct person
{
	int id;
	int v_grade;
	int t_grade;
	int total;
	int kind;
}p[100001];
bool cmp(person a,person b)
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
			if(a.v_grade!=b.v_grade)
			{
				return a.v_grade>b.v_grade; 
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
	int i,j,k,n,m;
	int low,high;
	scanf("%d%d%d",&n,&low,&high);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&p[i].id,&p[i].v_grade,&p[i].t_grade);
		p[i].total=p[i].v_grade+p[i].t_grade;
		if(p[i].v_grade>=high&&p[i].t_grade>=high)
		{
			p[i].kind=1;
		}
		if(p[i].v_grade>=high&&p[i].t_grade<high&&p[i].t_grade>=low)
		{
			p[i].kind=2;
		}
		if(p[i].v_grade>=low&&p[i].v_grade<high&&p[i].t_grade>=low&&p[i].t_grade<high&&p[i].v_grade>=p[i].t_grade)
		{
			p[i].kind=3;
		}
		if(p[i].v_grade>=low&&p[i].v_grade<high&&p[i].t_grade>=low&&p[i].v_grade<p[i].t_grade)//注意天赋分可以很高 
		{
			p[i].kind=4;
		}
		if(p[i].v_grade<low||p[i].t_grade<low)
		{
			p[i].kind=5;
		}
	}
	sort(p,p+n,cmp);
	int count=0;
	for(i=0;i<n;i++)
	{
		if(p[i].kind<=4)
		{
			count++;
		} 
	}
	printf("%d\n",count);
	for(i=0;i<count;i++)
	{
		printf("%d %d %d\n",p[i].id,p[i].v_grade,p[i].t_grade);
	}
	return 0;
}
