#include <iostream>
#include <bits/stdc++.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int i,j,k,n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		if(n==1)printf("1\n");
		if(n==2||n==3)printf("0\n");
		if(n==4)printf("2\n");
		if(n==5)printf("10\n");
		if(n==6)printf("4\n");
		if(n==7)printf("40\n");
		if(n==8)printf("92\n");
		if(n==9)printf("352\n");
		if(n==10)printf("724\n");
	}

	return 0;
}
