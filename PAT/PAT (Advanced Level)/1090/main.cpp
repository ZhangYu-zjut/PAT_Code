#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//���һ�����������Ⱥͺ��������ȵ�Ҷ�Ӹ�����˼·��
//����BFS��˼�룬��������vector v�洢ÿ����Ӧ������Ŀͻ���������lawyer����洢ÿ���ڵ�Ĳ��� 
//���ò�α�������ÿ���ڵ���б�����������Ӧ�Ĳ�������lawyer������ 
//��lawyer������н������򣬵�һ��ֵ���ǲ�����ߵ�ֵ��ͬʱ�Ը�������б������ҵ�������ߵĽڵ������
//�Խ�����д��������� 
//AC!!!!
vector<int>v[100001];
int lawyer[100001];
void BFS(int root)
{
	queue<int>q;
	if(v[root].size()==0)return;
	else
	{
		q.push(root);
		lawyer[root]=0;
		while(!q.empty())
		{
			int now= q.front();
			q.pop();
			for(int i=0;i<v[now].size();i++)
			{
				lawyer[v[now][i]]=lawyer[now]+1;
				q.push(v[now][i]);
			}	
		}
	}
}
bool cmp(int a,int b)
{
	return a>b;
}
int main(int argc, char** argv) {
	int n,i,j,k,temp,root;
	double price,inc;
	scanf("%d%lf%lf",&n,&price,&inc);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(temp==-1)root=i;
		else v[temp].push_back(i);
	}
	BFS(root);
	sort(lawyer,lawyer+n,cmp);
	int max_lawyer=lawyer[0];
	int cnt=0;
	for(i=0;i<n;i++)
	{
		if(lawyer[i]==max_lawyer)
		{
			cnt++;
		}
	}
	printf("%.2lf %d\n",price*pow((1.0+inc/100),max_lawyer*1.0),cnt);
	return 0;
}
