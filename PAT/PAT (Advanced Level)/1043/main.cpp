#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//思路：
//首先，根据输入的序列，构建出对应结构的二叉树，并将输入序列保存在向量origin中 
//然后，输入根节点，将先序遍历的结果存放在向量pre中 
//接着，输入根节点，将镜像先序遍历的结果存放在向量premirror中  
//再者，输入根节点，将后序遍历和镜像后序遍历的结果存放在post，postmirro中 
//最后，输入输入序列，将输入序列分别与向量pre，向量premirror比较，若相等，输出YES；若都不相等，输出NO 

struct node
{
	int data;
	node* left;
	node* right;
};
vector <int>pre,premirror,post,post_mirror; 
void insert(node* &root,int x)
{
	if(NULL==root)
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
//根据根节点，将先序序列存放在向量pre中。 
void pre_seq(node* root,vector<int> &pre)
{
	if(root==NULL)return;
	else
	{
		pre.push_back(root->data);
		pre_seq(root->left,pre);
		pre_seq(root->right,pre);
	}
}
void premirror_seq(node* root,vector<int> &premirror)
{
	if(root==NULL)return;
	else
	{
		premirror.push_back(root->data);
		premirror_seq(root->right,premirror);
		premirror_seq(root->left,premirror);
	}
}
void post_seq(node* root,vector<int> &post)
{
	if(root==NULL)return;
	else
	{
		post_seq(root->left,post);
		post_seq(root->right,post);
		post.push_back(root->data);
	}
} 
void postmirror_seq(node* root,vector<int> &post_mirror)
{
	if(root==NULL)return;
	else
	{
		postmirror_seq(root->right,post_mirror);
		postmirror_seq(root->left,post_mirror);
		post_mirror.push_back(root->data);
	}
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n,temp;
	scanf("%d",&n);
	vector<int>origin;
	node* root=NULL;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		origin.push_back(temp);
		insert(root,origin[i]);
	}
	pre_seq(root,pre);
	premirror_seq(root,premirror);
	if(origin==pre)
	{
		printf("YES\n");
		post_seq(root,post);
		for(int j=0;j<post.size();j++)
		{
			if(j==0)printf("%d",post[j]);
			else
			{
				printf(" %d",post[j]);
			}
		} 
	}
	else if(origin==premirror)
	{
		printf("YES\n");
		postmirror_seq(root,post_mirror);
		for(int j=0;j<post_mirror.size();j++)
		{
			if(j==0)printf("%d",post_mirror[j]);
			else
			{
				printf(" %d",post_mirror[j]);
			}
		} 
	}
	else 
	{
		printf("No\n");
	}
	return 0;
}
