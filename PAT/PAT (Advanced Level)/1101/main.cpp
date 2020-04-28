#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//好像有点问题 
int nmin=0;
int nmax=1000000009;//这里要是10^9，注意数据的范围 0x3fffffff; 
int leftmax[100005];
int rightmin[100005];
int num[100005];
vector<int>ans;
int main(int argc, char** argv) {
	int n,i,j;
	scanf("%d",&n);
	int count=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		if(num[i]>nmin)
		{
			leftmax[i]=num[i];
			nmin=num[i];
		}
		else
		{
			leftmax[i]=nmin;
		}
	}
	if(n==1)//当n==1的时候应该不输出结果的序列，但是这道题目加不加对1的特判都能通过！ 
	{
		printf("1\n");
		printf("%d",num[0]);
		return 0;
	}
	/*另外一种写法 
	lefrmax[0]=0;
	for(i=1;i<n;i++)
	{
		leftmax[i]=max(leftmax[i-1],num[i-1]); 
	}
	rightmin[n-1]=inf;
	for(i=n-2;i>=0;i--)
	{
		rightmin=min(rightmin[i+1],num[i+1]);
	}
	*/
	for(i=n-1;i>=0;i--)
	{
		if(num[i]<nmax)
		{
			rightmin[i]=num[i];
			nmax=num[i];
		}
		else
		{
			rightmin[i]=nmax;
		}
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			if(num[i]<rightmin[1])
			{
				count++;
				ans.push_back(num[i]);
			}
		}
		else if(i==n-1)
		{
			if(num[i]>leftmax[n-2])
			{
				count++;
				ans.push_back(num[i]);
			}
		}
		else
		{
			if(num[i]<rightmin[i+1]&&num[i]>leftmax[i-1])
			{
				count++;
				ans.push_back(num[i]);
			}
			
		}
	}
	if(ans.size()!=0)
	{
		sort(ans.begin(),ans.end());
	}
	if(count==0)
	{
		printf("%d\n\n",count);
	} 
	else
	{
		printf("%d\n",count);
		for(i=0;i<ans.size();i++)
		{
			if(i==0)printf("%d",ans[i]);
			else printf(" %d",ans[i]);
		}
	}
	return 0;
}
