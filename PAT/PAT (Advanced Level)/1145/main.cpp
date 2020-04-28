#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//ע�⣺��key���в���ʱ��ÿ�β��ҵ�ʱ���һ�����ҵ����Լ�ͬ�������֣������ҵ��ĵط�����Ϊ0��������ѭ������
//��Ҫô�ҵ���Ӧ��ֵ��Ҫô��Ӧ�ĵط�û��ֵ���� 
bool hashtable[100004];
int num[100004];
int num2[100004];
bool isprime(int x)
{
	if(x==1)return false;
	int temp=sqrt(1.0*x);
	for(int i=2;i<=temp;i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int m,n;
	int i,j,k;
	scanf("%d%d%d",&m,&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	int length;
	while(!isprime(m))
	{
		m++;
	}
	fill(hashtable,hashtable+100000,0);
	fill(num2,num2+100000,0);
	for(i=0;i<n;i++)
	{
		bool find=false;
		for(j=0;j<=m;j++)
		{
			if(hashtable[(num[i]+j*j)%m]==false)
			{
				num2[(num[i]+j*j)%m]=num[i];
				hashtable[(num[i]+j*j)%m]=true;
				find=true;
				break;
			}
		}
		if(!find)
		{
			printf("%d cannot be inserted.\n",num[i]);
		}
	}
	int sum=0,temp;
	double ans=0.0;
	for(i=0;i<k;i++)
	{
		scanf("%d",&temp);
		bool find2=false;
		for(j=0;j<=m;j++)
		{
			sum++;
			if(num2[(temp+j*j)%m]==temp||num2[(temp+j*j)%m]==0)//���������������Ҫ������ 
			{
				find2=true;
				break;
			}
		}
	}
	ans=1.0*sum/k;
	printf("%.1lf",ans);
	return 0;
}
