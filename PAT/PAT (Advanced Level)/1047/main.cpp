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

int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	map<int,set<string>>mp;
	set<string>se;
	string na;
	int m,n,k,i,j;
	int course,temp,t;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		cin>>na>>t;
		se.insert(na);
		/*if(i==0)
		{
			for(j=0;j<t;j++)
			{
				cin>>temp;
				mp[temp]=se;
			}
		}*/
		//else
		{
			for(j=0;j<t;j++)
			{
				cin>>temp;
				mp[temp].insert(na);
			}
		}
	}
	int index=1;
	bool find=false;
	bool have[2501];
	int last=mp.end()->first;
	i=0;
	for(i=1;i<=k;i++)
	{
		mp.insert(i,"");
	}
	string a="";
	prinyf("length is:%d",a.length());
	for(map<int,set<string>>::iterator it=mp.begin();it!=mp.end();it++)
	{
		if(i!=it->first())
		{
			
		}
	}
	for(map<int,set<string>>::iterator it=mp.begin();it!=mp.end();it++)
	{
		if(have[i])
		{
			cout<<it->first<<" "<<it->second.size()<<endl;
			for(set<string>::iterator it2=it->second.begin();it2!=it->second.end();it2++)
			{
				cout<<*it2<<endl;
			}
		}
		else
		{
			cout<<it->first<<" "<<0<<endl;
		}
	}
	return 0;
}
