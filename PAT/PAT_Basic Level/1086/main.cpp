#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//������Ҫע��һЩ�ӣ�
//����25 4�Ժ����Ϊ1.Ҫ��ԭ����001�е�ǰ����ȥ����
//���⣬������5 1010�����ӦΪ505.����һ��ǰ����ȥ�����ڶ����㱣���� 
int num[10];
int main(int argc, char** argv) {
	int a,b,sum;
	scanf("%d%d",&a,&b);
	sum = a*b;
	int i=0,j;
	int size=0;
	bool first=true;
	while(1)
	{
		int temp=sum%10;
		while(temp==0&&first==true)
		{
			sum=sum/10;
			temp=sum%10;
		} 
		first=false;
		num[i]=temp;
		sum/=10;
		i++;
		size++;
		if(sum<1)
		{
			break;
		}
	}
	for(j=0;j<size;j++)
	{
		printf("%d",num[j]);
	}
	return 0;
}
