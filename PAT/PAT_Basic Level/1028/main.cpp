
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct person
{
	char name[6];
	int year;
	int month;
	int day;
}p[100010];
char temp[1000];
bool judge(int year, int month, int day)
{
	if (year >= 2015)
	{
		return false;
	}
	if (year == 2014 && month > 9)
	{
		return false;
	}
	if (year == 2014&&month==9&&day>6)
	{
		return false;
	}
	if (year < 1814)
	{
		return false;
	}
	if (year == 1814 && month < 9)
	{
		return false;
	}
	if (year == 1814 && month == 9 && day<6)
	{
		return false;
	}
	return true;
}
bool cmp(person a, person b)
{
	if (a.year != b.year)
	{
		return a.year < b.year;
	}
	else
	{
		if (a.month != b.month)
		{
			return a.month < b.month;
		}
		else
		{
			return a.day < b.day;
		}
	}
}
int main(int argc, char** argv) {
	freopen("test.txt", "r", stdin);
	int i, j, k, n;
	//printf("hell"); 
	while (scanf("%d", &n) != EOF)
	{
		int count = 0;
		int old = 0;
		int young = 0;

		for (i = 0;i<n;i++)
		{
			scanf("%s %s", p[i].name, temp);
			int g = 0;
			int second=0;
			int a1 = 0;
			int a2 = 0;
			int length = strlen(temp);
			char cs = '/';
				bool find = false;
			while (find == false)
			{
				if (temp[g] == '/'&&second == 1)
				{
					a2 = g;
					second++;
					find = true;
				}
				if (temp[g] == '/'&&second==0)
				{
					a1 = g;
					second++;
				}
				
				g++;
			}
			//printf("temp is%d %d\n", a1, a2);
			int year = 0;
			int month = 0;
			int day = 0;
			int c = 1;
			for (j = a1-1;j>=0;j--)
			{
				year += (temp[j] - '0')*c;
				c *= 10;
			}
			//printf("year is%d \n", year);
			c = 1;
			for (j = a2-1;j>(a1);j--)
			{
				month += (temp[j] - '0')*c;
				c *= 10;
			}
			//printf("month is%d \n", month);
			c = 1;
			for (j = length-1;j>(a2);j--)
			{
				day += (temp[j] - '0')*c;
				c *= 10;
			}
			//printf("day is%d \n", day);
			if (judge(year, month, day))
			{
				p[count].year = year;
				p[count].month = month;
				p[count].day = day;
				count++;
			}
			
			//if ()
				//printf("%s %d %d %d", p[i].name, p[i].year, p[i].month, p[i].day);
		}
		sort(p, p + count, cmp);
		printf("%d %s %s", count, p[0].name, p[count - 1].name);

	}
	return 0;
}
