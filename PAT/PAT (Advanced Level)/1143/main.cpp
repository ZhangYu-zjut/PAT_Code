#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AC!!
int n,m;
int in[10005];
int finda=0;
int find2=0;
struct node
{
	int data;
	node* left;
	node* right;
	int layer;
	node* father;
}N[10004];

void create(node* &root,int a,int layer)
{
	
	if(root==NULL)
	{
		//node* root=new node;//这样写是错的！！！
		root = new node; //这样写才对！！！ 
		root->left=NULL;
		root->right=NULL;
		root->data=a;
		root->layer=layer;
		return;
	}
	if(a<root->data)
	{
		create(root->left,a,layer+1);
		root->left->father=root;
	}
	else
	{
		create(root->right,a,layer+1);
		root->right->father=root;
	}

}
void inshow(node* root)
{
	//printf(" data is%d \n",root->data);
	if(root==NULL)
	{
		return;
	}
	inshow(root->left);
	//printf("%d ",root->layer);
	inshow(root->right);
	printf("%d ",root->data);
}
void search(node* root,node* &p,int x) 
{
	if(root==NULL)
	{
		return;
	}
	if(x==root->data)
	{
		find2=1;
		p=root;
		return;
	}
	if(x<root->data&&find2==0)
	{
		search(root->left,p,x);
	}
	if(x>root->data&&find2==0)
	{
		search(root->right,p,x);
	}
	
}
/*void search(node* root,node* &p1,node* &p2,int x,int y)
{
	if(root==NULL)
	{
		//printf("errot\n");
		return;
	}
	if(root->data==x)
	{
		p1 = root;
		//找到后不能返回，如果返回的话，就相当于停止往下搜索 
	}
	if(root->data==y)
	{
		p2 = root;
		//printf("find x %d\n",x);
	}
	if(x<root->data) 
	{
		search(root->left,p1,p2,x,y);
	}
	else
	{
		search(root->right,p1,p2,x,y);	
	}
	if(y<root->data) 
	{
		search(root->left,p1,p2,x,y);
	}
	else
	{
		search(root->right,p1,p2,x,y);	
	}
}*/
//另外一种ruturn的写法怎么写？？ 
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	scanf("%d%d",&m,&n);
	int i,j,k;
	int a,b;
	node* root=NULL;
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		create(root,in[i],1);
	}
	//root->layer=1;//这句话不能放在这里 
	if(root==NULL)
	{
		printf("errior\n");
	}
	//inshow(root);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		node* p1=NULL;
		node* p2=NULL;
		find2=0;
		search(root,p1,a);
		find2=0;
		search(root,p2,b);
		if(p1==NULL&&p2==NULL)
		{
			printf("ERROR: %d and %d are not found.\n",a,b);
			continue;
		}
		if(p1==NULL&&p2!=NULL)
		{
			printf("ERROR: %d is not found.\n",a);
			continue;
		}
		if(p1!=NULL&&p2==NULL)
		{
			printf("ERROR: %d is not found.\n",b);
			continue;
		}
		if(p1!=NULL&&p2!=NULL)
		{
			int flag=0;		
			//找到p1,p2
			int maxlayer=max(p1->layer,p2->layer); 
			while(p1->layer<p2->layer)
			{
				p2=p2->father;
				flag=1;
			}
			while(p1->layer>p2->layer)
			{
				p1=p1->father;
				flag=2;
			}
			if(p1->data==p2->data&&flag==1)
			{
				printf("%d is an ancestor of %d.\n",a,b);
			}
			else if(p1->data==p2->data&&flag==2)
			{
				printf("%d is an ancestor of %d.\n",b,a);
			}
			else
			{
				while(p1->data!=root->data&&p2->data!=root->data)
				{
					p1=p1->father;
					p2=p2->father;
					if(p1->data==p2->data)
					{
						printf("LCA of %d and %d is %d.\n",a,b,p1->data);
						break;
					}
				}
			}
		}
	}
	return 0;
}
