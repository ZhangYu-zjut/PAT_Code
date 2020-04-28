#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//二叉搜索树的建立过程：
//插入节点函数 
//建立函数 
//搜索函数 
//输出函数
//删除函数，删除以root为根的树中节点值为x的节点，注意要递归删除 
struct node
{
	int data;
	node* left;
	node* right;
}; 
node* newnode(int x)//新建一个节点，节点的左右子节点为空，节点值为x 
{
	node* root=new node;
	root->left=root->right=NULL;
	root->data=x;
	return root;
}
void insert(node* &root,int x)//向树中插入值为x的数据。在树中一直查找，直到找到为空的节点，进行新建节点。 
//由于根节点指向的数据不断变化，所以要传入及指针的引用。  
{
	if(root==NULL)
	{
		root=newnode(x);
		return;
	}
	if(x<root->data)
	{
		insert(root->left,x);
	}
	else
	{
		insert(root->right,x);
	}
}
int num[1000];
node* create(int data[],int n)//建立树，建树的过程本质上是往根节点不断地插入数据。
{
	node* root=NULL;//因为插入的时候需要根节点，所以首先创建一个节点。当插入完成后，root就是更新完之后的节点。 
	for(int i=0;i<n;i++)
	{
		insert(root,data[i]);
	}
	return root;
}
void show(node* root)//按照中序输出树的数据 
{
	if(root==NULL)
	{
		return;
	} 
	else
	{
		show(root->left);
		printf("%d ",root->data);
		show(root->right);
	}
}
void lawyer(node* root)//对一颗已经建立好的树进行层次遍历输出节点值。 
{
	queue<node*>q;
	if(root==NULL)
	{
		return;
	}
	else
	{
		q.push(root);
		while(!q.empty())
		{
			node* now=q.front();
			q.pop();
			printf("%d ",now->data);
			if(now->left!=NULL)
			{
				q.push(now->left);
			}
			if(now->right!=NULL)
			{
				q.push(now->right);
			}
		}
	}
}
//找到前驱节点和后继节点
node* findMax(node* root)
{
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root;
} 
node* findMin(node* root)
{
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}
//删除函数，删除以root为根的树中节点值为x的节点，注意要递归删除 
void deleteNode(node* &root,int x)
{
	if(root==NULL)
	{
		return;
	}
	if(root->data==x)
	{
		//是叶子节点，直接删除 
		if(root->left==NULL&&root->right==NULL)
		{
			root=NULL;
		}
		//左子树不为空，找到左子树的前驱节点，将前驱节点的值覆盖当前节点的值，并对前驱节点进行递归删除 
		else if(root->left!=NULL)
		{
			node* pre=findMax(root->left);//左子树的最大节点，即为前驱节点 
			root->data=pre->data;
			deleteNode(root->left,pre->data);//将当前节点变为左子树的节点，然后删除pre->data对应的节点 
		}
		//右子树不为空，找到右子树的后继节点，将后继节点的值覆盖当前节点的值，并对后继节点进行递归删除 
		else
		{
			node* post=findMin(root->right);
			root->data=post->data;
			deleteNode(root->right,post->data);
		}
	}
	else if(x<root->data)
	{
		deleteNode(root->left,x);
	}
	else
	{
		deleteNode(root->right,x);
	}
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	} 
	node* root=NULL;
	root=create(num,n);
	show(root);
	printf("\n层次遍历的结果为：\n");
	lawyer(root);
	//将根节点的10删除后，查看层次遍历的结果 
	deleteNode(root,10);
	printf("\n删除根节点后，层次遍历的结果为：\n");
	lawyer(root);
	return 0;
}
