#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//考察完全二叉树的建立+后序遍历+最大最小堆的判定
//完全二叉树可以直接用下标进行访问，左子树2*i,右子树2*i+1。（前提是下标均不超过n） 
//用建好的最大最小堆跟原始的序列比较，原始序列跟哪个相等就是最大/最小堆 
//AC!!
struct node
{
	int data;
	int left;
	int right;
}N[1003];
int n;
int cnt;
int num[1003];
int maxheap[1003];
int minheap[1003];
bool cmp(int a[],int b[],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
			return false;
		}
	}
	return true;
}
void downaj(int low,int high)
{
	int i=low,j=2*i;
	while(j<=high)
	{
		if(maxheap[j+1]>maxheap[j]&&j+1<=high)
		{
			j=j+1;
		}
		if(maxheap[j]>maxheap[i])
		{
			swap(maxheap[i],maxheap[j]);
			i=j;
			j=2*i;
		}
		else
		{
			break;
		}
	}
}
void mindownaj(int low,int high)
{
	int i=low,j=2*i;
	while(j<=high)
	{
		if(minheap[j+1]<minheap[j]&&j+1<=high)
		{
			j=j+1;
		}
		if(minheap[j]<minheap[i])
		{
			swap(minheap[i],minheap[j]);
			i=j;
			j=2*i;
		}
		else
		{
			break;
		}
	}
}
void createheap1()
{
	for(int i=n/2;i>=1;i--)
	{
		downaj(i,n);
	}
}
void createheap2()
{
	for(int i=n/2;i>=1;i--)
	{
		mindownaj(i,n);
	}
}
void post(int root)
{
	if(root==0)
	{
		return;
	}
	post(N[root].left);
	post(N[root].right);
	if(cnt==0)
	{
		printf("%d",N[root].data);
		cnt++;
	}
	else
	{
		printf(" %d",N[root].data);
	}
}
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	int m;
	int i,j;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&num[j]);
			maxheap[j]=num[j];
			minheap[j]=num[j];
			N[j].data=num[j];
			if(2*j<=n)N[j].left=2*j;
			else N[j].left=0;
			if(2*j+1<=n)N[j].right=2*j+1;
			else N[j].right=0;
		}
		createheap1();
		createheap2();
		if(cmp(num,maxheap,n))
		{
			printf("Max Heap\n");
		}
		else if(cmp(num,minheap,n))
		{
			printf("Min Heap\n");
		}
		else
		{
			printf("Not Heap\n");
		}
		cnt=0;
		post(1);
		printf("\n");
	}
	
	return 0;
}
