#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int num[10];
int number[100];
int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	int k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(num[i]!=num[j])
			{
				number[k]=10*num[i]+num[j];
				k++;
			}
		
		}
	}
	int sum=0;
	for(i=0;i<k;i++)
	{
		sum+=number[i];
	
	}
	printf("%d",sum);
	return 0;
}
