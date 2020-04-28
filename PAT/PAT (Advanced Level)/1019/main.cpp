#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AC!!!
int num[1000];
int main(int argc, char** argv) {
	int n,b;
	int i=0,j,k;
	scanf("%d%d",&n,&b);
	while(1)
	{
		num[i]=n%b;
		n/=b;
		i++;
		if(n<1)
		{
			break;
		}
	}
	int length=i;
	bool equal=true;
	for(i=0;i<length;i++)
	{
		if(num[i]!=num[length-1-i])
		{
			equal=false;
			break;
		}
	}
	equal==true?printf("Yes\n"):printf("No\n");
	for(i=0;i<length;i++)
	{
		if(i==0)
		{
			printf("%d",num[length-1-i]);
		}
		else
		{
			printf(" %d",num[length-1-i]);
		}
	}
	return 0;
}
