#include <iostream>
#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long num[12];
void count_1(int num,int &count)
{
	string str=to_string(num);
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=="1")
		{
			count++;
		}
	}
}
int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	int temp=0;
	int i,j,k,index;
	num[0]=1;
	int count=0;
	int tem;
	for(i=1;i<12;i++)
	{
		long long d=pow(10,i);
		num[i]=d+num[i-1]*9;
		printf("num is:%lld\n",num[i]);
	}
	for(i=0;i<11;i++)
	{
		if(n>=num[i]&&n<=num[i+1])
		{
			index=i;
			printf("index is%d",index);
		}
	}
	count=num[index];
	for(i=pow(10,index+1);i<=n;i++)
	{
		tem=i;
		count_1(i,count);
		/*while(1)
		{
			int temp=tem/10;
			int last=tem%temp;
			if(last==1)count++;
			temp/=10;
			if(temp<1)break;
		}*/
	}
	printf("%d",count);
	return 0;
}
