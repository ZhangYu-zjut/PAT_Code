#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char str[20];
int weight[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char check[]={'1','0','X','9','8','7','6','5','4','3','2'};
bool mark[120];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n,i,j,k;
	int sum=100;
	while(scanf("%d",&n)!=EOF)
	{
		bool all_check=true;
		for(i=0;i<n;i++)
		{
			int total=0;
			scanf("%s",str);
			mark[i]=true;
			for(j=0;j<strlen(str);j++)
			{
				if(j<strlen(str)-1)
				{
					if(str[j]>='0'&&str[j]<='9')
					{
						total+=(str[j]-'0')*weight[j];
					}
					if(str[j]<'0'||str[j]>'9')
					{
						mark[i]=false;
						break;
					}
				}
				else
				{
					if(str[j]!=check[total%11])
					{
						mark[i]=false;
						break;
					}
				}
			}
			if(mark[i]==false)
			{
				printf("%s\n",str);
				all_check=false;
			}
			if(i==n-1&&all_check==true)
			{
				printf("All passed\n");
			}
		}
	}
	
	return 0;
}
