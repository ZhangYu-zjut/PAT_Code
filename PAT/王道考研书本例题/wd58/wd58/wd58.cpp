// wd58.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
int gsize;
char str1[25], str2[25],str3[25];
int size1, size2;
char *str;//指向当前的字符串
int *temp_size;//当前保存的字符串长度

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
}

node* insert(node* root, int x)
{
	if (root == NULL)
	{
		root = creat();
		root->num = x;//这句话不能忘掉！！！！
		return root;
	}
	else if (x < root->num)
	{
		root->left = insert(root->left,x);
	}
	else if (x > root->num)
	{
		root->right = insert(root->right, x);
	}
	return root;
}

void inorder(node* root)
{	
	if (root->left != NULL)
	{
		inorder(root->left);
	}
	str[(*temp_size)++] = root->num + '0';
	if (root->right != NULL)
	{
		inorder(root->right);
	}
}

void preorder(node* root)
{
	str[(*temp_size)++] = root->num+'0';
	if (root->left != NULL)
	{
		preorder(root->left);
	}
	if (root->right != NULL)
	{
		preorder(root->right);
	}
}

int main()
{
	freopen("test.txt","r",stdin);
	int i, j, n;
	while (scanf("%d",&n)!=EOF && n!=0)
	{
		gsize = 0;
		scanf("%s", str3);
		node* t = NULL;
		for (i = 0;str3[i] != 0;i++)
		{
			t = insert(t,str3[i] - '0');
			
		}
		size1 = 0;
		str = str1;
		temp_size = &size1;
		preorder(t);
		inorder(t);
		str1[size1] = 0;
		while (n--)
		{
			scanf("%s", str3);
			node* t2 = NULL;
			for (i = 0;str3[i] != 0;i++)
			{
				t2 = insert(t2, str3[i]-'0');
			}
			size2 = 0;
			str = str2;
			temp_size = &size2;
			preorder(t2);
			inorder(t2);
			str[size2] = 0;
			//读取一个字符串
			//比较两者差异。如何保存字符串？？？
			if (strcmp(str1, str2) == 0)
			{
				printf("Yes");
			}
			
			else
			{
				printf("No");
			}

			printf("\n");
		}
		//strcmp(str1, str2) == 0 ? printf("Yes"): printf("No");
	}
    return 0;
}

