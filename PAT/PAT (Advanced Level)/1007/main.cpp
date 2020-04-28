#include <iostream>
#include <stdio.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int num[10004];
int dp[10004];
int index=0;
int st[10004];//st[i]表示以i为结尾的序列的开始节点序号 
//动态规划进行完成，利用st[]存放各个结尾序列的开始序号 
//together with the first and the last numbers of the maximum subsequence. 
//输出子序列的第一个和最后一个数字，不是下标！！！
//AC!!! 
int choose(int a,int b,int i)
{
	if(a>=b)//当dp[i-1]+num[i]>num[i]时，st[i]跟之前的一样，保持不变。 
	{
		st[i]=index;
		return a;
	}
	else//当dp[i-1]+num[i]<num[i]时，子序列冲num[i]到num[i]，st[i]变化，与i一致。 
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
