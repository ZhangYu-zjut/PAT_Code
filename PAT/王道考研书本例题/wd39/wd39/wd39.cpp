// wd39.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define debug 1
struct tvprogram
{
	int start;
	int end;

}tv[110];
bool cmp(tvprogram a, tvprogram b)
{
	return a.end < b.end;
}
int main()
{
	freopen("test.txt","r",stdin);
	int n, i, j;
	while (scanf("%d",&n))
	{
		if (n == 0)
		{
			break;
		}
		else
		{
			for (i = 0; i < n; i++)
			{
				scanf("%d%d", &tv[i].start, &tv[i].end);
			}
			sort(tv, tv + n, cmp);
			int count = 0;
			int end_temp = 0;
			for ( i = 0; i < n; i++)
			{
				if (tv[i].start>=end_temp)
				{
					end_temp = tv[i].end;
					count++;
				}
			}
			printf("%d\n",count);
		}
		
	}
    return 0;
}

