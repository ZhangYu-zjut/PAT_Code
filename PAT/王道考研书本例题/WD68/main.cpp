#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <stdio.h> 
int main(int argc, char** argv) {
	int m,i;
	long long a,b,sum;
	freopen("test.txt","r",stdin);
	while(scanf("%d",&m)!=EOF)
	{
		if(m==0){break;}
		scanf("%lld%lld",&a,&b);
		sum = a+b;
		int num[50],size=0,temp;
		while(1)
		{
			temp = sum%m;
			num[size]=temp;
			size++;
			sum = sum/m;
			if(sum==0){
				break;
			}
			
		}
		for(i=size-1;i>=0;i--){
			printf("%d",num[i]);
		}
		printf("\n");
		
	}
	return 0;
}
