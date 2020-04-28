#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//与前面的PAT1052,1032思路类似，用静态链表+排序实现
//AC!! 
struct node
{
	int addr;
	int data;
	int flag;
	int cnt;
	int next;
}N[100005];
map<int,int>ma;
const int inf = 100005;
bool cmp(node a,node b)
{
	if(a.flag!=b.flag)
	{
		return a.flag>b.flag;
	}
	else return a.cnt<b.cnt;
}
int main(int argc, char** argv) {
	int head,n;
	int i,j,k,a,b,c;
	scanf("%d%d",&head,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		N[a].addr=a;
		N[a].data=b;
		N[a].next=c;
	}
	for(i=0;i<inf;i++)
	{
		N[i].flag=-1;
	}
	int count1=0,count2=0;
	int s=head;
	while(s!=-1)
	{
		int abstemp = abs(N[s].data);
		ma[abstemp]++;
		if(ma[abstemp]>1)
		{
			N[s].flag=0;
			N[s].cnt=count2;
			count2++;
		}
		else
		{
			N[s].flag=inf-(count1);
			count1++;
		}
		s=N[s].next;
	}
	sort(N,N+inf,cmp);
	for(i=0;i<count1;i++)
	{
		if(i==count1-1)printf("%05d %d -1\n",N[i].addr,N[i].data);
		else printf("%05d %d %05d\n",N[i].addr,N[i].data,N[i+1].addr);
	}
	for(i=count1;i<count1+count2;i++)
	{
		if(i==count1+count2-1)printf("%05d %d -1\n",N[i].addr,N[i].data);
		else printf("%05d %d %05d\n",N[i].addr,N[i].data,N[i+1].addr);
	}
	return 0;
}
