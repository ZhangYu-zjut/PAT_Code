#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//¼òµ¥Ìâ£¬AC!! 
int main(int argc, char** argv) {
	int a1,b1,c1;
	int a2,b2,c2;
	int b3,c3;
	long long a3;
	int carry=0;
	scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
	c3=c1+c2;
	if(c3>29)
	{
		c3-=29;
		b2++;
	}
	b3=b1+b2;
	if(b3>17)
	{
		b3-=17;
		a2++;
	}
	else
	{
		carry=0;
	}
	a3=a1+a2;
	printf("%lld.%d.%d",a3,b3,c3);
	return 0;
}
