#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PAT_A1102 二叉树的反转，注意一些细节，AC!!! 
struct node
{
	int data;
	int left;
	int right;
}N[100];
int isroot[100];
void post(int root)
{
	if(root==-1)return;
	post(N[root].left);
	post(N[root].right); 
	/*下面是错误的写法*/
	/*int temp=N[root].left;
	N[root].right=N[root].left; 
	N[root].left=temp;
	*/
	/*正确写法*/
	int temp=N[root].left;
	N[root].left=N[root].right; 
	N[root].right=temp;
	//或者使用swap 
	//swap(N[root].left,N[root].right);
}
int in1=0;
int level1=0;
void in(int root)
{
	if(root==-1)return;
	in(N[root].left);
	if(in1==0)
	{
		printf("%d",N[root].data);
		in1++;
	}
	else
	{
		printf(" %d",N[root].data);
	}
	in(N[root].right);
}
void level(int root)
{
	if(root==-1)return;
	queue<int>q;
	q.push(root);
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		if(level1==0)
		{
			printf("%d",N[temp].data);
			level1++;
		}
		else
		{
			printf(" %d",N[temp].data);
		}
		if(N[temp].left!=-1)q.push(N[temp].left);
		if(N[temp].right!=-1)q.push(N[temp].right);
	}
}
int main(int argc, char** argv) {
	fill(isroot,isroot+100,true);
	int n,i,j,k;
	char a,b;
	int root;
	scanf("%d",&n);
	getchar();//要加这句话，吸收回车符 
	if(n==1)//边界值 
	{
		printf("%d\n",0);
		printf("%d\n",0);
		return 0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%c %c",&a,&b);
		getchar();//要加这句话，吸收回车符 
		N[i].data=i;
		if(a!='-')
		{
			N[i].left=a-'0';
			isroot[a-'0']=false;
		}
		else
		{
			N[i].left=-1;
		}
		if(b!='-')
		{
			N[i].right=b-'0';
			isroot[b-'0']=false;
		}
		else
		{
			N[i].right=-1;
		}
	}
	for(i=0;i<n;i++)
	{
		if(isroot[i])
		{
			root=i;
			break;
		}
	}
	post(root);
	level(root);
	printf("\n");
	in(root);
	return 0;
}
