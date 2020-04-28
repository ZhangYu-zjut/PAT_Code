#include <iostream>
#include <stdio.h>
#include <algorithm>
#define N 10000
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//将甲从99开始查找，能否找到满足四个条件的。 
void cmp(double x,double y)
{
	if(x==y)
	{
		printf(" Ping");
	}
	if(x>y)
	{
		printf(" Gai");
	}
	if(x<y)
	{
		printf(" Cong");
	}
	
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int a,b,x,y,m;
	int i,j,k;
	int jia,yi;
	double bing; 
	double c;
	while(scanf("%d%d%d",&m,&x,&y)!=EOF)
	{
		bool find=false;
		for(jia=99;jia>9;jia--){
	        yi=(jia%10)*10+jia/10;
	        bing=(double)abs(jia-yi)/x;
	        if(yi==y*bing) 
			{
				find=true;
				break;
			}
    	}
		if(find==true)
		{
			printf("%d",jia);
			cmp(m,jia);
			cmp(m,yi);
			cmp(m,bing);
			printf("\n");
		}
		else
		{
			printf("No Solution\n");
		}

	}
	 
	return 0;
}
