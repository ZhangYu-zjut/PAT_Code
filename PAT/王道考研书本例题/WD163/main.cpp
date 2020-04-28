#include <iostream>
#include <stdio.h> 
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//最长公共子序列，利用递推关系式进行求解
//AC!!!! 
char str1[105];
char str2[105];
int dp[200][200];
int max(int x,int y){
	return x>y?x:y;
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin); 
	scanf("%s%s",str1,str2);
	int size1=strlen(str1);
	int size2=strlen(str2);
	int i,j,k;
	for(i=0;i<size1;i++)dp[i][0]=0;
	for(j=0;j<size2;j++)dp[0][j]=0;
	for(i=1;i<size1;i++)
	{
		for(j=1;j<size2;j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	printf("%d",dp[size1-1][size2-1]);
	return 0;
}
