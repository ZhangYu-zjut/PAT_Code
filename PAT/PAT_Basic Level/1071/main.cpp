
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("test.txt", "r", stdin);
	int t, k;
	int i, j, n;
	int total;
	int n1, n2,b;
	//printf("hell"); 
	while (scanf("%d%d", &total,&n) != EOF)
	{
		for (i = 0;i < n;i++)
		{
			bool win = false;
			bool left=true;
			scanf("%d%d%d%d", &n1, &b, &t,&n2);
			if (total < t)
			{
				printf("Not enough tokens.  Total = %d.\n",total);
			}
			else
			{
				if ((n2 < n1&&b == 0) || (n2 > n1 && b == 1))
				{
					total += t;
					printf("Win %d!  Total = %d.\n", t, total);
				}
				else
				{
					total -= t;
					printf("Lose %d.  Total = %d.\n", t, total);
					if (total == 0)
					{
						printf("Game Over.\n");
						return 0;
					}
				}
			}
		}

	}
	return 0;
}
