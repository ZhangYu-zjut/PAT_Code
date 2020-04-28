#include <iostream>
#include <stdio.h> 
#include <map>
#include <set>
#include <vector>
#include <string>
#include <string.h>
#include <time.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//思路：利用map<string,set<int>>mp存储数据
//1039 Course List for Student （25 分）AC!!!! 
string name[300];
string query;
string na;
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	map<string,set<int>>mp;
	set<int>se;
	int m,n,k,i,j;
	int course,temp,t;
	scanf("%d%d",&n,&k);
	for(i=0;i<k;i++)
	{
		scanf("%d%d",&course,&t);
		if(i==0)
		{
			for(j=0;j<t;j++)
			{
				cin>>na;
				se.insert(course);
				mp[na]=se;
				se.clear();
			}
		}
		else
		{
			for(j=0;j<t;j++)
			{
				cin>>na;
				mp[na].insert(course);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cin>>query;
		if(mp[query].size()==0)
		{
			cout<<query<<" "<<mp[query].size()<<endl;
		}
		else
		{
			cout<<query<<" "<<mp[query].size();
			for(set<int>::iterator it=mp[query].begin();it!=mp[query].end();it++)
			{
				cout<<" "<<*it;
			}
			cout<<endl;
		}
	}
	return 0;
}
