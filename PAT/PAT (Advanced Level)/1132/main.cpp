#include <iostream>
#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//简单题，不过要考虑b==0的情况
//AC!!
int main(int argc, char** argv) {
	int n,temp;
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		int length=0;
		int data=temp;
		while(data>0)
		{
			length++;
			data/=10;
		}
		int a=temp/(pow(10,(int)length/2));
		int b=temp%((int)pow(10,(int)length/2));
		if(b==0)printf("No\n");
		else
		{
			if(temp%(a*b)==0)printf("Yes\n");
			else printf("No\n");
		}	
	}
	return 0;
}
