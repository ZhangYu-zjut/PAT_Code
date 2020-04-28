#include <iostream>
#include <stdio.h> 
#include <queue>
const int maxn=100;
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node
{
	int value;
	node* left;
	node* right;
};
int pre[maxn],post[maxn],in[maxn];
int n;
//�����������кͺ������й�������[inl,inr],[postl,postr] 
//��������һ��Ϊ�����������������ҵ������ڵ�λ�ã���Ϊk.���ڵ�Ϊpostr 
//��ԭʼ�����н��зָ�����������Ľڵ����Ϊnumleft=k-inl���������ڵ����Ϊn-1-k+inl 
//�������ĺ�������Ϊ��postl,post+numleft-1�����������ĺ�������Ϊ��k,n-1�� 
//����������������Ϊ��post+numleft,postr��������������������Ϊ��k+1,n�� 
//���ڵ���������ڵ㼴Ϊ�������ĸ��ڵ㡣 
//���еݹ������ 
node* create(int postl,int postr,int inl,int inr)
{
	if(postl>postr)
	{
		return NULL;
	}
	node* root=new node;
	root->value=post[postr];
	int k;
	for(k=inl;k<=inr;k++)
	{
		if(in[k]==post[postr])
		{
			break;
		}
	}
	//��仰����Ҫ!!! 
	int numleft= k-inl;//�������ڵ�Ϊnumleft���������������Ҫ�����޸� 
	root->left=create(postl,postl+numleft-1,inl,k-1);//�������ڵ����Ϊnumleft�� 
	root->right=create(postl+numleft,postr-1,k+1,inr);
	
	return root;
}

//��α���,
//1.������ڵ㡣2.�ж��Ƿ�Ϊ��.
//3.��Ϊ�գ�ȡ����ͷ��4.�ж������Ƿ�Ϊ�գ������������������롣 
int num=0;
void BFS(node* root)
{
	if(root==NULL)
	{
		return;
	} 
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node *now=q.front();
		q.pop();
		printf("%d",now->value);
		num++;
		if(num<n)
		{
			printf(" ");
		}
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

int main(int argc, char** argv) {
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&post[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
	}
	node* root=create(0,n-1,0,n-1);
	BFS(root);
	return 0;
}
