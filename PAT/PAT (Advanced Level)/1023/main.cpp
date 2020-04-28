#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AC!!! 注意20位的数字，不能用long long进行存储 
char ch[100];
char ans[100];
string a,b;
bool check[100]={false};
int main(int argc, char** argv) {
	int n;
	int i,j;
	scanf("%s",ch);
	int n1=strlen(ch);
	int carry=0;
	for(i=0;i<strlen(ch);i++)
	{
		int temp=(ch[n1-1-i]-'0')*2+carry;
		carry=temp/10;
		int res=temp%10;
		ans[i]=res+'0';
	}
	if(carry>0)
	{
		ans[n1]=1+'0';
	}
	int n2=strlen(ans);
	for(i=0;i<strlen(ch);i++)
	{
		int count=0;
		for(j=0;j<strlen(ans);j++)
		{
			if(ch[i]==ans[j]&&check[j]==false&&count==0)
			{
				check[j]=true;
				count++;
			}
		}
	}
	for(j=0;j<strlen(ans);j++)
	{
		if(check[j]==false)
		{
			
			printf("No\n");
			for(i=0;i<strlen(ans);i++)
			{
				printf("%c",ans[strlen(ans)-1-i]);
			}
			return 0;
		}
	}
	printf("Yes\n");
	for(i=0;i<strlen(ans);i++)
	{
		printf("%c",ans[strlen(ans)-1-i]);
	}
	return 0;
}
