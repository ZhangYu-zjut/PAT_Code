#include <iostream>
#include <stdio.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int num[10004];
int dp[10004];
int index=0;
int st[10004];//st[i]��ʾ��iΪ��β�����еĿ�ʼ�ڵ���� 
//��̬�滮������ɣ�����st[]��Ÿ�����β���еĿ�ʼ��� 
//together with the first and the last numbers of the maximum subsequence. 
//��������еĵ�һ�������һ�����֣������±꣡����
//AC!!! 
int choose(int a,int b,int i)
{
	if(a>=b)//��dp[i-1]+num[i]>num[i]ʱ��st[i]��֮ǰ��һ�������ֲ��䡣 
	{
		st[i]=index;
		return a;
	}
	else//��dp[i-1]+num[i]<num[i]ʱ�������г�num[i]��num[i]��st[i]�仯����iһ�¡� 
	{
		index=i;
		st[i]=index;
		return b;
	}
}

int main(int argc, char** argv) {
	int n,ed;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	dp[0]=num[0];
	for(i=1;i<n;i++)
	{
		dp[i]=choose(dp[i-1]+num[i],num[i],i);
	}
	int max_sum=-1;
	for(i=0;i<n;i++)
	{
		if(dp[i]>max_sum)
		{
			
			max_sum=dp[i];
			ed=i;
			//printf("i is:%d max_sum is:%d ed is:%d\n",i,max_sum,ed);
		}
	}
	if(max_sum==-1)
	{
		printf("%d %d %d",0,num[0],num[n-1]);
	}
	else
	{
		printf("%d %d %d",max_sum,num[st[ed]],num[ed]);
	}
	return 0;
}
