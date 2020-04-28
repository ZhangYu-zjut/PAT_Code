#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
int n;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//字符串模拟，关键是对科学计数法的理解。 
string proc(string s,int &e)
{
	int k=0;
	while(s[0]=='0')//去掉前导0 
	{
		s.erase(s.begin());
	}
	if(s[0]=='.')
	{
		s.erase(s.begin());
		while(s[0]=='0')
		{
			s.erase(s.begin());
			e--;
		}
	}
	else
	{
		while(k<s.length()&&s[k]!='.')
		{
			k++;
			e++;
		}
		if(k<s.length())
		{
			s.erase(s.begin()+k);
		}
	}
	if(s.length()==0)
	{
		e=0;
	}
	string ans;
	int num=0;
	k=0;
	while(num<n)
	{
		if(k<s.length())
		{
			ans+=s[k++];
		}
		else
		{
			ans+='0';
		}
		num++;
	}
	return ans;
}
int main(int argc, char** argv) {
	int i,j,k;
	string a,b;
	while(scanf("%d",&n)!=EOF)
	{
		cin>>a>>b;
		int e1=0,e2=0;
		string ans1=proc(a,e1);
		string ans2=proc(b,e2);
		if(ans1==ans2&&e1==e2)
		{
			printf("YES ");
			cout<<"0."<<ans1<<"*"<<"10^"<<e1;
		}
		else
		{
			printf("NO ");
			cout<<"0."<<ans1<<"*"<<"10^"<<e1<<" ";
			cout<<"0."<<ans2<<"*"<<"10^"<<e2;
		}
	}
	return 0;
}
