#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//根据中序和后序序列确定树的结构.
//思想：采用递归的形式，找到中序和后序序列中的根节点，每次不断更新根节点所指向的子树。 
//输入：中序数组、后序数组
//输出：能表现树结构的根节点 
#define maxx 200
int in[maxx],post[maxx];
struct node
{
	int data;
	node* left;
	node* right;
}; 
node* create(int inl,int inr,int postl,int postr)//根据中序序列的区间和后序序列的区间确定树的结构（新建节点） 
{
	if(inl>inr)
	{
		return NULL;
	}
	node* root=new node;
	root->data=post[postr];//这两家不能忘记！！ 
	int data=post[psotr];//后序序列的最后一个数就是根节点的值
	for(int k=inl;k<=inr;k++)//在中序序列中找到对应值的位置 
	{
		if(in[k]==post[postr])
		{
			break;
		}
	} 
	int numleft=k-inl;//记录根节点左边的数据有多少个 
	root->left=(inl,inl+numleft-1,postl,postl+numleft-1);//inl+numleft-1
	root->right=(k+1,inr,postl+numleft,postr-1);
	return root;
}
int main(int argc, char** argv) {
	
	return 0;
}
