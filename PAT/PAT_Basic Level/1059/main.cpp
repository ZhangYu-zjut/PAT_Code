#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student
{
	char id[5];
	int rank;
	bool prime;
	bool check = false;
	bool prime_judge(int x)
	{
		for (int i = 2;i <= sqrt(x) + 1;i++)
		{
			if (x%i == 0)
			{
				return false;
			}
		}
		return true;
	}
}stu[10010];
bool equal(char a[],char b[])
{
	if(strlen(a)!=strlen(b))
	{
		return false;
	}
	else
	{
		for(int i=0;i<strlen(a);i++)
		{
			if(a[i]!=b[i])
			{
				return false;
			}
		}
		return true;
	}
} 
int main(int argc, char** argv) {
	freopen("test.txt", "r", stdin);
	int n;
	int i, j, k;
	char str[8];
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1;i <= n;i++)
		{
			scanf("%s",stu[i].id);
			stu[i].rank = i;
			stu[i].prime = stu[i].prime_judge(stu[i].rank);
		}
		scanf("%d", &k);

		for (i = 1;i <= k;i++)
		{
			scanf("%s",str);
			bool find = false;
			for (j = 1;j <= n;j++)
			{
				if (equal(str,stu[j].id))
				{
					if (stu[j].check == true)
					{						
						printf("%s: Checked\n",str);
					}
					if (stu[j].check == false && stu[j].rank == 1)
					{
						printf("%s: Mystery Award\n",str);
						stu[j].check = true;
					}
					if (stu[j].check == false && stu[j].rank>1 && stu[j].prime == true)
					{
						printf("%s: Minion\n",str);
						stu[j].check = true;
					}
					if (stu[j].check == false && stu[j].rank>1 && stu[j].prime == false)
					{
						printf("%s: Chocolate\n",str);
						stu[j].check = true;
					}
					find = true;
				}
			}
			if (find == false)
			{
				//cout << str << ": " << "Are you kidding?" << endl;
				printf("%s: are you kidding?\n",str);
				
			}
		}

	}
	return 0;
}
