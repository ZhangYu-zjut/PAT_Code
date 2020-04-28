#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AC!!!
char ch[]={'W','T','L'}; 

double num[3][3];
int index[3];
int main(int argc, char** argv) {
	char ch1[100],ch2[100],ch3[100];
	int n,i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%lf",&num[i][j]);
		}
		double max=0.0;
		for(j=0;j<3;j++)
		{
			if(num[i][j]>max)
			{
				max=num[i][j];
				index[i]=j;
			}
		}
	}
	double total=(num[0][index[0]]*num[1][index[1]]*num[2][index[2]]*0.65-1)*2;
	printf("%c %c %c %.2lf\n",ch[index[0]],ch[index[1]],ch[index[2]],total);
	return 0;
}
