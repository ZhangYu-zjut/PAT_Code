#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�ж�һ�����Ƿ�Ϊ��ȫ��������ֻ��Ҫ��ĳ���ڵ���ֿյĶ��ӽڵ���ٲ鿴�Ƿ������µĽڵ�����˶��ӽڵ㣬
//���У�������ȫ��������ͬʱ����level����ǰ�������һ���ڵ����ż��ɣ��Ҹ��ڵ�Ϊ�ճ�������
//���� AC!!! 
struct node
{
	int data;
	int left;
	int right;
}N[30];
bool vis[30];
int last;
int count=0;
bool level(int root)
{
	queue<int>q;
	q.push(root);
	bool find=false;
	int temp; 
	while(!q.empty())
	{
		temp=q.front();
		q.pop();	
		if(N[temp].left!=-1)
		{
			if(find)
			{
				return false;
			}
			else
			{
				q.push(N[temp].left);
			}
		}
		else
		{
			find=true;
		}
		if(N[temp].right!=-1)
		{
			if(find)
			{
				return false;
			}
			else
			{
				q.push(N[temp].right);
			}
		}
		else
		{
			find=true;
		}
		if(q.size()==0)
		{
			last=temp;
		}
	}
	return true;
}
int main(int argc, char** argv) {
	int n,i,j,k;
	string a,b;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		if(a[0]=='-')
		{
			N[i].left=-1;
		}
		else
		{
			N[i].left=atoi(a.c_str());
			vis[atoi(a.c_str())]=true;
		}
		if(b[0]=='-')
		{
			N[i].right=-1;
		}
		else
		{
			N[i].right=atoi(b.c_str());
			vis[atoi(b.c_str())]=true;
		}
	}
	int root=0;
	for(i=0;i<n;i++)
	{
		if(vis[i]==false)
		{
			root=i;
			break;
		}
	}
	bool ans;
	ans=level(root);
	if(ans)
	{
		printf("YES %d",last);
	}
	else
	{
		printf("NO %d",root);
	}
	return 0;
}
