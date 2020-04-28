#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//直接用cin,cout,string排序会导致一个测试点超时
//将cin,cout改为scanf，printf 并经string改为char[]，利用strcmp对char数组进行字典排序。可以通过超时的测试点
//AC！！！ 
struct person
{
	char name[10];
	int age;
	int wealth;
}p[100001];
bool cmp(person a,person b)
{
	if(a.wealth!=b.wealth)
	{
		return a.wealth>b.wealth;
	}
	else
	{
		if(a.age!=b.age)
		{
			return a.age<b.age;	
		}
		else
		{
			return strcmp(a.name,b.name)<0;//a.name<b.name;
		}
	}
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int i,j,m,n,k;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		//cin>>p[i].name>>p[i].age>>p[i].wealth;
		scanf("%s%d%d",p[i].name,&p[i].age,&p[i].wealth);
	}
	sort(p,p+n,cmp);
	for(i=0;i<k;i++)
	{
		int m;
		int a_min,a_max;
		scanf("%d%d%d",&m,&a_min,&a_max);
		int count=0;
		printf("Case #%d:\n",(i+1));
		for(j=0;j<n;j++)
		{
			if(p[j].age>=a_min&&p[j].age<=a_max&&count<m)
			{
				//cout<<p[j].name;
				printf("%s %d %d\n",p[j].name,p[j].age,p[j].wealth);
				count++;
			}
		}
		if(count==0)
		{
			printf("None\n");
		}
	}
	return 0;
}
