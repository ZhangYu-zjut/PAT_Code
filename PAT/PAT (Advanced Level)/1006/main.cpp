#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AC!!!!
struct person
{
	char name[100];
	int in_hour;
	int in_min;
	int in_sec;
	int out_hour;
	int out_min;
	int out_sec;	
}p[1000];
bool cmp1(person a,person b)
{
	if(a.in_hour!=b.in_hour)
	{
		return a.in_hour<b.in_hour;
	}
	else
	{
		if(a.in_min!=b.in_min)
		{
			return a.in_min<b.in_min;
		}
		else
		{
			return a.in_sec<b.in_sec;
		}
	}
}
bool cmp2(person a,person b)
{
	if(a.out_hour!=b.out_hour)
	{
		return a.out_hour>b.out_hour;
	}
	else
	{
		if(a.out_min!=b.out_min)
		{
			return a.out_min>b.out_min;
		}
		else
		{
			return a.out_sec>b.out_sec;
		}
	}
}
int main(int argc, char** argv) {
	char ch1[100],ch2[100],ch3[100];
	int n,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s %d:%d:%d %d:%d:%d",p[i].name,&p[i].in_hour,&p[i].in_min,&p[i].in_sec,&p[i].out_hour,&p[i].out_min,&p[i].out_sec);
	}
	sort(p,p+n,cmp1);
	printf("%s",p[0].name);
	sort(p,p+n,cmp2);
	printf(" %s",p[0].name);
	printf("\n");
	return 0;
}
