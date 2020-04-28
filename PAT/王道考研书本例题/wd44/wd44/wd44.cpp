// wd44.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stack>

using namespace std;
int priority[][5] = {
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0
};
char str[300];
void getop()
{

}
int main()
{
	freopen("test.txt","r",stdin);
	stack<double>num;
	stack<int>op;
	int n, i, j, top;
	double temp;
	double a,b;
	double result;
	while(scanf("%s",str))
	{
		if (str[0] == '0'&&str[1] == 0)
		{
			break;
		}
		op.push(0);
		for (i=0;str[i]!=0;i++)
		{
			if (str[i] != ' ')
			{
				if (str[i] <= '9'&&str[i] >= '0')
				{
					num.push(str[i]-'0');
				}
				if (str[i] == '+')
				{
					while(1)
					{
						top = op.top();
						if (priority[top][1] == 1)
						{
							op.push(1);
							break;
						}
						if (priority[top][1] == 0)
						{
							a = num.top();
							num.pop();
							b = num.top();
							num.pop();
							if (top == 3)
							{
								temp = a*b;
								num.push(temp);
							}
							if (top == 4)
							{
								temp = a / b;
								num.push(temp);
							}
							op.pop();
						}
					}
				
				}
				if (str[i] == '-')
				{
					while (1)
					{
						top = op.top();
						if (priority[top][2] == 1)
						{
							op.push(2);
							break;
						}
						if (priority[top][2] == 0)
						{
							a = num.top();
							num.pop();
							b = num.top();
							num.pop();
							if (top == 3)
							{
								temp = a*b;
								num.push(temp);
							}
							if (top == 4)
							{
								temp = a / b;
								num.push(temp);
							}
							op.pop();
						}
					}

				}
				if (str[i] == '*')
				{
					while (1)
					{
						top = op.top();
						if (priority[top][3] == 1)
						{
							op.push(3);
							break;
						}
						if (priority[top][3] == 0)
						{
							a = num.top();
							num.pop();
							b = num.top();
							num.pop();
							if (top == 3)
							{
								temp = a*b;
								num.push(temp);
							}
							if (top == 4)
							{
								temp = a / b;
								num.push(temp);
							}
							op.pop();
						}
					}

				}
				if (str[i] == '/')
				{
					while (1)
					{
						top = op.top();
						if (priority[top][2] == 1)
						{
							op.push(4);
							break;
						}
						if (priority[top][2] == 0)
						{
							a = num.top();
							num.pop();
							b = num.top();
							num.pop();
							if (top == 3)
							{
								temp = a*b;
								num.push(temp);
							}
							if (top == 4)
							{
								temp = a / b;
								num.push(temp);
							}
							op.pop();
						}
					}
				}

			}

		}
		result = num.top();
		printf("%.2f",result);
		while (num.empty() == false)
		{
			num.pop();
		}
		while (op.empty() == false)
		{
			op.pop();
		}
			
	}

    return 0;
}

