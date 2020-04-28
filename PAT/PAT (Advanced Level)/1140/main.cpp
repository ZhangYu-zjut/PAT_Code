#include <iostream>
#include <string>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//注意细节，AC！！！ 
string a;
string cal(string s)
{
	int i=0,j;
	string ans;
	string temp;
	int length=s.length();
	while(i<length-1)
	{
		int count=1;
		temp=s[i];
		while(s[i]==s[i+1]&&i<length-1)
		{
			count++;
			i++;
		}
		ans+=temp;
		ans+=to_string(count);
		//每次处理完前面的值后需要往后加一 
		i++;//这句话不要忘掉！！！ 
	}
	if(s[length-1]!=s[length-2])
	{
		ans+=s[length-1];
		ans+=to_string(1);
	}
	return ans;
}
int main(int argc, char** argv) {
	int i,j,k;
	string s;
	string ans;
	int n;
	cin>>s;
	cin>>n;
	if(n==1)
	{
		cout<<s;
		return 0;
	}  
	s=s+to_string(1);
	for(i=0;i<n-2;i++)
	{
		string temp;
		temp=cal(s);
		s=temp;
	}
	cout<<s;
	return 0;
}
