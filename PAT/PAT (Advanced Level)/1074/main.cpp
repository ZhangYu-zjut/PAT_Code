#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//刚开始的时候没有注意到group初始化为0,导致两个测试用例过不了，如果group从小到大（0开始）排序，则要将初始的group赋值为inf 
//AC!!
struct node
{
	int addr;
	int data;
	int next;
	int flag;
	int group;
	int third;
}N[100005];
const int inf=100005;
bool cmp(node a,node b)
{
	if(a.group!=b.group)return a.group<b.group;
	else 
	{
		if(a.flag!=b.flag)
		{
			return a.flag>b.flag;
		}
		else return a.third<b.third;
	}
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int head,n;
	int i,j,k,a,b,c;
	scanf("%d%d%d",&head,&n,&k);
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
		N[i].group=inf;
	}
	int count=0;
	int s=head;
	
	while(s!=-1)
	{
		count++;
		N[s].flag=1;
		N[s].third=count;
		s=N[s].next;
	}
	if(k==1)
	{
		s=head;
		int temp=0;
		while(s!=-1)
		{
			if(temp!=count-1)printf("%05d %d %05d\n",N[s].addr,N[s].data,N[s].next);
			else printf("%05d %d -1\n",N[s].addr,N[s].data);
			s=N[s].next;
			temp++;
		}
		return 0;
	}
	s=head;
	int count1=count+1;
	int group=0;
	for(i=0;i<count/k;i++)
	{
		count1=count+1;
		for(j=0;j<k;j++)
		{
			N[s].flag=count1;
			N[s].group=group;
			count1++;
			s=N[s].next;
		}
		group++;
	}
	sort(N,N+inf,cmp);
	for(i=0;i<count;i++)
	{
		if(i!=count-1)printf("%05d %d %05d\n",N[i].addr,N[i].data,N[i+1].addr);
		else printf("%05d %d -1\n",N[i].addr,N[i].data);
	}
	return 0;
}
