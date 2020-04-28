#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//利用动态规划的思想求解！！ 
//最后一个测试点竟然跟大小有关
//cin.getline(str,1000);不过 
//cin.getline(str,1001);通过 
//因为最大有1000个字符，字符后面还有一个结束符，所以最大要读1001个字符 ！！！ 
int dp[1010][1010];
char str[1010];
int main(int argc, char** argv) {
	cin.getline(str,1005);//要这样使用！！！ 
	//gets(str);//这句话在编译器中不能通过 
	int length=strlen(str);
	fill(dp[0],dp[0]+length*length,0);
	int i,j;
	int ans=1;
	for(i=0;i<length;i++)
	{
		dp[i][i]=1;
		if(i<length-1)
		{
			if(str[i]==str[i+1])
			{
				dp[i][i+1]=1;
				ans=2;
			}
		}
	}
	for(int L=3;L<=length;L++)//根据字符数组的大小来 
	{
		for(i=0;i+L-1<length;i++)
		{
			j=i+L-1;
			if(str[i]==str[j]&&dp[i+1][j-1]==1)
			{
				dp[i][j]=1;
				ans=L;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
