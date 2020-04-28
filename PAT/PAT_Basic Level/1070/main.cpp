#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define N 10001
int num[N];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	double ans=(num[0]+num[1]+0.0)/2;
	//double ans=0.0;
	for(j=2;j<n;j++)
	{
		ans=(ans+num[j]+0.0)/2;
	}
	printf("%d",int(ans));
	return 0;
}
