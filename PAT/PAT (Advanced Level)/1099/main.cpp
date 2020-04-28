#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//简单的30分题目，AC!! 
struct node
{
	int data;
	int left;
	int right;
}N[102];
int num[102];
int t=0,cnt=0;
void level(int root)
{
	queue<int>q;
	q.push(root);
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		if(cnt==0)
		{
			printf("%d",N[temp].data);
			cnt++;
		}
		else printf(" %d",N[temp].data);
		if(N[temp].left!=-1)q.push(N[temp].left);
		if(N[temp].right!=-1)q.push(N[temp].right);
	}
}

void in(int root)
{
	if(root==-1)return;
	in(N[root].left);
	N[root].data=num[t++];
	in(N[root].right);
}
int main(int argc, char** argv) {
	int n;
	int root;
	int i,j,k,a,b;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		N[i].left=a;
		N[i].right=b;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	root=0;
	in(root);
	level(root);

	return 0;
}
