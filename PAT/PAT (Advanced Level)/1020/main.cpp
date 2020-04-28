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
//根据中序序列和后序序列构建树。[inl,inr],[postl,postr] 
//后序的最后一个为根，在中序序列中找到根所在的位置，记为k.根节点为postr 
//将原始的序列进行分割。其中左子树的节点个数为numleft=k-inl，右子树节点个数为n-1-k+inl 
//左子树的后序区间为【postl,post+numleft-1】，右子树的后序区间为【k,n-1】 
//左子树的中序区间为【post+numleft,postr】，右子树的中序区间为【k+1,n】 
//根节点的左子树节点即为左子树的根节点。 
//进行递归操作。 
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
	//这句话很重要!!! 
	int numleft= k-inl;//左子树节点为numleft个，后序的序列需要进行修改 
	root->left=create(postl,postl+numleft-1,inl,k-1);//左子树节点个数为numleft个 
	root->right=create(postl+numleft,postr-1,k+1,inr);
	
	return root;
}

//层次遍历,
//1.放入根节点。2.判定是否为空.
//3.不为空，取出队头。4.判定子树是否为空，不空则将左右子树放入。 
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
