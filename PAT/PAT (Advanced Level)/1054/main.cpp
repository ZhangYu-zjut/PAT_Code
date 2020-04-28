#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	map<int,int> mp;
	int m,n;
	int i,j; 
	int temp;
	int color;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&temp);
				mp[temp]++;
			}
		}
		map<int,int>::iterator it;
		map<int,int>::iterator it2;
		int max=0;
		for(it=mp.begin();it!=mp.end();it++)
		{
			if(it->second>max)
			{
				max=it->second;
				color=it->first;
			}
		}
		printf("%d\n",color);
	}
	return 0;
}
