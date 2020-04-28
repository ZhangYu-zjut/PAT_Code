#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct test
{
	int score;
	int choice;
	int right;
	char ans[6];
}t[110];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n,m;
	int i,j,k;
	char ch;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&t[i].score,&t[i].choice,&t[i].right);
			k=0;
			while((ch=getchar())!='\n')
			{
				if(ch>='a'&&ch<='h')
				{
					t[i].ans[k]=ch;
					k++;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			
		}
	}
	return 0;
}
