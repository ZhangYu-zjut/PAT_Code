// wd43.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <stack>
#include <string>
using namespace std;

char str[110];
char output[110];
int main()
{
	stack<int> s;
	while (scanf("%s",str)!=EOF)
	{
		int n = strlen(str);
		int i, j;
		for (i = 0;str[i] != 0;i++)
		{
			output[i] = ' ';
		}
		for (i=0;str[i]!=0;i++)
		{
			if (str[i]=='(')
			{
				s.push(i);
			}
			if (str[i] == ')')
			{
				if (s.empty() == true)
				{
					output[i] = '?';
				}
				else
				{
					s.pop();
				}				
			}
		}
		for (i = 0;str[i] != 0;i++)
		{
			if (s.empty() == false)
			{
				int k = s.top();
				output[k] = '$';
			}

		}
		for (i = 0;str[i] != 0;i++)
		{
			printf("%c",output[i]);
		}
		printf("\n");
	}
	int n;
    return 0;
}

