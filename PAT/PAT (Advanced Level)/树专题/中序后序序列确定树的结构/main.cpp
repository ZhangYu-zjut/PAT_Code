#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//��������ͺ�������ȷ�����Ľṹ.
//˼�룺���õݹ����ʽ���ҵ�����ͺ��������еĸ��ڵ㣬ÿ�β��ϸ��¸��ڵ���ָ��������� 
//���룺�������顢��������
//������ܱ������ṹ�ĸ��ڵ� 
#define maxx 200
int in[maxx],post[maxx];
struct node
{
	int data;
	node* left;
	node* right;
}; 
node* create(int inl,int inr,int postl,int postr)//�����������е�����ͺ������е�����ȷ�����Ľṹ���½��ڵ㣩 
{
	if(inl>inr)
	{
		return NULL;
	}
	node* root=new node;
	root->data=post[postr];//�����Ҳ������ǣ��� 
	int data=post[psotr];//�������е����һ�������Ǹ��ڵ��ֵ
	for(int k=inl;k<=inr;k++)//�������������ҵ���Ӧֵ��λ�� 
	{
		if(in[k]==post[postr])
		{
			break;
		}
	} 
	int numleft=k-inl;//��¼���ڵ���ߵ������ж��ٸ� 
	root->left=(inl,inl+numleft-1,postl,postl+numleft-1);//inl+numleft-1
	root->right=(k+1,inr,postl+numleft,postr-1);
	return root;
}
int main(int argc, char** argv) {
	
	return 0;
}
