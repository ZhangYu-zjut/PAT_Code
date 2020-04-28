#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define maxn 1000
int point[2010]={0},edge[2010][2010]={0};//存储边和点的权值 
bool vis[2010]={false};//记录某个点是否被访问过 
int pointnum=0,num;
map<string,int> str2int;
map<int,string> int2str;
map<string,int> head_num; 
int change(string str)//输入字符串str，返回对应的编号 
{
	map<string,int>::iterator it=str2int.begin();
	if(str2int.find(str)!=str2int.end())//说明原来的map中存在对应的字符串 
	{
		return str2int[str];
	}
	else//说明原来的map中不存在对应的字符串 
	{
		str2int[str]=pointnum;
		int2str[pointnum]=str;
	}
	return pointnum++;
}
void DFS(int u,int &head,int &pnum,int &totalvalue)//寻找头节点、计算集合人数，计算总权重 
{
	pnum++;
	vis[u]=true;
	if(point[u]>point[head])
	{
		head=u;
	}
	for(int i=0;i<pointnum;i++)
	{
		if(edge[u][i]>0)
		{
			totalvalue+=edge[u][i];
			edge[u][i]=edge[i][u]=0;
			if(vis[i]==false)
			{
				DFS(i,head,pnum,totalvalue);	
			}
		}
	}
}
void DFStravel(int gate)
{
	for(int i=0;i<pointnum;i++)
	{
		if(vis[i]==false)
		{
			int head=i,pnum=0,totalvalue=0;
			DFS(i,head,pnum,totalvalue); 
			if(pnum>2&&totalvalue>gate)
			{
				head_num[int2str[head]]=pnum;//进行存储 
			}
		}
		/*
		if(vis[i]==false)
		{
			int head=i,pnum=0,totalvalue=0;
			DFS(i,head,pnum,totalvalue); 
		}*/
		
	}
}
int main(int argc, char** argv) {
	int n,k;
	cin>>n>>k;
	int i,j;
	string a,b;
	int temp;
	for(i=0;i<n;i++)
	{
		cin>>a>>b>>temp;
		int id1=change(a);
		int id2=change(b);
		point[id1]+=temp;
		point[id2]+=temp;
		edge[id1][id2]+=temp;//原本是=； 
		edge[id2][id1]+=temp;		
	}
	DFStravel(k);
	cout<<head_num.size()<<endl;
	for(map<string,int>::iterator it=head_num.begin();it!=head_num.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;	
	}
	return 0;
}
