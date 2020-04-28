#include <iostream>
#include <stdio.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AC!!!
using namespace std;
int num[102];
//node* root=NULL;
struct node
{
	int data;
	int height;
	node* left;
	node* right;
}N[100];

int getheight(node* root)
{
	if(root==NULL)return 0;
	return root->height;
}
int getfactor(node* root)
{
	return (getheight(root->left)-getheight(root->right));
}
void update(node* root)//更新高度 
{
	root->height = max(getheight(root->left),getheight(root->right))+1;
}
void L(node* &root)
{
	node* temp=root->right;
	root->right=temp->left;
	temp->left=root;
	update(root);
	update(temp);
	root=temp;
}
void R(node* &root)
{
	node* temp=root->left;
	root->left=temp->right;
	temp->right=root;
	update(root);
	update(temp);
	root=temp;
}
node* newnode(int data)
{
	node* temp = new node;
	temp->data=data;
	temp->left=temp->right=NULL;
	temp->height=1;
	return temp;
}

void insert(node* &root,int data)//注意这个返回值是void 
//在插完之后要更新根节点的高度，判断是否平衡，并根据是否平衡进行调整 
{
	if(root==NULL)
	{
		root=newnode(data);
		return;
	}
	if(root->data<data)
	{
		insert(root->right,data);
		update(root);//这句话不能少！！！ 
		if(getfactor(root)==2)
		{
			if(getfactor(root->left)==1)
			{
				R(root);
			}
			else if(getfactor(root->left)==-1)
			{
				L(root->left);
				R(root);
			}
		}
		else if(getfactor(root)==-2)
		{
			if(getfactor(root->right)==-1)
			{
				L(root);
			}
			else if(getfactor(root->right)==1)
			{
				R(root->right);
				L(root);
			}
		}
	}
	if(root->data>data)
	{
		insert(root->left,data);
		update(root);//这句话不能少！！！ 
		if(getfactor(root)==2)
		{
			if(getfactor(root->left)==1)
			{
				R(root);
			}
			else if(getfactor(root->left)==-1)
			{
				L(root->left);
				R(root);
			}
		}
		else if(getfactor(root)==-2)
		{
			if(getfactor(root->right)==-1)
			{
				L(root);
			}
			else if(getfactor(root->right)==1)
			{
				R(root->right);
				L(root);
			}
		}
	}
}
node* create(int data[],int n)
{
	int i;
	node* temp=NULL;
	for(i=0;i<n;i++)
	{
		insert(temp,data[i]);
	}
	return temp;
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int i,j,k,n,temp;
	node* root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		num[i]=temp;
	}
	root=create(num,n);
	printf("%d",root->data);

	return 0;
}
