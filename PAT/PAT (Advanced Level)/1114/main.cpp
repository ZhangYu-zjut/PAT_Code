#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//注意原始的数据中id可能为0，所有要给个初始的<0的值，并且把<0的过滤掉！！！
//用isroot来存储根节点，用cou[]存储根节点所在集合的节点个数
//用map<int,set<int>>mp;存放根节点和对应结合的节点下标
//用vector<person>ans存储最后的输出节点
//AC!!!!
struct person
{
	int id=-1;
	int fa;
	int mo;
	vector<int>child;
	int es;
	int area;
	double ave1;
	double ave2;
	int cnt;
}p[10003];
int n;
int father[10003];
bool isroot[10003];
int cou[10003];
vector<int>v;
vector<person>ans;
map<int,set<int>>mp;
int findfa(int x)
{
	while(x!=father[x])
	{
		x = father[x]; 
	} 
	return x;
}
void Union(int a,int b)
{
	int fa=findfa(a);
	int fb=findfa(b);
	if(fa!=fb)
	{
		father[fa]=fb;
	}
}

void init()
{
	for(int i=0;i<10000;i++)
	{
		father[i]=i;
	}
}
bool cmp(person a,person b)
{
	if(a.ave2!=b.ave2)
	{
		return a.ave2>b.ave2;
	}
	else return a.id<b.id;
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	int i,j,k,temp;
	init();
	int a,b,c,d,e,f;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&k);
		p[a].id=a;
		if(b!=-1)
		{
			p[b].id=b;
			p[a].fa=b;
			Union(a,b);
		}
		if(c!=-1)
		{
			p[c].id=c;
			p[a].mo=c;
			Union(a,c);	
		}
		for(j=0;j<k;j++)
		{
			scanf("%d",&temp);
			Union(a,temp);	
			p[temp].id=temp;
			p[a].child.push_back(temp);
		}
		scanf("%d%d",&e,&f);
		p[a].es=e;
		p[a].area=f;
	}
	int temp2;
	for(i=0;i<10000;i++)
	{
		if(p[i].id!=-1)
		{
			temp2=findfa(i);
			isroot[findfa(i)]=true; 
			cou[findfa(i)]++;
			{
				mp[temp2].insert(i);
			}
		} 
	}
	int ansp;
	set<int>::iterator sit;
	set<int>::iterator it;
	for(i=0;i<10000;i++)
	{
		if(isroot[i]==true)
		{
			sit=mp[i].begin();
			p[*sit].cnt=cou[i];
			for(it=mp[i].begin();it!=mp[i].end();it++)
			{
				if(it==mp[i].begin())continue;
				p[*sit].area+=p[*it].area;
				p[*sit].es+=p[*it].es;
			}
			p[*sit].ave1=1.0*p[*sit].es/p[*sit].cnt;
			p[*sit].ave2=1.0*p[*sit].area/p[*sit].cnt;
			ans.push_back(p[*sit]);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%04d %d %.3lf %.3lf\n",ans[i].id,ans[i].cnt,ans[i].ave1,ans[i].ave2);
	}
	return 0;
}
