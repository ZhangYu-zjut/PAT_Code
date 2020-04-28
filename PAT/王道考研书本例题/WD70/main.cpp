#include <iostream>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <stdio.h>
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int a,b;
	int i,j;
	char str[50];
	int ans[50];
	while(scanf("%d %s %d",&a,str,&b)!=EOF)
	{
		int sum = 0;
		int temp;
		int length = strlen(str);
		int c=1;//ЦёКэПо 
		for(i=length-1;i>=0;i--)//tranfer into decimal
		{
			int x;
			if(str[i]>='0'&&str[i]<='9')
			{
				x = str[i]-'0';
			}
			else if(str[i]>='a'&&str[i]<='f')
			{
				x = str[i]-'a'+10;
			}
			else
			{
				x = str[i]-'A'+10;
			}
			
			temp = (x)*c;
			sum += temp;
			c = c*a;		
		}
		int size = 0;
		while(1)
		{
			int temp2 = sum%b;
			ans[size++]=temp2;
			sum = sum/b;
			if(sum==0)
			{
				break;
			}
		}
		for(j=size-1;j>=0;j--)
		{
			printf("%d",ans[j]);
		}
		printf("\n");
	}
	return 0;
}
