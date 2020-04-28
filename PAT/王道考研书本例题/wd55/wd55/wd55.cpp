// wd55.cpp : �������̨Ӧ�ó������ڵ㡣
//

// wd51.cpp : �������̨Ӧ�ó������ڵ㡣
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
node* insert(node* t, int x)//������������в���ֵΪx�Ľڵ㣬��x��t�ڵ��ֵ���бȽϣ������ظ��ڵ�
{
	if (t == NULL)//���ڵ�Ϊ�գ��ݹ����������Ҫ�����λ�á�
	{
		node* t = creat();
		t->num = x;
		return t;
	}
	else if (x < t->num)//xС��num�����ڵ������ڵ�����
	{
		t->left = insert(t->left, x);//�µĽڵ�Ҫ�嵽��ǰ�ڵ����ߣ�����x��t�ڵ���ߵ�ֵ���Ƚ�
	}
	else if (x > t->num)//x����num�����ڵ������ڵ���ұ�
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
			t=insert(t, x);//important�����ڵ��ȥ��ÿ�ζ����ظ��ڵ�
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

