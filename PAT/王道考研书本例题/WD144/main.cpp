#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long F(int x)
{
	if(x==1)return 2;
	if(x>1)
	{
		return 3*F(x-1)+2;
	}
}
int main(int argc, char** argv) {
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",F(n));
	}
	return 0;
}
