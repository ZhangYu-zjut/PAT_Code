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
	return &tree[gsize];
	gsize++;
}
node* insert(node* t,int x) 
{
	if (t ==NULL)
	{
		node* t = creat();
		t->num = x;
		return t;
	}
	else if (x < t->num)
	{
		t->left = insert(t->left,x);
	}
	else if (x > t->num)
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
	printf("%d",head->num);
	if (head->right != NULL)
	{
		inorder(head->right);
	}
}
void postorder(node* head)
{
	if (head->left != NULL)
	{
		inorder(head->left);
	}
	if (head->right != NULL)
	{
		inorder(head->right);
	}
	printf("%d", head->num);
}
void prenorder(node* head)
{
	printf("%d", head->num);
	if (head->left != NULL)
	{
		inorder(head->left);
	}
	
	if (head->right != NULL)
	{
		inorder(head->right);
	}
}

int main()
{
	freopen("test.txt","r",stdin);
	int n, i, j;
	while (scanf("%d",&n)!=EOF)
	{
		gsize = 0;
		node* t = NULL;
		for (i=0;i<n;i++)
		{
			int x;
			scanf("%d", &x);
			insert(t,x);
		}
		prenorder(t);
		printf("\n");
		inorder(t);
		printf("\n");
		postorder(t);
		printf("\n");
	}
    return 0;
}

