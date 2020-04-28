#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define debug 1 
int prime[100010];//������� 
bool mark[100010];//�ж��Ƿ�Ϊ���� 
int primesize;//��¼�����ĸ��� 
void init()//����ɸѡ�� 
{
	primesize=0;
	int i,j;
	for(i=0;i<=100000;i++)
	{
		mark[i]=true;//��ʼ����Ϊ�������� 
	}
	for(i=2;i<=100000;i++)
	{
		if(mark[i]==false)continue; //���������Ͳ��ô���  
		prime[primesize++]=i;
		if(i>1000)continue;//j=i*i.ҪС��10^5,����i��1000�Ϳ��Խ����ˡ������ѭ����û�������,�����ܻ����Խ�硣 
		for(j=i*i;j<=100000;j+=i)//�������ͱ�� 
		{			
			mark[j] = false;
		}
	}
}

int main(int argc, char** argv) {
	int ansnum[50];//������� 
	int anssize[50];//���ÿ����������ָ�� 
	int length;//��ͬ�����ӵĸ��� 
	int ans;//������Ľ�� 
	int n,i,j;
	//�㷨���̣�
	//1.��ȡN��
	//2.���С��N��������������
	//3.��N���Ը�������������ȡ������������ָ���� 
	//4.ָ����ӣ�������Ľ��
	while(scanf("%d",&n)!=EOF)
	{
		init();
		ans=0;
		length=0;
		for(i=0;i<primesize;i++)
		{

			if(n%prime[i]==0)//�ж��������n�ܷ�ĳ������������ 
			{
				anssize[length]=0;
				while(n%prime[i]==0)
				{
					ansnum[length]=prime[i];
					anssize[length]++;
					n=n/prime[i];	
					#if debug
					printf("prime[i] is:%d\n",prime[i]);	
					#endif			
				}
				length++;//��仰ֻ�ܷ����������ĳһ��������������֮�󣬶�length+1��			
			}	
			if(n==1)
			{
				break;
			}
		} 
		if(n!=1)
		{
			ansnum[length]=n;
			anssize[length]=1;
		}
		for(i=0;i<length;i++)
		{
			ans+=anssize[i];
			#if debug
			printf("size is:%d\n",anssize[i]); 
			#endif
		}
		printf("%d\n",ans);
	}
	return 0;
}
