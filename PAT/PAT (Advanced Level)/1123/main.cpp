#include <iostream>
#include <stdio.h> 
#include <queue>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AVL+��ȫ������+��α�����AC!!!
using namespace std;
int num[102];

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
void update(node* root)//���¸߶� 
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

void insert(node* &root,int data)//ע���������ֵ��void 
//�ڲ���֮��Ҫ���¸��ڵ�ĸ߶ȣ��ж��Ƿ�ƽ�⣬�������Ƿ�ƽ����е��� 
{
	if(root==NULL)
	{
		root=newnode(data);
		return;
	}
	if(root->data<data)
	{
		insert(root->right,data);
		update(root);//��仰�����٣����� 
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
		update(root);//��仰�����٣����� 
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
void show(node* root)
{
	if(root==NULL)
	{
		return;
	}
	
	show(root->left);
	printf("%d\n",root->data);
	show(root->right);
}
bool BFS(node* root)
{
	queue<node*>q;
	q.push(root);
	int count=0;
	bool find=false;
	bool ans=true;
	while(!q.empty())
	{
		node* temp=q.front();
		q.pop();
		if(count==0)
		{
			printf("%d",temp->data);
			count++;
		}
		else 
		{
			printf(" %d",temp->data);
			count++;
		}
		if(temp->left!=NULL)
		{
			if(find)
			{
				ans=false;
			}
			q.push(temp->left);	
		}
		else
		{
			find=true;
		}
		if(temp->right!=NULL)
		{
			if(find)
			{
				ans=false;
			}
			q.push(temp->right);	
		}
		else
		{
			find=true;
		}
	}
	return ans;
} 
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	int i,j,k,n,temp;
	node* root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		num[i]=temp;
	}
	root=create(num,n);
	bool ans=BFS(root);
	if(ans==true)printf("\nYES");
	else printf("\nNO");

	return 0;
}
