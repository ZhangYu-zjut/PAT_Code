#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int i,j,n;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<=100;i++)
		{
			for(j=0;j<=100;j++)
			{
				if(100+14*i+8*j<=3*n)
				{
					printf("x=%d,y=%d,z=%d\n",i,j,100-(i+j));
				}
			}
			
		} 
		
	}
	return 0;
}
