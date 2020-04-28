// PAT_Btest.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>
#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PAT_B1018 AC!!!
struct person
{
	int win;
	int equal;
	int lose;
	int B;//记录剪刀石头布分别获胜的次数 
	int C;
	int J;
	int final;
	char cmp()
	{
		char max;
		if (B >= C)
		{
			max = 'B';
			if (J>B)
			{
				max = 'J';
			}
		}
		else//C>B
		{
			max = 'C';
			if (J>C)
			{
				max = 'J';
			}
		}
		return max;

	}
}A, B;

int main(int argc, char** argv) {
	int n, i, j;
	scanf("%d", &n);
	char a[2], b[2];
	A.win = A.lose = A.equal = 0;
	B.win = B.lose = B.equal = 0;
	A.B = A.C = A.J = 0;
	B.B = B.C = B.J = 0;
	for (i = 0;i<n;i++)
	{
		scanf("%s %s", a, b);
		if ((a[0] == 'J'&&b[0] == 'B'))
		{
			A.win++;
			B.lose++;
			A.J++;
		}
		if ((a[0] == 'B'&&b[0] == 'C'))
		{
			A.win++;
			B.lose++;
			A.B++;
		}
		if ((a[0] == 'C'&&b[0] == 'J'))
		{
			A.win++;
			B.lose++;
			A.C++;
		}
		if ((b[0] == 'J'&&a[0] == 'B'))
		{
			B.win++;
			A.lose++;
			B.J++;
		}
		if ((b[0] == 'B'&&a[0] == 'C'))
		{
			B.win++;
			A.lose++;
			B.B++;
		}
		if ((b[0] == 'C'&&a[0] == 'J'))
		{
			B.win++;
			A.lose++;
			B.C++;
		}
		if (a[0] == b[0])
		{
			A.equal++;
			B.equal++;
		}
	}
	printf("%d %d %d\n", A.win, A.equal, A.lose);
	printf("%d %d %d\n", B.win, B.equal, B.lose);
	char temp1= A.cmp(), temp2= B.cmp();
	printf("%c %c",temp1,temp2);
	return 0;
}
