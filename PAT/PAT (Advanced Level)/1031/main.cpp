#include <iostream>
#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//ºÚµ•Ã‚AC!!! 
char ch[100];
int main(int argc, char** argv) {
	scanf("%s",ch);
	int n=strlen(ch);
	int n1,n2;
	int i,j,k;
	int flag=0;
	for(i=3;i<=n;i++)
	{
		for(j=i;j>0;j--)
		{
			if(i+j*2-2==n&&flag==0)
			{
				n1=j;
				n2=i;
				flag=1;
				break;
			}
		}
	}
	for(i=0;i<n1-1;i++)
	{
		printf("%c",ch[i]);
		for(j=0;j<n2-2;j++)
		{
			printf(" ");
		}
		printf("%c\n",ch[n-1-i]);	
	}
	for(i=n1-1;i<n1+n2-1;i++)
	{
		printf("%c",ch[i]);
	}
	return 0;
}
