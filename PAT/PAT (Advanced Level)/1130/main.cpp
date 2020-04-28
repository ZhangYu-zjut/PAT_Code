#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
#include <string.h> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//注意观察，总结括号的处理,当节点为普通的中间节点（除去根节点和叶子节点的节点）时，在节点两侧加上括号。
//即在这些节点的左子树遍历前加上（，在右子树便利后加上），AC!!! 
int num[50];
int judge[50];
struct node
{
	string data;
	int left;
	int right;
}N[50];
void inorder(int x)
{
	if(x==-1)
	{
		return;
	}
	if(judge[x]==0)//需要加( 
	{
		cout<<"(";
	}
	inorder(N[x].left);
	cout<<N[x].data;
	inorder(N[x].right);
	if(judge[x]==0)//需要加( 
	{
		cout<<")";
	}
}
void postorder(int x)
{
	if(x==-1)
	{
		return;
	}
	postorder(N[x].left);
	postorder(N[x].right);
	cout<<N[x].data<<" ";
}
int main(int argc, char** argv) {
	int i,j,k,n,a,b;
	scanf("%d",&n);
	string str;
	for(i=1;i<=n;i++)
	{
		cin>>str;
		cin>>a>>b;
		N[i].data=str;
		N[i].left=a;
		N[i].right=b;
		if(a>0)num[a]=1;
		if(b>0)num[b]=1;
		if(a==-1&&b==-1)
		{
			judge[i]=1;
		}
	}
	int root;
	for(i=1;i<=n;i++)
	{
		if(num[i]==0)
		{
			root=i;
			break;
		}
	}
	judge[root]=1;
	inorder(root);
	//postorder(root);
	return 0;
}
