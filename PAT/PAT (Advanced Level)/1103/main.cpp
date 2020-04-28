#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//一个点没通过。29分 
vector<int>temp;
vector<int>ans;
vector<int>fac;
int n,k,p;
int maxfacsum=0;
void DFS(int index,int nowk,int sum,int facsum)
{
	if(sum==n&&nowk==k)
	{
		if(facsum>maxfacsum)
		{
			maxfacsum=facsum;
			ans=temp;
		}
		return;
	}
	if(sum>n||nowk>k)
	{
		return;
	}
	if(index-1>=0)
	{
		temp.push_back(index);
		DFS(index,nowk+1,sum+fac[index],facsum+index);
		temp.pop_back();
		DFS(index-1,nowk,sum,facsum);
	} 
}
int po(int a,int b)//a^b
{
	int i;
	int sum=1;
	for(i=0;i<b;i++)
	{
		sum*=a;
	}
	return sum;
} 
int main(int argc, char** argv) {
	int i,j;
	scanf("%d%d%d",&n,&k,&p);
	for(i=0;i<n;i++)
	{
		if(po(i,p)<=n)
		{
			fac.push_back(po(i,p));
		}
		else
		{
			break;
		}
	}

	DFS(fac.size()-1,0,0,0);
	if(maxfacsum==0)
	{
		printf("Impossible\n");
		return 0;
	}
	printf("%d =",n);
	for(i=0;i<k;i++)
	{
		if(i!=k-1)printf(" %d^%d +",ans[i],p);
		else printf(" %d^%d",ans[i],p);
	}
	return 0;
}
