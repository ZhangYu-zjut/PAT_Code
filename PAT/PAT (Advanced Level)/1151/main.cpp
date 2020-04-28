#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AC!!
int n,m;
int in[10005],pre[10005];

struct node
{
	int data;
	node* left;
	node* right;
	int layer;
	node* father;
}N[10004];
vector<node*>ans;
node* create(int prel,int prer,int inl,int inr,int layer)
{
	if(prel>prer)
	{
		return NULL;
	}
	node* root=new node;//一定要new一个节点 
	root->data=pre[prel];
	root->layer=layer;
	int i,j;
	for(i=inl;i<=inr;i++)
	{
		if(in[i]==pre[prel])
		{
			break;
		}
	}
	int leftnum=i-inl;
	root->left=create(prel+1,prel+leftnum,inl,i-1,layer+1);
	if(root->left!=NULL)root->left->father=root;
	root->right=create(prel+leftnum+1,prer,i+1,inr,layer+1);	
	if(root->right!=NULL)root->right->father=root;
	return root;
}
void inshow(node* root)
{
	if(root==NULL)
	{
		return;
	}
	inshow(root->left);
	//printf("%d ",root->layer);
	inshow(root->right);
	printf("%d ",root->data);
}
//另一种写法 
void sea(node* root,int x,int count)
{
	if(ans.size()>0&&count==0)
	{
		ans.clear();
	}
	count++;
	if(root==NULL)
	{
		return;
	}
	if(root->data==x)
	{
		ans.push_back(root);
	}
	else
	{
		sea(root->left,x,count);
		sea(root->right,x,count);
	}
} 
void search(node* root,node* &p1,node* &p2,int x,int y)
{
	if(root==NULL)
	{
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
	}
	search(root->left,p1,p2,x,y);
	search(root->right,p1,p2,x,y);	

}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	scanf("%d%d",&m,&n);
	int i,j,k;
	int a,b;
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
	}
	node* root=NULL;
	//root->layer=1;//这句话不能放在这里 
	root=create(0,n-1,0,n-1,1);
	//inshow(root);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		node* p1=NULL;
		node* p2=NULL;
		sea(root,a,0);
		if(ans.size()>0)p1=ans[0];
		sea(root,b,0);
		if(ans.size()>0)p2=ans[0];
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
