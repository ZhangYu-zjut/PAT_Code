#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//���ö�̬�滮��˼����⣡�� 
//���һ�����Ե㾹Ȼ����С�й�
//cin.getline(str,1000);���� 
//cin.getline(str,1001);ͨ�� 
//��Ϊ�����1000���ַ����ַ����滹��һ�����������������Ҫ��1001���ַ� ������ 
int dp[1010][1010];
char str[1010];
int main(int argc, char** argv) {
	cin.getline(str,1005);//Ҫ����ʹ�ã����� 
	//gets(str);//��仰�ڱ������в���ͨ�� 
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
	for(int L=3;L<=length;L++)//�����ַ�����Ĵ�С�� 
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
