#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�����������Ľ������̣�
//����ڵ㺯�� 
//�������� 
//�������� 
//�������
//ɾ��������ɾ����rootΪ�������нڵ�ֵΪx�Ľڵ㣬ע��Ҫ�ݹ�ɾ�� 
struct node
{
	int data;
	node* left;
	node* right;
}; 
node* newnode(int x)//�½�һ���ڵ㣬�ڵ�������ӽڵ�Ϊ�գ��ڵ�ֵΪx 
{
	node* root=new node;
	root->left=root->right=NULL;
	root->data=x;
	return root;
}
void insert(node* &root,int x)//�����в���ֵΪx�����ݡ�������һֱ���ң�ֱ���ҵ�Ϊ�յĽڵ㣬�����½��ڵ㡣 
//���ڸ��ڵ�ָ������ݲ��ϱ仯������Ҫ���뼰ָ������á�  
{
	if(root==NULL)
	{
		root=newnode(x);
		return;
	}
	if(x<root->data)
	{
		insert(root->left,x);
	}
	else
	{
		insert(root->right,x);
	}
}
int num[1000];
node* create(int data[],int n)//�������������Ĺ��̱������������ڵ㲻�ϵز������ݡ�
{
	node* root=NULL;//��Ϊ�����ʱ����Ҫ���ڵ㣬�������ȴ���һ���ڵ㡣��������ɺ�root���Ǹ�����֮��Ľڵ㡣 
	for(int i=0;i<n;i++)
	{
		insert(root,data[i]);
	}
	return root;
}
void show(node* root)//������������������� 
{
	if(root==NULL)
	{
		return;
	} 
	else
	{
		show(root->left);
		printf("%d ",root->data);
		show(root->right);
	}
}
void lawyer(node* root)//��һ���Ѿ������õ������в�α�������ڵ�ֵ�� 
{
	queue<node*>q;
	if(root==NULL)
	{
		return;
	}
	else
	{
		q.push(root);
		while(!q.empty())
		{
			node* now=q.front();
			q.pop();
			printf("%d ",now->data);
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
}
//�ҵ�ǰ���ڵ�ͺ�̽ڵ�
node* findMax(node* root)
{
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root;
} 
node* findMin(node* root)
{
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}
//ɾ��������ɾ����rootΪ�������нڵ�ֵΪx�Ľڵ㣬ע��Ҫ�ݹ�ɾ�� 
void deleteNode(node* &root,int x)
{
	if(root==NULL)
	{
		return;
	}
	if(root->data==x)
	{
		//��Ҷ�ӽڵ㣬ֱ��ɾ�� 
		if(root->left==NULL&&root->right==NULL)
		{
			root=NULL;
		}
		//��������Ϊ�գ��ҵ���������ǰ���ڵ㣬��ǰ���ڵ��ֵ���ǵ�ǰ�ڵ��ֵ������ǰ���ڵ���еݹ�ɾ�� 
		else if(root->left!=NULL)
		{
			node* pre=findMax(root->left);//�����������ڵ㣬��Ϊǰ���ڵ� 
			root->data=pre->data;
			deleteNode(root->left,pre->data);//����ǰ�ڵ��Ϊ�������Ľڵ㣬Ȼ��ɾ��pre->data��Ӧ�Ľڵ� 
		}
		//��������Ϊ�գ��ҵ��������ĺ�̽ڵ㣬����̽ڵ��ֵ���ǵ�ǰ�ڵ��ֵ�����Ժ�̽ڵ���еݹ�ɾ�� 
		else
		{
			node* post=findMin(root->right);
			root->data=post->data;
			deleteNode(root->right,post->data);
		}
	}
	else if(x<root->data)
	{
		deleteNode(root->left,x);
	}
	else
	{
		deleteNode(root->right,x);
	}
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	} 
	node* root=NULL;
	root=create(num,n);
	show(root);
	printf("\n��α����Ľ��Ϊ��\n");
	lawyer(root);
	//�����ڵ��10ɾ���󣬲鿴��α����Ľ�� 
	deleteNode(root,10);
	printf("\nɾ�����ڵ�󣬲�α����Ľ��Ϊ��\n");
	lawyer(root);
	return 0;
}
