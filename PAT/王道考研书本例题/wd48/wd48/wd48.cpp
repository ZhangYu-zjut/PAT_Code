// wd48.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <queue> 
#include <functional>
using namespace std;
int num[1010];
int main()
{
	freopen("test.txt","r",stdin);
	priority_queue <int,vector<int>,greater<int> >q;
	int n,i,j,sum,a,b;
	
	while (scanf("%d", &n) != EOF)
	{
		sum = 0;
		for (i = 0;i < n;i++)
		{
			scanf("%d", &num[i]);
			q.push(num[i]);
		}
		while (1)
		{
			a = q.top();
			q.pop();
			if (q.empty() == true)
			{
				printf("%d\n", sum);
				break;
			}
			else
			{
				b = q.top();
				q.pop();
				q.push(a+b);
				sum += (a+b);
			}
		}	
	}
    return 0;
}

