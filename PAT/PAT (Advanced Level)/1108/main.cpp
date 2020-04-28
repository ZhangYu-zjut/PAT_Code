#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//简单题目，注意题目的各个条件即可 
//AC!!!
string str[101];
double num[101];
bool check(string str)
{
	
	int n = str.length();
	int index = -1;
	bool judge = true;
	int count = 0;
	int point_after = 0;
	bool negative = false;
	for (int i = 0;i<n;i++)
	{
		if (i == 0)
		{
			if (str[0] >= '0' || str[0] <= '9')
			{
				continue;
			}
			else if (str[0] == '-')
			{
				negative == true;
			}
			else
			{
				judge = false;
				return judge;
			}
		}
		if (i>0)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				if (index == -1)continue;
				else
				{
					point_after++;
					if (point_after>2)return false;
				}
			}
			else if (str[i] == '.')
			{
				index = i;
				count++;
				if (count == 2)return false;
			}
			else
			{
				judge = false;
				return judge;
			}
		}
	}
	return true;
}
int main(int argc, char** argv) {
	int m, i, j, k = 0, n;
	double sum = 0.0;
	int num_count = 0;
	scanf("%d", &n);
	for (i = 0;i<n;i++)
	{
		cin >> str[i];
		if (check(str[i]))
		{
			double temp= atof(str[i].c_str());
			if (temp>=-1000&&temp<=1000)
			{
				num[k] = atof(str[i].c_str());
				k++;
				num_count++;
			}
			else
			{
				cout << "ERROR: " << str[i] << " is not a legal number" << endl;
			}
		}
		else
		{
			cout << "ERROR: " << str[i] << " is not a legal number" << endl;
		}
	}
	if (num_count == 0)
	{
		cout << "The average of 0 numbers is Undefined" << endl;
	}
	else if (num_count == 1)
	{
		printf("The average of 1 number is %.2lf\n", num[0]);
	}
	else
	{
		for (i = 0;i<k;i++)
		{
			sum += num[i];
		}
		printf("The average of %d numbers is %.2lf\n", k, sum / k);
	}


	return 0;
}
