#include <iostream>
#include <stdio.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define N 1000 
struct stu
{
	char num[14];
	int test;
	int exam;
}Stu[N];
int search[N];
int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		scanf("%s%d%d",Stu[i].num,&Stu[i].test,&Stu[i].exam);
	}
	int m;
	scanf("%d",&m);
	for(j=0;j<m;j++)
	{
		scanf("%d",&search[j]);
		for(k=0;k<n;k++)
		{
			if(Stu[k].test==search[j])
			{
				printf("%s %d\n",Stu[k].num,Stu[k].exam);
			}
		}	
	} 
	return 0;
}
