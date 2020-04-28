#include <iostream>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int num[1001][1001];

string ans;
char ch[]={'J','Q','K'}; 
int main(int argc, char** argv) {
	freopen("test.txt", "r", stdin);
	int t, k;
	int i, j, m,n,g;
	int total;
	int n1, n2,bound;
	int temp;
	string a;
	string b;
	//printf("hell"); 
	cin>>a>>b;
	int size1=a.length();
	int size2=b.length();
	if(size2<=size1)
	{
		k=1;
		t=size1-1;
		for(i=size2-1;i>=0;i--)
		{
			if(k%2==1)
			{
				
				temp=(((a[t]-'0')+(b[i]-'0'))%13);
				if(temp<=9)
				{
					ans[k]=temp+'0';
				}
				if(temp>9)
				{
					ans[k]=ch[temp-10];
				}
			}
			else
			{
				int temp2=((b[i]-'0')-(a[t]-'0'));
				if(temp2<0)
				{
					temp2+=10;
				}
				ans[k]=temp2+'0';
			}
			k++;
			t--;
		}
	}
	if(size2>size1)
	{
		k=1;
		t=size1-1; 
		for(i=size2-1;i>=(size2-size1);i--)
		{
			if(k%2==1)
			{
				int temp;
				temp=(((a[t]-'0')+(b[i]-'0'))%13);
				//printf("temp is:%d  ",a[t]);//'0'ÊÇ48 
				if(temp<=9)
				{
					ans[k]=temp+'0';
				}
				if(temp>9)
				{
					ans[k]=ch[temp-10];
				}
				//printf("ans is:%c  ",ans[k]);
			}
			else
			{
				int temp2=((b[i]-'0')-(a[t]-'0'));
				if(temp2<0)
				{
					temp2+=10;
				}
				ans[k]=temp2+'0';
				//printf("temp is:%d  ",a[t]);//'0'ÊÇ48 
				//printf("ans is:%c  ",ans[k]);
			}
			k++;
			t--;
		}
		for(i=(size2-size1-1);i>=0;i--)
		{
			ans[k]=b[i];
			k++;
		}
	}
	for(i=k-1;i>=1;i--)
	{
		printf("%c",ans[i]);
	}
	cout<<endl;
	return 0;
}
