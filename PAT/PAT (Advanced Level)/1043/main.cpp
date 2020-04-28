#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//˼·��
//���ȣ�������������У���������Ӧ�ṹ�Ķ������������������б���������origin�� 
//Ȼ��������ڵ㣬����������Ľ�����������pre�� 
//���ţ�������ڵ㣬��������������Ľ�����������premirror��  
//���ߣ�������ڵ㣬����������;����������Ľ�������post��postmirro�� 
//��������������У����������зֱ�������pre������premirror�Ƚϣ�����ȣ����YES����������ȣ����NO 

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
//���ݸ��ڵ㣬���������д��������pre�С� 
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
