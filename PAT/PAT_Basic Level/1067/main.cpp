#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PAT_B 1067 ������ ��20 �֣�AC!!! ע�⣺������û�пո񣬵���������ַ����п����пո񣬶�����Ҫ����һ������֮��Ļس��Ե��� 
char password[30];
char temp[200];
bool cmp(char a[],char b[])
{
	if(strlen(a)!=strlen(b))
	{
		return false;
	}
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]!=b[i])
		{
			return false;
		}
	}
	return true;
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n;
	scanf("%s%d\n",password,&n);
	int count=1;
	int wrong=0;
	getchar();
	while(cin.getline(temp,150))
	{
		if(strlen(temp)==1&&temp[0]=='#')
		{
			break;
		}
		if(count<=n)
		{
			if(cmp(password,temp))
			{
				printf("Welcome in\n");
				break;
			}
			else
			{
				if(wrong<n)
				{
					printf("Wrong password: %s\n",temp);
					wrong++;
				}
				if(wrong==n)
				{

					printf("Account locked\n");		
				}
				
			}
		}
		count++;		
	}
	return 0;
}
