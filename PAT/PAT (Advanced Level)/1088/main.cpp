#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AC!!!
typedef long long ll;
struct fraction
{
	ll up;
	ll down; 
}a,b,temp,ans;
ll gcd(ll a,ll b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}
fraction reduce(fraction a)//3¸öif 
{
	if(a.up==0)
	{
		a.down=1;
	}
	if(a.down<0)
	{
		a.up*=-1;
		a.down*=-1;
	}
	else
	{
		ll d=gcd(abs(a.up),abs(a.down));
		a.up/=d;
		a.down/=d;
	}
	return a;
}
fraction add(fraction a,fraction b)
{
	fraction ans;
	ans.down=a.down*b.down;
	ans.up=a.up*b.down+b.up*a.down;
	return reduce(ans); 
}
fraction minu(fraction a,fraction b)
{
	fraction ans;
	ans.down=a.down*b.down;
	ans.up=a.up*b.down-b.up*a.down;
	return reduce(ans); 
} 
fraction mul(fraction a,fraction b)
{
	fraction ans;
	ans.down=a.down*b.down;
	ans.up=a.up*b.up;
	return reduce(ans); 
}
fraction dev(fraction a,fraction b)
{
	fraction ans;
	ans.down=a.down*b.up;
	ans.up=a.up*b.down;
	return reduce(ans); 
}
void show(fraction a)
{
	a=reduce(a);
	if(a.up<0)printf("(");
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
	if(a.up<0)printf(")");
}
int main(int argc, char** argv) {
	ll x,y;
	scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
	show(a);
	printf(" + ");
	show(b);
	ans=add(a,b);
	printf(" = ");
	show(ans);
	printf("\n");
	
	show(a);
	printf(" - ");
	show(b);
	ans=minu(a,b);
	printf(" = ");
	show(ans);
	printf("\n");
	
	show(a);
	printf(" * ");
	show(b);
	ans=mul(a,b);
	printf(" = ");
	show(ans);
	printf("\n");
	
	show(a);
	printf(" / ");
	show(b);
	ans=dev(a,b);
	printf(" = ");
	if(ans.down==0)
	{
		printf("Inf");
	}
	else
	{
		show(ans);
	}
	printf("\n");
	
	return 0;
}
