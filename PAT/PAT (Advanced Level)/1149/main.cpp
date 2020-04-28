#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AC!!!
map<int,set<int>>mp;
int n,m;
int num[10003];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	int i,j,k,t;
	int a,b,temp;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].insert(b);
		mp[b].insert(a);
	}
	set<int>::iterator it;
	for(i=0;i<m;i++)
	{
		scanf("%d",&k);
		for(j=0;j<k;j++)
		{
			scanf("%d",&num[j]);
		}
		bool find=false;
		for(j=0;j<k;j++)
		{
			if(mp[num[j]].size()>0)
			{
				for(it=mp[num[j]].begin();it!=mp[num[j]].end();it++)
				{
					for(t=j+1;t<n;t++)
					{
						if(*it==num[t])
						{
							find=true;
							break;
						}
					}
					if(find)break;
				}
				if(find)
				{
					printf("No\n");
					break;
				}
			}
		}
		if(!find)
		{
			printf("Yes\n");
		}
	}
	return 0;
}
