#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//有一个测试点因为内存超限原因没有通过！！ 
int num1[200000];
int num2[200000];
const int INF=(1<<30)-1;
bool cmp(long a,long b)
{
	return a<b;
}
int main(int argc, char** argv) {
	printf("size of is%d\n",sizeof(num1));
	int n,m;
	int i,j,k;
	scanf("%d",&n);	
	int count=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num1[i]);
	}
	scanf("%d",&m);	
	for(i=0;i<m;i++)
	{
		scanf("%d",&num2[i]);
	}
	num1[n]=INF;
	num2[m]=INF;
	int pos=(n+m-1)/2;
	i=0,j=0;
	while(count<pos)
	{
		if(num1[i]<num2[j])i++;
		else j++;
		count++;
	}
	if(num1[i]<num2[j])
	{
		printf("%d",num1[i]);
	}
	else printf("%d",num2[j]);

	return 0;
}
