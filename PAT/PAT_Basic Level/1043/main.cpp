#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PAT_B1043 Êä³öPATest AC 
char str[10005];
int num[10];
char ch[]={'P','A','T','e','s','t'};
int main(int argc, char** argv) {
	scanf("%s",str);
	int i,j,k;
	for(i=0;i<10;i++)
	{
		num[i]=0;
	}
	for(i=0;str[i]!=0;i++)
	{
		if(str[i]=='P')
		{
			num[0]++;
		}
		if(str[i]=='A')
		{
			num[1]++;
		}
		if(str[i]=='T')
		{
			num[2]++;
		}
		if(str[i]=='e')
		{
			num[3]++;
		}
		if(str[i]=='s')
		{
			num[4]++;
		}
		if(str[i]=='t')
		{
			num[5]++;
		}
	} 
	int maxlen=0;
	int minlen=10000;
	for(j=0;j<6;j++)
	{
		if(num[j]>maxlen)
		{
			maxlen=num[j];
		}
		if(num[j]<minlen)
		{
			minlen=num[j];
		}
	}
	for(i=0;i<maxlen;i++)
	{
		for(j=0;j<6;j++)
		{
			if(num[j]>0)
			{
				printf("%c",ch[j]);
				num[j]--;
			}
		}
	}
	return 0;
}
