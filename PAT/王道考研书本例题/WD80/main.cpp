#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define debug 1 
int prime[100010];//存放素数 
bool mark[100010];//判定是否为素数 
int primesize;//记录素数的个数 
void init()//素数筛选法 
{
	primesize=0;
	int i,j;
	for(i=0;i<=100000;i++)
	{
		mark[i]=true;//初始化记为都是素数 
	}
	for(i=2;i<=100000;i++)
	{
		if(mark[i]==false)continue; //不是素数就不用处理  
		prime[primesize++]=i;
		if(i>1000)continue;//j=i*i.要小于10^5,所以i到1000就可以结束了。后面的循环是没有意义的,还可能会造成越界。 
		for(j=i*i;j<=100000;j+=i)//是素数就标记 
		{			
			mark[j] = false;
		}
	}
}

int main(int argc, char** argv) {
	int ansnum[50];//存放因数 
	int anssize[50];//存放每个因数的幂指数 
	int length;//不同素因子的个数 
	int ans;//存放最后的结果 
	int n,i,j;
	//算法过程：
	//1.读取N。
	//2.获得小于N的所有素因数。
	//3.用N除以各个素因数，获取各个素因数的指数。 
	//4.指数相加，获得最后的结果
	while(scanf("%d",&n)!=EOF)
	{
		init();
		ans=0;
		length=0;
		for(i=0;i<primesize;i++)
		{

			if(n%prime[i]==0)//判定输入的数n能否被某个素因数整除 
			{
				anssize[length]=0;
				while(n%prime[i]==0)
				{
					ansnum[length]=prime[i];
					anssize[length]++;
					n=n/prime[i];	
					#if debug
					printf("prime[i] is:%d\n",prime[i]);	
					#endif			
				}
				length++;//这句话只能放在这里！！！某一个素因数处理完之后，对length+1；			
			}	
			if(n==1)
			{
				break;
			}
		} 
		if(n!=1)
		{
			ansnum[length]=n;
			anssize[length]=1;
		}
		for(i=0;i<length;i++)
		{
			ans+=anssize[i];
			#if debug
			printf("size is:%d\n",anssize[i]); 
			#endif
		}
		printf("%d\n",ans);
	}
	return 0;
}
