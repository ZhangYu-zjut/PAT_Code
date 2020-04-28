// wd36.cpp : 定义控制台应用程序的入口点。
//



// WD36.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define debug 1
struct goods
{
	int beans;
	int cost;
	double cost_per;
	int obtain;
	bool buy;
}god[1002];

bool cmp(goods a, goods b)
{
	return a.cost_per>b.cost_per;
}
int main(int argc, char** argv) {
	freopen("test.txt", "r", stdin);
	int n, m;
	while (scanf("%d%d", &m, &n))
	{
		int i, j;
		if (m ==-1 && n == -1)
		{
			break;
		}
		else
		{
			for (i = 0;i<n;i++)
			{
				scanf("%d%d", &god[i].beans, &god[i].cost);
				god[i].cost_per = 1.0*god[i].beans / god[i].cost;
				god[i].buy = false;
			}
			sort(god, god + n, cmp);
			int sum = 0;
			double bean = 0;
			for (i = 0;i<n;i++)
			{
				if (god[i].cost + sum <= m)
				{
					sum = sum + god[i].cost;
					bean += god[i].beans;
					god[i].buy = true;
					god[i].obtain = god[i].cost;
				}
				else
				{
					god[i].buy = true;
					god[i].obtain = (m - sum);
					sum += god[i].obtain;
					bean += ((double(god[i].obtain) / double(god[i].cost))*double(god[i].beans));
					break;
				}
			}
			printf("%.3lf\n", bean);
		}

	}

	return 0;
}

