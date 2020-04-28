#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node
{
	int data=0;
	int left;
	int right;
}N[1003];
bool vis[10004];
int n;
int pleaf=0;
int cnt=0;
int judge()
{
	int i;
	int ans=0;
	int cnt1=0;
	int cnt2=0;
	int leaf=(n+1)/2;
	int nonleaf=n-leaf;
	for(i=1;i<=nonleaf;i++)
	{
		if(N[i].data>N[2*i].data&&N[i].data>N[2*i+1].data)
		{
			cnt1++;
		}
		if(N[2*i].data!=0&&N[2*i+1].data!=0)
		{
			if(N[i].data<N[2*i].data&&N[i].data<N[2*i+1].data)
			{
				cnt2++;
			}
		}
		if(N[2*i].data!=0||N[2*i+1].data!=0)
		{
			if(N[2*i].data==0)
			{
				if(N[i].data<N[2*i+1].data)cnt2++;
			}
			if(N[2*i+1].data==0)
			{
				if(N[i].data<N[2*i].data)cnt2++;
			}
		}
	
	}
	
	if(cnt1==nonleaf)return 1;
	else if(cnt2==nonleaf)return 2;
	else return 0;
}
void show(int root)
{
	if(root==0)
	{
		return;
	}
	if(vis[root]==true)
	{
		return;
	}
	if(pleaf==1)
	{
		return;
	}
	if(vis[N[root].left]&&vis[N[root].right])
	{
		vis[root]=true;
		return;
	}
	if(N[root].left==0&&N[root].right==0)
	{
		vis[root]=true;
		printf(" %d",N[root].data);
		pleaf=1;
		return;
	}
	/**/
	if(cnt==0)
	{
		printf("%d",N[root].data);
		cnt++;
	}
	else
	{
		printf(" %d",N[root].data);
	}
	/**/
	show(N[root].right);
	show(N[root].left);
	
}
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	
	int i,j,k;
	int temp;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		N[i].data=temp;
		if(2*i<=n)N[i].left=2*i;
		else N[i].left=0;
		if(2*i+1<=n)N[i].right=2*i+1;
		else N[i].right=0;
		//printf(" tet %d\n",N[8].data);
	}
	int leaf=(n+1)/2;
	int nonleaf=n-leaf;
	fill(vis,vis+1004,false);
	for(i=1;i<=leaf;i++)
	{
		pleaf=0;
		cnt=0;		
		show(1);
		printf("\n");
	}
	//show(1);
	int choice=judge();
	if(choice==1)
	{
		printf("Max Heap\n");
	}
	else if(choice==2)printf("Min Heap\n");
	else printf("Not Heap\n");
	return 0;
}
