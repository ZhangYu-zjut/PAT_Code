#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node
{
	int data;
	int left;
	int right;
}Node[110];
set<int>s;
int n;
int g=0;
void levelorder(int root)
{
	int i=0;
	queue<int>q;
	q.push(root);
	while(!q.empty())
	{
		int now=q.front();
		if(i==0)
		{
			printf("%d",Node[now].data);i++;
		}
		else printf(" %d",Node[now].data);
		q.pop();
		if(Node[now].right!=100)q.push(Node[now].right);
		if(Node[now].left!=100)q.push(Node[now].left);
	}
}
void inorder(int root)
{
	if(root==100)return;
	inorder(Node[root].right);
	if(g==0)
	{
		printf("%d",Node[root].data);g++;
	}
	else printf(" %d",Node[root].data);
	inorder(Node[root].left); 
}
int main(int argc, char** argv) {
	int n,i,j,k;
	scanf("%d",&n);
	char a[5],b[5];
	for(i=0;i<n;i++)
	{
		scanf("%s%s",a,b);
		Node[i].data=i;
		if(a[0]=='-')Node[i].left=100;
		else 
		{
			Node[i].left=a[0]-'0';
			s.insert(a[0]-'0');
		}
		if(b[0]=='-')Node[i].right=100;
		else 
		{
			Node[i].right=b[0]-'0';
			s.insert(b[0]-'0');
		}
	}
	if(n==1)//只有一个根节点时特殊考虑 
	{
		printf("%d\n",0);
		printf("%d\n",0);
		return 0;
	}
	int root;
	j=0;
	for(set<int>::iterator it=s.begin();it!=s.end();it++)
	{
		if(*it==j)j++;
		else root=j;
	}
	levelorder(root);
	printf("\n");
	inorder(root);
	return 0;
}
