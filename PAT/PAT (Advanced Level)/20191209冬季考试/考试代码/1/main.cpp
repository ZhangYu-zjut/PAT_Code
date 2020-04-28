#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char ch[10003];
int str2int(string s)
{
	long long size=s.length();
	long long i;
	long long ans=0;
	long long c=1;
	for(i=size-1;i>=0;i--)
	{
		ans+=(s[i]-'0')*c;
		c*=10;
	}
	return ans;
}
bool prime(long long x)
{
	long long i;
	if(x==1)return false;
	else if(x==2)return true;
	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	int m,n;
	scanf("%d%d",&n,&m);
	int i,j,k;
	scanf("%s",ch);
	string ans;
	int size=strlen(ch);
	bool find=false;
	for(i=0;i<=size-1-m+1;i++)
	{
		for(j=i;j<i+m;j++)
		{
			ans+=ch[j];
		}
		long long temp=str2int(ans);
		if(prime(temp))
		{
			cout<<ans<<endl;
			find=true;
			break;
		}
		ans.clear(); 
	}
	if(!find)
	{
		printf("404\n");
	}
	return 0;
}
