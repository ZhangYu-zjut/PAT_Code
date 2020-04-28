#include <iostream>
#include <stdio.H>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//WD160 À¹½Øµ¼µ¯ AC!!! 
int num[30];
int F[30];
int temp[30];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	F[0]=1;
	int x;
	for(i=1;i<n;i++)
	{
		int k=0;
		bool find=false;
		for(j=0;j<i;j++)
		{
			if(num[i]<=num[j])
			{
				find=true;
				temp[k]=F[j]+1;
				k++;
			}
		}
		int max=0;
		for(x=0;x<k;x++)
		{
			if(temp[x]>max)
			{
				max=temp[x];
			}
		}
		find==true?F[i]=max:F[i]=1;
	}
	int ans=0; 
	for(i=1;i<n;i++)
	{
		if(F[i]>ans)
		{
			ans=F[i];
		}
	}
	printf("%d",ans);
	return 0;
}
