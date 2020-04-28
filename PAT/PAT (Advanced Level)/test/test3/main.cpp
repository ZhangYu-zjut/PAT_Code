#include <iostream>
#include <vector>
#include <queue>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
vector<int>v[100];
int no_child[100]={0};//��¼ÿ���Ҷ�ӽڵ���� 
int level[100];//��¼ÿ���ڵ����ڵĲ��� 
int max_layer=1;//��¼���Ĳ��� 
void BFS(int root)
{
	queue<int>q;
	q.push(root);
	max_layer=1;
	level[root]=1;
	int i,j;
	if(v[root].size()==0)
	{
		no_child[max_layer]=1;
		return;
	}
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		if(v[now].size()!=0) 
		{
			for(i=0;i<v[now].size();i++)
			{
				level[v[now][i]]=level[now]+1;//��һ���ڵ�Ĳ���=��ǰ�ڵ�Ĳ���+1 
				if(level[v[now][i]]>max_layer)max_layer=level[v[now][i]];//���������� 
				if(v[v[now][i]].size()==0)//�ж��Ƿ�ΪҶ�ӽڵ� 
				{
					no_child[level[v[now][i]]]++;//�ǵĻ���û�б�Ҫ������� 
				}
				else//��Ҷ�ӽڵ����������� 
				{
					q.push(v[now][i]);
				}			
			}
		}
	}
}
char s[10]; 
int main(int argc, char** argv) {
	
	bool find=false;
	int n,m;
	int i,j;
	int no,k;
	int root,child;
	scanf("%d%d",&n,&m);
	if(n==0)return 0;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&no,&k);
		if(no==1)root=no;
		for(j=0;j<k;j++)
		{
			scanf("%d",&child);
			v[no].push_back(child);
		}
	}
	BFS(root);
	for(i=1;i<=max_layer;i++)
	{
		if(i==1)printf("%d",no_child[i]);
		else printf(" %d",no_child[i]);
	}
	return 0;
}
