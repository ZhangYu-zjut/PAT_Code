#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int num[10010];
int temp[10010];
int main(int argc, char** argv) {
	int i,n,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp[i]);
		num[temp[i]]++;
	}
	for(i=0;i<n;i++)
	{
		if(num[temp[i]]==1)
		{
			printf("%d\n",temp[i]);
			return 0;
		}
	}
	printf("None\n");
	return 0;
}
