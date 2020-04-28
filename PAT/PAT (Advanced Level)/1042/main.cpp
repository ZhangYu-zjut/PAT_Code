
#include <iostream>
#include <stdio.h>
#include  <vector>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//题目本身不复杂，但是边界情况和细节需要考虑清楚，比较费时间
//AC!!!
string v[22][55];//用向量在赋值的时候会出错，所有用数组！！！ 
int num[22][55];
char ch[] = { 'S','H','C','D' };
int main(int argc, char** argv) {
	freopen("test.txt", "r", stdin);
	int n, i, j, k;
	string temp = "";
	stringstream ss;
	string s = "SHCD";
	scanf("%d", &k);
	int flag;
	for (i = 1;i <= 52;i++)
	{
		int g = i;
		if (g % 13 == 0)//为0情况要特殊考虑！！！！ 
		{
			temp = s[i / 13-1] + to_string(13);
		}
		else
		{
			temp = s[i / 13] + to_string(i % 13);
		}`
		v[0][i] = temp;
	}
	v[0][53] = "J1";
	v[0][54] = "J2";
	for (i = 1;i <= 54;i++)
	{
		scanf("%d", &num[0][i]);
	}
	for (i = 1;i <=k;i++)
	{
		for (j = 1;j <= 54;j++)
		{
			v[i][num[0][j]] = v[i - 1][j];
		}
	}
	for (j = 1;j <= 54;j++)
	{
		if (j == 1)cout << v[k][j];
		else cout << " " << v[k][j];
	}
	return 0;
}
