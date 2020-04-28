// wd55.cpp : 定义控制台应用程序的入口点。
//

// wd51.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>

#include<algorithm>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int gsize;
struct node
{
	node* left;
	node* right;
	int num;
}tree[100];

node* creat()
{
	tree[gsize].left = NULL;
	tree[gsize].right = NULL;
	return &tree[gsize++];
	//gsize++;
}
node* insert(node* t, int x)//向二叉搜索树中插入值为x的节点，将x与t节点的值进行比较，并返回根节点
{
	if (t == NULL)//当节点为空，递归结束，就是要插入的位置。
	{
		node* t = creat();
		t->num = x;
		return t;
	}
	else if (x < t->num)//x小于num，将节点插入跟节点的左边
	{
		t->left = insert(t->left, x);//新的节点要插到当前节点的左边，并把x与t节点左边的值作比较
	}
	else if (x > t->num)//x大于num，将节点插入跟节点的右边
	{
		t->right = insert(t->right, x);
	}
	return t;
}

void inorder(node* head)
{
	if (head->left != NULL)
	{
		inorder(head->left);
	}
	printf("%d ", head->num);
	if (head->right != NULL)
	{
		inorder(head->right);
	}
}
void postorder(node* head)
{
	if (head->left != NULL)
	{
		postorder(head->left);
	}
	if (head->right != NULL)
	{
		postorder(head->right);
	}
	printf("%d ", head->num);
}
void preorder(node* head)
{
	printf("%d ", head->num);
	if (head->left != NULL)
	{
		preorder(head->left);
	}

	if (head->right != NULL)
	{
		preorder(head->right);
	}
}

int main()
{
	freopen("test.txt", "r", stdin);
	int n, i, j;
	while (scanf("%d", &n) != EOF)
	{
		gsize = 0;
		node* t = NULL;
		for (i = 0;i<n;i++)
		{
			int x;
			scanf("%d", &x);
			t=insert(t, x);//important，根节点进去，每次都返回根节点
		}
		preorder(t);
		printf("\n");
		inorder(t);
		printf("\n");
		postorder(t);
		printf("\n");
	}
	return 0;
}

