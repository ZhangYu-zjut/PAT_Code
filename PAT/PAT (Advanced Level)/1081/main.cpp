#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//注意数据类型为long long而不是int！！！！ 
struct fraction
{
	long long up;
	long long down;
}f[200];
long long gcd(long long a,long long b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}
fraction reduce(fraction a)
{
	if(a.up==0)
	{
		a.up=0;
		a.down=1;
	}
	if(a.down<0)
	{
		a.up*=-1;
		a.down*=-1;
	}
	else
	{
		long long d=gcd(abs(a.up),abs(a.down));//先这样计算 
		a.up/=d;	
		a.down/=d;
	}
	return a;
}
fraction add(fraction a,fraction b)
{
	fraction ans;
	ans.down=a.down*b.down;
	ans.up = a.up*b.down+b.up*a.down;
	return reduce(ans);
}

void show(fraction a)
{
	//整数放在最前面 
	if(a.down==1)
	{
		printf("%lld",a.up);
	}
	else if(abs(a.up)>a.down)
	{
		printf("%lld %lld/%lld",a.up/a.down,abs(a.up)%a.down,a.down);
	}
	else
	{
		printf("%lld/%lld",a.up,a.down);
	}
}
int main(int argc, char** argv) {
	int i,j,n;
	long long a,b;
	fraction sum,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld/%lld",&a,&b);
		f[i].up=a;
		f[i].down=b;
	}
	temp=f[0];
	for(i=1;i<n;i++)
	{
		sum=add(temp,f[i]);
		temp=sum;
	}
	show(sum);
	return 0;
}
