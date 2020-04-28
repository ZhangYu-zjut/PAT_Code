#include <iostream>
#include <stdio.h>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//有一个地方没有通过测试，段错误、！！ 
struct person
{
	int id;
	int weight;
	int count=0;
	int rank;
	int order;
}p[10003];
map<int,int>mp;
queue<person>q;
int num[10003];
int order[10003];
bool cmp1(person a,person b)
{
	return a.order<b.order;
}
bool cmp2(person a,person b)
{
	return a.count>b.count;
}
bool cmp3(person a,person b)
{
	return a.id<b.id;
}

int main(int argc, char** argv) {
	int rand;
	printf("rnadom is%d\n",rand); 
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		p[i].weight=num[i];
		p[i].id=i;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&order[i]);
		p[i].order=order[i];
	}
	//sort(p,p+n,cmp1);//因为这里排序过，所以后面的p[index].count++不是对原来顺序的数组进行操作，会出现错误！ 
	for(i=0;i<n;i++)
	{
		q.push(p[order[i]]);
	}
	int turn=n/m;
	int group=m;
	while(q.size()>1)
	{
		int total=q.size();
		int size;
		if(total%m==0)size=total/m;
		else size=total/m+1; 
		for(i=0;i<size;i++)//循环size轮 
		{
			int max=-1;
			int index;
			int left=total-(i)*m;//这个地方不要写错！！ 
			person ptemp;
			person maxp;
			if(left>=3)
			{
				for(j=0;j<m;j++)//每一组m个人 
				{
					ptemp=q.front();
					q.pop();
					if(ptemp.weight>max)
					{
						max=ptemp.weight;
						index=ptemp.id;
					}
				}
			}
			else
			{
				for(j=0;j<left;j++)
				{
					ptemp=q.front();
					q.pop();
					if(ptemp.weight>max)
					{
						max=ptemp.weight;
						index=ptemp.id;
					}
				}
			}
			p[index].count++;
			q.push(p[index]);
		}
	}
	sort(p,p+n,cmp2);
	p[0].rank=1;
	mp[p[0].weight]=1;
	for(i=1;i<n;i++)
	{
		if(p[i].count==p[i-1].count)
		{
			p[i].rank=p[i-1].rank;
			mp[p[i].weight]=p[i].rank;
		}
		else
		{
			p[i].rank=i+1;
			mp[p[i].weight]=p[i].rank;
		}
	}
	for(i=0;i<n;i++)
	{
		if(i==0)printf("%d",mp[num[i]]);
		else printf(" %d",mp[num[i]]);
	}
	return 0;
}
