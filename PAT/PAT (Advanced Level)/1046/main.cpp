#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//注意外循环和内循环的变量不能是同一个，并且可以将每次相加以后的结果存起来，减少时间消耗！！！
//AC!!! 
int num[100005]; 
int a[100005];
int b[100005];
int sum[100005];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin); 
	int n,i,j,k;
	int total=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		total+=num[i];
		sum[i]=total;
	}
	scanf("%d",&k);
	for(j=0;j<k;j++)
	{
		scanf("%d%d",&a[j],&b[j]);
		int ans1=0;
		int ans2=0;
		
		int final=0;
		int minn=min(a[j],b[j]);
		int maxx=max(a[j],b[j]);
		ans1=sum[maxx-1]-sum[minn-1];//用这种方法能够避免最后一个测试点超时的情况！ 
		/*for(i=minn;i<maxx;i++)
		{
			ans1+=num[i];
		}*/
		ans2=total-ans1;
		printf("%d\n",min(ans1,ans2));
	}

	
	return 0;
}
