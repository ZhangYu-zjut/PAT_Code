#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PAT_A1146,拓扑排序。
//注意：看清楚下标，是0--N-1还是0--N ！！！！
//AC!! 
vector<int>v[1003];
vector<int>v2[1003];
int in[1003];
int in2[1003];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n,m;
	int a,b,t,temp;
	scanf("%d%d",&n,&m);
	int i,j,k;
	fill(in,in+1002,0);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		in[b]++;
	}
	scanf("%d",&k);
	int count=0;
	for(i=0;i<k;i++)
	{
		for(j=1;j<=n;j++)
		{
			in2[j]=in[j];
		}
		bool judge=true;
		for(j=0;j<n;j++)
		{
			scanf("%d",&temp);
			if(in2[temp]!=0)
			{
				judge=false;
			}
			//else
			{
				for(t=0;t<v[temp].size();t++)
				{
					in2[v[temp][t]]--;
				}
			}
		}
		if(judge==true)continue;
		if(count>0)
		{
			printf(" %d",i);
		}
		if(count==0)
		{
			printf("%d",i);
			count++;
		}
		
	}
	return 0;
}
