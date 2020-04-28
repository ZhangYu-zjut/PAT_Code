#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int num[10004];
string s[10004];
bool cmp(string a,string b)
{
	return a<b;
}
int main(int argc, char** argv) {
	int n,i,j,k;
	string ans="";
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		s[i]=num[i]+"";
		cout<<"si is:"<<s[i]<<endl;
	}
	sort(s,s+n,cmp);
	for(i=0;i<n;i++)
	{
		ans+=s[i];
	}
	cout<<ans<<endl;
	return 0;
}
