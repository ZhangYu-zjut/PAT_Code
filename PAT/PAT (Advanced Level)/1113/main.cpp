#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//ºÚµ•Ã‚AC!!
int num[100001];
int main(int argc, char** argv) {
	int n,i,j,k;
	int ans1;
	long long ans2;
	while(scanf("%d",&n)!=EOF)
	{
		ans2=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		} 
		sort(num,num+n);
		if(n%2==0)
		{
			ans1=0;
			for(j=0;j<n/2;j++)
			{
				ans2+=(num[n-1-j]-num[j]);
			}
		}
		else
		{
			ans1=1;
			for(j=0;j<n/2;j++)
			{
				ans2+=(num[n-1-j]-num[j]);
			}
			ans2+=num[n/2];
		}
		printf("%d %lld\n",ans1,ans2);
	} 
	return 0;
}
