#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define maxn 1000
int point[2010]={0},edge[2010][2010]={0};//�洢�ߺ͵��Ȩֵ 
bool vis[2010]={false};//��¼ĳ�����Ƿ񱻷��ʹ� 
int pointnum=0,num;
map<string,int> str2int;
map<int,string> int2str;
map<string,int> head_num; 
int change(string str)//�����ַ���str�����ض�Ӧ�ı�� 
{
	map<string,int>::iterator it=str2int.begin();
	if(str2int.find(str)!=str2int.end())//˵��ԭ����map�д��ڶ�Ӧ���ַ��� 
	{
		return str2int[str];
	}
	else//˵��ԭ����map�в����ڶ�Ӧ���ַ��� 
	{
		str2int[str]=pointnum;
		int2str[pointnum]=str;
	}
	return pointnum++;
}
void DFS(int u,int &head,int &pnum,int &totalvalue)//Ѱ��ͷ�ڵ㡢���㼯��������������Ȩ�� 
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
				head_num[int2str[head]]=pnum;//���д洢 
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
		edge[id1][id2]+=temp;//ԭ����=�� 
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
