#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//本题需要注意一些坑：
//输入25 4以后，输出为1.要将原来的001中的前导零去掉。
//另外，若输入5 1010，输出应为505.将第一个前导零去掉。第二个零保留。 
int num[10];
int main(int argc, char** argv) {
	int a,b,sum;
	scanf("%d%d",&a,&b);
	sum = a*b;
	int i=0,j;
	int size=0;
	bool first=true;
	while(1)
	{
		int temp=sum%10;
		while(temp==0&&first==true)
		{
			sum=sum/10;
			temp=sum%10;
		} 
		first=false;
		num[i]=temp;
		sum/=10;
		i++;
		size++;
		if(sum<1)
		{
			break;
		}
	}
	for(j=0;j<size;j++)
	{
		printf("%d",num[j]);
	}
	return 0;
}
