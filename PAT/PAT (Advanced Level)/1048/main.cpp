#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�����������뷨������������������ʱ
//����һ��˼·�������һ��������ÿ�����ֳ��ֵĴ�����ֱ�ӱȽ�num[i]��num[m-i]����ֵ�Ƿ����0 
//ע�����������Ŀ���Ϊ14��������������ֻ��һ��7. 
int num[100100]={0};
int main(int argc, char** argv) {
	int n,m,i,j,k,temp;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		num[temp]++;
	}
	for(i=0;i<1001;i++)//num[i]>0���п��������Ĵ� 
	{
		if(num[i]>0)
		{
			num[i]--;//���Լ�һ 
			if(num[m-i]>0&&m>i)//m>i��仰û��Ҳ���ԣ���Ϊ��i>mʱ��num[i]����0�������Ľ����Ӱ�� 
			{
				printf("%d %d\n",i,m-i);
				return 0;
			}
			num[i]++;
		}
	}
	printf("No Solution\n");
	return 0;
}
