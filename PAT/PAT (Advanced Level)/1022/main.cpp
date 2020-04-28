#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AC!!!!
map<string,set<string>>ma[6];
set<string>se[6][10000];
string id[10000];
struct node
{
	string id;
	string key[10];
	int size;
}N[10000];
bool cmp(node a,node b)
{
	return a.id<b.id;
}
int main(int argc, char** argv) {	
	freopen("test.txt","r",stdin);
	int n,m,i,j,k;
	string st;
	string str[7];
	scanf("%d%*c",&n);
	for(i=0;i<n;i++)
	{
		int t=0;
		for(j=0;j<=5;j++)
		{
			getline(cin,str[j]);
			//cout<<"str "<<j<<" is:"<<str[j]<<endl;
			if(j>0&&j!=3)
			{
				ma[j][str[j]].insert(str[0]);
			}
			if(j==3)
			{
				N[i].id=str[0];
				for(k=0;k<str[j].length();k++)
				{
					if(str[j][k]!=32)
					{
						st+=str[j][k];
					}
					if(str[j][k]==32||k==str[j].length()-1)
					{
						N[i].key[t++]=st;
						//cout<<"st is:"<<st<<endl;
						N[i].size=t;
						st.clear();
					}
				}
			}
		}
		id[i]=str[0];
	}
	sort(N,N+n,cmp);
	for(i=0;i<n;i++)
	{
		for(j=0;j<N[i].size;j++)
		{
			ma[3][N[i].key[j]].insert(N[i].id);
		}
	}
	scanf("%d%*c",&m);
	int choice;
	string stemp;
	set<string>::iterator it;
	for(i=0;i<m;i++)
	{
		scanf("%d%*c%*c",&choice);
		getline(cin,stemp);
		if(choice==3)
		{
			if(ma[choice][stemp].size()==0)
			{
				cout<<choice<<": "<<stemp<<endl;
				printf("Not Found\n");
			}
			else
			{
				cout<<choice<<": "<<stemp<<endl;
				for(it=ma[choice][stemp].begin();it!=ma[choice][stemp].end();it++)
				{
					cout<<*it<<endl;
				}
			}
		}
		else
		{
			if(ma[choice][stemp].size()==0)
			{
				cout<<choice<<": "<<stemp<<endl;
				printf("Not Found\n");
			}
			else
			{
				cout<<choice<<": "<<stemp<<endl;
				for(it=ma[choice][stemp].begin();it!=ma[choice][stemp].end();it++)
				{
					cout<<*it<<endl;
				}
			}
		}
	}
	return 0;
}
