#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//注意：判断是否在同一斜线上的方法是：判断两个点横坐标与横坐标之差是否等于纵坐标与纵坐标之差
//abs(num[a]-num[b])==abs(a-b)
//AC!!
int num[1003];
int temp[1003]; 
int judge[2003]={0}; 
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int k,n,t;
	scanf("%d",&n);
	int i,j;
	
	for(i=0;i<n;i++)
	{
		bool jud=true;
		scanf("%d",&k);
		for(j=1;j<=2002;j++)
		{
			judge[j]=0;
		}
		for(j=1;j<=k;j++)
		{
			scanf("%d",&num[j]);
			
		}
		for(j=1;j<=k;j++)
		{
			for(t=j+1;t<=k;t++)
			{
				if((abs(j-t)==abs(num[j]-num[t])||num[t]==num[j])&&jud==true)//
				{
					printf("NO\n");
					jud=false;
					break;
				}
			}
		}
		if(jud==true)printf("YES\n");
		
	}
	return 0;
}
