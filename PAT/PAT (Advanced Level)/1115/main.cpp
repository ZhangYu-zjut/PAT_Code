#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//思路： 
//首先，根据输入序列构建对应结构的二叉树 
//然后，对二叉树进行层次遍历，对每个节点赋值对应的层高 
//接着，找出最大的层高，并再次遍历树，找到最高层高和次高层高对应的节点数量；注意树的层高可能小于2 
//最后，将最后的结果进行输出。
//有两个测试点过不了！！！ 
struct node
{
	int data;
	int lawyer;
	node* left;
	node* right;
};
void insert(node* &root,int x)
{
	if(root==NULL)
	{
		root = new node;
		root->left=root->right=NULL;
		root->data=x;
		return;
	}
	else
	{
		if(x<root->data)insert(root->left,x);
		else insert(root->right,x);
	}
} 
int BFS(node* root)//返回最大的层高数值 
{
	int max_lawyer;
	int left_lawyer=0,right_lawyer=0;
	if(root==NULL)
	{
		max_lawyer=0;
		return max_lawyer;
	}
	else
	{
		queue<node*>q;
		root->lawyer=1;
		max_lawyer=1;
		q.push(root);
		while(!q.empty())
		{
			node* now=q.front();
			q.pop();
			if(now->left!=NULL)
			{
				now->left->lawyer=now->lawyer+1;
				left_lawyer=now->left->lawyer;
				q.push(now->left);
			}
			if(now->right!=NULL)
			{
				now->right->lawyer=now->lawyer+1;
				right_lawyer=now->right->lawyer;
				q.push(now->right);
			}
		}
	}
	if(right_lawyer==0&&left_lawyer==0)//只有一层的情况 
	{
		max_lawyer==1;
		return max_lawyer;
	} 
	right_lawyer>left_lawyer?max_lawyer=right_lawyer:max_lawyer=left_lawyer;
	return max_lawyer;
}
void search(node* root,int max_lawyer,vector<int>&vi)
{
	int a=0,b=0;//统计最深一层和次深一层的节点个数 
	vi.push_back(a);
	vi.push_back(b);
	if(max_lawyer==1)//只有一层的情况 
	{
		vi[0]=1;
		return;
	}
	if(root==NULL)return;
	else
	{
		if(root->lawyer==max_lawyer)
		{
			vi[0]++;
		}
		if(root->lawyer==max_lawyer-1)
		{
			vi[1]++;
		}
		search(root->left,max_lawyer,vi);
		search(root->right,max_lawyer,vi);
	}

}
int main(int argc, char** argv) {
	int n,j,i,k,temp;
	int a,b;
	scanf("%d",&n);
	node* root=NULL;
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		insert(root,temp);
	}
	int max_lawyer=BFS(root);
	printf("max lawyer is%d\n",max_lawyer); 
	vector<int>v;
	search(root,max_lawyer,v);
	if(max_lawyer==1)
	{
		printf("%d + %d = %d\n",v[0],0,v[0]);
	}
	else
	{
		printf("%d + %d = %d\n",v[0],v[1],v[0]+v[1]);
	}
	//printf("%d + %d = %d\n",v[0],v[1],v[0]+v[1]);
	return 0;
}
