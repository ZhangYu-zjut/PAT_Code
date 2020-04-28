#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//ˮ�⣬AC!!! 
char ch[]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
int num[3];
int main(int argc, char** argv) {
	int a,b,c;
	int i,j,k;
	for(i=0;i<3;i++)
	{
		scanf("%d",&num[i]);
	}
	printf("#");
	int ten,ge;
	for(i=0;i<3;i++)
	{
		ten=num[i]/13;
		ge=num[i]%13;
		printf("%c%c",ch[ten],ch[ge]);
	}
	
	return 0;
}
