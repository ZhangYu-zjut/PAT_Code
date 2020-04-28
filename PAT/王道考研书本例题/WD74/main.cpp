#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <stdio.h>
int gcd(int a,int b)
{
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(int argc, char** argv) {
	
	int a,b;
	while(scanf("%d%d",&a,&b))
	{
		printf("%d\n",a*b/gcd(a,b));
	}
	return 0;
	
}
