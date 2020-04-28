#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int MAXV=10000007;
int n;
struct fac
{
	int data;
	int count;
}F[100];
//两种方法，素数筛选法和直接比较法
int prime[MAXV],length=0;
bool pri[MAXV]={true};
bool test[100]={true};//这样只能对第一个赋值，不能对数组的全部元素赋值！！！ 
int total_prime=0; 
void findprime()
{
	int i,j;
	int temp=(int)sqrt(n*1.0); 
	for(i=2;i<MAXV;i++)
	{
		if(pri[i]==true)
		{
			prime[length++]=i;
			for(j=i;j<MAXV;j+=i)
			{
				pri[j]=false;
			}
		}
	}
}
void search()
{
	int temp=(int)sqrt(n*1.0);
	int i,j;
	for(i=0;i<length;i++)
	{
		if(n%prime[i]==0)
		{
			fac ftemp;
			ftemp.data=prime[i];
			ftemp.count=0;
			while(n%prime[i]==0)
			{
				ftemp.count++;
				n/=prime[i];	
			}
			F[total_prime++]=ftemp;
		}
	}
	if(n!=1)
	{
		fac ftemp;
		ftemp.data=n;
		ftemp.count=1;
		F[total_prime++]=ftemp;
	}
}
int main(int argc, char** argv) {
	int i,j;
	fill(pri,pri+MAXV,1);
	scanf("%d",&n);
	int temp=n;
	if(n==1)
	{
		printf("1=1");
		return 0;
	}  
	findprime();
	search();
	
	for(i=0;i<total_prime;i++)
	{
		if(i==0)
		{
			if(F[i].count==1)
			{
				printf("%d=%d",temp,F[i].data);
			}
			if(F[i].count>1)
			{
				printf("%d=%d^%d",temp,F[i].data,F[i].count);
			}
		}
		else
		{
			if(F[i].count==1)
			{
				printf("*%d",F[i].data);
			}
			if(F[i].count>1)
			{
				printf("*%d^%d",F[i].data,F[i].count);
			}
		}
	}
	return 0;
}
