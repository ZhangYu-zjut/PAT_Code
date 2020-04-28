#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//简单题，注意系数为0的情况。AC!! 
struct node
{
	int exp;
	double coff;
}
a[20];
node b[20],c[30];
bool cmp(node x,node y)
{
	return x.exp>y.exp;
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n,m,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%lf",&a[i].exp,&a[i].coff);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%lf",&b[i].exp,&b[i].coff);
	}
	sort(a,a+n,cmp);
	sort(b,b+m,cmp);
	int a1=0,b1=0,c1=0;
	while(a1<n&&b1<m)
	{
		if(a[a1].exp==b[b1].exp)
		{
			double temp=a[a1].coff+b[b1].coff;
			if(temp!=0)
			{
				c[c1].exp=a[a1].exp;
				c[c1].coff=temp;
				c1++;
			}
			a1++;
			b1++;
		}
		else if(a[a1].exp>b[b1].exp)
		{
			c[c1].exp=a[a1].exp;
			c[c1].coff=a[a1].coff;
			c1++;
			a1++;
		}
		else
		{
			c[c1].exp=b[b1].exp;
			c[c1].coff=b[b1].coff;
			c1++;
			b1++;
		}
	}
	while(a1<n)
	{
		c[c1].exp=a[a1].exp;
		c[c1].coff=a[a1].coff;
		c1++;
		a1++;
	}
	while(b1<m)
	{
		c[c1].exp=b[b1].exp;
		c[c1].coff=b[b1].coff;
		c1++;
		b1++;
	}
	printf("%d",c1);
	for(i=0;i<c1;i++){
		printf(" %d %.1lf",c[i].exp,c[i].coff);
	}
	return 0;
}
