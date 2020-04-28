#include <iostream>
#include <stdio.h> 
#include <string>
#include <stack>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node
{
	int data;
	node* left;
	node* right;
}n[32];
int pre[100],in[100];
int count=0;
stack<int>s;
node* create(int preL,int preR,int inL,int inR)
{
	if(preL>preR)return NULL;
	node *root = new node;
	root->data = pre[preL];
	int i,k;
	for(i=0;i<50;i++)
	{
		if(pre[preL]==in[i])
		{
			k=i;
			break;
		}
	}
	int numleft = k-inL;
	root->left = create(preL+1,preL+numleft,inL,k-1); 
	root->right = create(preL+numleft+1,preR,k+1,inR); 
	return root;
}
void post(node* root)
{
	if(root==NULL)return;
	post(root->left);
	post(root->right);
	if(count==0)
	{
		printf("%d",root->data);
		count++;
	}
	else printf(" %d",root->data);
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	string a;
	int n,i,j,k,temp,index1=0,index2=0;
	node* root=NULL;
	cin>>n;
	for(i=0;i<2*n;i++)
	{
		cin>>a;
		if(a=="Push")
		{
			cin>>temp;
			s.push(temp);
			pre[index1++]=temp;
		}
		else
		{
			temp=s.top();
			s.pop();
			in[index2++]=temp;
		}
	}
	
	root=create(0,n-1,0,n-1);
	post(root);
	return 0;
}
