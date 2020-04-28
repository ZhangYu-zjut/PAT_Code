#include <iostream>
#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//pat_B1007 AC
bool prime(int x)
{
	int i,j;
	for(i=2;i<sqrt(x)+1;i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
int main(int argc, char** argv) {
	int i,j,k,n;
	int statr=3;
	scanf("%d",&n);
	int count=0;
	for(i=3;i+2<=n;i+=2)
	{
		if(prime(i)&&prime(i+2))
		{
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}
