#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node
{
	int st;
	int ed;
};
const int INF=100000008;
map<int,int>mp;
map<int,vector<node>>node_mp;
int n,num[100005];
int sum[100005]={0};
//int sum2[100005][100005];

bool search(int count)
{
	
}
int main(int argc, char** argv) {
	int n,count,temp;
	int temp_sum; 
	int i,j,k,min_sum=INF;
	scanf("%d%d",&n,&count);
	sum[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		sum[i]=sum[i-1]+temp;
	}
	bool find=false;
	for(i=1;i<=n;i++)
	{
		j=i;
		temp_sum=sum[j]-sum[i-1];
		while(temp_sum<count&&j<n)
		{
			j++;
			temp_sum=sum[j]-sum[i-1];
		}
		if(temp_sum==count)
		{
			mp[i]=j;
			find=true;
		}
		if(temp_sum>=count&&temp_sum<=min_sum)
		{
			min_sum=temp_sum;
			node a;
			a.st=i;
			a.ed=j;
			node_mp[temp_sum].push_back(a);
		}
	}
	if(find)
	{
		map<int,int>::iterator it;
		for(it=mp.begin();it!=mp.end();it++)
		{
			printf("%d-%d\n",it->first,it->second);
			//cout<<it->first<<"-"<<it->second<<endl; 
		}
	}
	else
	{
		vector<node>::iterator it;
		for(int i=0;i<node_mp[min_sum].size();di++)
		{
			printf("%d-%d\n",node_mp[min_sum][i].st,node_mp[min_sum][i].ed);
			//cout<<node_mp[min_sum][i].st<<"-"<<node_mp[min_sum][i].ed<<endl;
		}
	}
	return 0;
}
