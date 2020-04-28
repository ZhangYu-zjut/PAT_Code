#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//使用两个堆栈进行处理，对将左右节点按照顺序放入堆栈s2中，
//然后在对s2遍历的过程中，按照右左节点的顺序将节点放到s1中
//每次输出时，均对计数器cnt+1，当cnt==n时，结束循环。
//AC!!!! 
int post[40],in[40];
struct node
{
	int data;
	node* left;
	node* right;
};
node* create(int ins,int inend,int posts,int postend)
{	
	node* root=new node();
	if(ins>inend)return NULL;
	else
	{
		int k;
		int data=post[postend];
		root->data=data;
		for(k=ins;k<inend;k++)
		{
			if(in[k]==data)
			{
				break;
			}
		}
		int numleft=k-ins;
		root->left=create(ins,k-1,posts,posts+numleft-1);
		root->right=create(k+1,inend,posts+numleft,postend-1);
	}
	return root;
} 
void ziglevel(node* root,int n)
{
	stack<node*>s1;
	stack<node*>s2;
	printf("%d",root->data);
	int cnt=1;
	if(root->right!=NULL)s1.push(root->right);
	if(root->left!=NULL)s1.push(root->left);
	while(cnt!=n)
	{
		while(!s1.empty())
		{
			node* now =s1.top();
			s1.pop();
			printf(" %d",now->data);
			if(now->left!=NULL)s2.push(now->left);
			if(now->right!=NULL)s2.push(now->right);
			cnt++;
		}
		while(!s2.empty())
		{
			node* now =s2.top();
			s2.pop();
			printf(" %d",now->data);
			if(now->right!=NULL)s1.push(now->right);
			if(now->left!=NULL)s1.push(now->left);
			cnt++;
		}
	}

}
//测试用的层次遍历，本题用不到！！ 
void level(node* root)
{
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node* now=q.front();
		q.pop();
		printf("%d ",now->data);
		if(now->left!=NULL)q.push(now->left);
		if(now->right!=NULL)q.push(now->right);
	}
}
int main(int argc, char** argv) {
	int n,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&post[i]);
	}
	node* root=NULL;
	root=create(0,n-1,0,n-1);	
	ziglevel(root,n);
	return 0;
}
