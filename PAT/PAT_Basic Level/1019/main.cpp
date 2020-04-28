#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//只过了两个测试点，没有完全AC 
bool cmp(char a,char b)
{
	return a>b;
}
bool judge(char a[])
{
	bool flag=false;
	if(a[0]=='6'&&a[1]=='1'&&a[2]=='7'&&a[3]=='4' )
	{
		flag=true;
	}
	return flag;
}
void ch_print(char a[])
{
	for(int i=0;i<strlen(a);i++)
	{
		printf("%c",a[i]);
	}
}
char num[5];
char a[5];
char b[5];
char c[5];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n;
	int i,j;
	while(scanf("%s",num)!=EOF)
	{
		if(num[0]==num[1]==num[2]==num[3])
		{
			printf("%s - %s = 0000\n",num,num);
			break;
		}
		while(!judge(num))
		{
			sort(num,num+4,cmp);
			int num_a=(int)((num[0]-'0')*1000+(num[1]-'0')*100+(num[2]-'0')*10+(num[3]-'0'));
			printf("%s",num);
			printf(" - ");
			sort(num,num+4);
			int num_b=(int)((num[0]-'0')*1000+(num[1]-'0')*100+(num[2]-'0')*10+(num[3]-'0'));
			printf("%s",num);
			printf(" = ");
			int num_c=num_a-num_b;
			printf("%04d",num_c);
			printf("\n");
			bool spe = false;
			if(num_c==999)
			{
				spe=true;
			}
			int k=3;
			while(1)
			{
				num[k]=(num_c%10)+'0';
				num_c/=10;
				k--;
				if(num_c<1)
				{
					if(spe==true)
					{
						num[0]='0';
					}
					break;
				}
			}
			/*
			for(int k=3;k>=0;k--)
			{
				num[k]=(num_c%10)+'0';
				num_c/=10;
			}*/
		}
		
	} 
	return 0;
}
