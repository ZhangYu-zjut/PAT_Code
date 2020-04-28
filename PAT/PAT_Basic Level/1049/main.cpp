#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PAT_B1049 数列的片段和  AC!!!
//找到规律即可，第i个数对应的个数为i*(n-i+1); 
#define N 100001 
double num[N]; 
int main(int argc, char** argv) {
	int n;
	int i,j,k;
	double temp;
	while(scanf("%d",&n)!=EOF)
	{
		temp=0.0;
		for(i=1;i<=n;i++)
		{
			scanf("%lf",&num[i]);
			temp+=num[i]*i*(n-i+1);
		}
		printf("%0.2lf\n",temp);
	} 
	return 0;
}
