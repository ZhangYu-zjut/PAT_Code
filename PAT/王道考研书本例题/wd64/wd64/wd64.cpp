// wd64.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>


using namespace std;
int main()
{
	int n, i, j;
	char str1[100];
	char str2[100];
	int ans;
	int a, b;
	int num1[100], num2[100];
	//方法一，数位拆解
	while (scanf("%d %d", &a,&b) != EOF)
	{
		ans = 0;
		int size1 = 0;
		int size2 = 0;
		while (a != 0)
		{
			num1[size1] = a%10;
			a = a / 10;
			size1++;
		}
		while (b != 0)
		{
			num2[size2] =b % 10;
			b = b / 10;
			size2++;
		}
		for (i = 0;i < size1;i++)
		{
			for (j = 0;j < size2;j++)
			{
				ans += num1[i]*num2[j];
			}

		}
		printf("%d\n", ans);
	}
	//方法二，看作字符直接相乘
	/*
	while (scanf("%s %s",str1, str2)!=EOF)
	{
		ans = 0;
		for (i = 0;str1[i]!=0;i++)
		{
			for (j = 0;str2[j] != 0;j++)
			{
				ans += (str1[i]-'0')*(str2[j] - '0');
			}
		}
		printf("%d\n",ans);
	}
	*/
    return 0;
}

