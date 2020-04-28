#include <iostream>
#include <stdio.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//1046 »®È­ £¨15 ·Ö£©AC!!!
int main(int argc, char** argv) {
	int a_win=0;
	int b_win=0;
	int n;
	scanf("%d",&n);
	int i,j,a,b,c,d;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(b==(a+c)&&d!=(a+c))
		{
			a_win++;
		}
		if(b!=(a+c)&&d==(a+c))
		{
			b_win++;
		}
	}
	printf("%d %d",b_win,a_win);
	return 0;
}
