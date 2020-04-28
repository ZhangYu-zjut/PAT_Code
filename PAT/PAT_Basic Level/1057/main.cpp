#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PAT 1057 数零壹 （20 分）有一个测试用例没有通过，只能拿到19分
#define N 100005
char str[N];
int num[N];
int bin[N];
int main(int argc, char** argv) {
	int i,j,n;
	gets(str);
	//scanf("%s",str);
	int size=0;
	for(i=0;str[i]!=0;i++)
	{
		if(str[i]>='a'&&str[i]<='z')
		{
			num[size]=str[i]-'a'+1;
			size++;
		}
		if(str[i]>='A'&&str[i]<='Z')
		{
			num[size++]=str[i]-'A'+1;
		}
	}
	int sum=0;
	for(i=0;i<size;i++)
	{
		sum+=num[i];
	}

	int k=0;
	while(1)
	{
		bin[k]=sum%2;
		sum=sum/2;
		k++;
		if(sum==0)
		{
			break;
		}
	}
	int zero=0;
	int one=0;
	for(i=0;i<k;i++)
	{
		if(bin[i]==0)
		{
			zero++;
		}
		if(bin[i]==1)
		{
			one++;
		}
	}
	printf("%d %d",zero,one);
	return 0;
}
