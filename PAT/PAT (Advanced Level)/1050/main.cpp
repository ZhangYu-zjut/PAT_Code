#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string temp1;
string temp2;
int num[10010]={0};
int main(int argc, char** argv) {
	getline(cin,temp1);
	getline(cin,temp2);
	int i,j,k;
	for(i=0;i<temp2.length();i++)
	{
		num[temp2[i]-0]=1;//要减去ascii为0的字符（NULL），数字0的ascii不是0！！！ 
		cout<<"num is:"<<temp2[i]-'0'<<endl;
	}
	for(i=0;i<temp1.length();i++)
	{
		if(num[temp1[i]-0]==0)
		{
			printf("%c",temp1[i]);
		}
	}
	printf("\n");
	return 0;
}
