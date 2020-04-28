#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//简单的贪心算法，AC!!! 
int cou[100001];
int value[100001];
int main(int argc, char** argv) {
	int n,m;
	scanf("%d",&n);
	int i,j,k;
	long long sum=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&cou[i]);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&value[i]);
	}
	sort(cou,cou+n);
	sort(value,value+m);
	i=n-1;
	j=m-1;
	while(value[j]>0&&cou[i]>0&&i>=0&&j>=0)
	{
		sum+=value[j]*cou[i];
		i--;
		j--;
	}
	i=0;
	j=0;
	while(value[j]<0&&cou[i]<0&&i<n&&j<m)
	{
		sum+=value[j]*cou[i];
		i++;
		j++;
	}
	
	printf("%ld",sum);
	return 0;
}
