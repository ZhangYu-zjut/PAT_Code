#include <iostream>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//根据前序和中序序列构造二叉树，简单题AC!!!! 
struct node
{
	int data;
	node* left;
	node* right;
};
int pre[50004],in[50004];
int count=0;
node* create(int ins,int inend,int pres,int preend)
{
	int k;
	if(ins>inend)return NULL;
	node* root=new node;
	root->data=pre[pres];
	for(k=ins;k<=inend;k++)
	{
		if(in[k]==pre[pres])
		break;
	}
	int numleft=k-ins;
	root->left=create(ins,k-1,pres+1,pres+numleft);
	root->right=create(k+1,inend,pres+numleft+1,preend);
	return root;
}
void post(node* root)
{
	if(root==NULL)return;
	if(root->left!=NULL)post(root->left);
	if(root->right!=NULL)post(root->right);
	if(count==0)
	{
		printf("%d",root->data);
		count++;
	}
}
int main(int argc, char** argv) {
	int n,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
	}
	node* root=NULL;
	root=create(0,n-1,0,n-1);
	post(root);
	return 0;
}
