//#include <iostream> 
#include <stdio.h>
//#include <algorithm>
#define N 10000
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct person
{
	char id[4];
	int x,y;
	int dis;
}P[N];
int distance(int x,int y)
{
	return (x*x+y*y);
};

bool cmp(person a,person b)
{
	return a.dis<b.dis;
};
int main(int argc, char** argv) {
	int n;
	int x,y;
	int a,b;
	scanf("%d",&n);
	int i=0;
	int k=n;
	while(n--)
	{
		scanf("%s",P[i].id);
		scanf("%d%d",&P[i].x,&P[i].y);
		P[i].dis=distance(P[i].x,P[i].y);
		i++;
	}
	sort(P,P+k,cmp);
	printf("%s %s",P[0].id,P[k-1].id);
	
	return 0;
}
