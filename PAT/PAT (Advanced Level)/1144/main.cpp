#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//注意一些小细节：全是负数、只有一个正数、有多个正数、缺少的数比最后那个数还有大； 
//思路不能错：看加一以后的那个数是否存在 
int num[100005];
int num2[100005];
int main(int argc, char** argv) {
	int n;
	int i,j,k=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		if(num[i]>0)
		{
			num2[k]=num[i];
			k++; 
		} 
	}
	sort(num2,num2+k);
	if(k==0)
	{
		printf("%d",1);
		return 0;
	}
	if(k==1)
	{
		printf("%d",num[0]+1);
		return 0;
	}
	for(i=0;i<k-1;i++)
	{
		if(num2[i]>0&&num2[i]+1<num2[i+1])
		{
			printf("%d",num2[i]+1);
			return 0;
		}
		
	}
	printf("%d",num2[k-1]+1);
	return 0;
}
