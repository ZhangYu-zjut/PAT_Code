#include <iostream>
#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//暴力求解会超时
//PAT是对称的，并且A恰好在中间的位置
//可以找到某个A左边的P个数，右边的T个数，两者相乘就是含有这个A的PAT个数
//只需要多个一重循环就可以计算出结果，降低了时间复杂度！！ 
//AC!!!
char ch[100005];
int rightt[100005];
int leftp[100005];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	while(scanf("%s",ch)!=EOF)
	{
		int length=strlen(ch);
		int i,j;
		int countp=0;
		for(i=0;i<length;i++)
		{
		
			if(ch[i]=='P')
			{
				countp++;
			}
			if(ch[i]=='A')
			{
				leftp[i]=countp;
			}
		} 
		int countt=0;
		for(i=length-1;i>=0;i--)
		{
			if(ch[i]=='T')
			{
				countt++;
			}
			if(ch[i]=='A')
			{
				rightt[i]=countt;
			}
		}
		long long sum=0;
		for(i=0;i<length;i++)
		{
			if(ch[i]=='A')
			{
				sum+=leftp[i]*rightt[i];
			}
		}	
		printf("%lld\n",sum%1000000007);//注意题目说的，很大时候取模 
	} 
	return 0;
}
