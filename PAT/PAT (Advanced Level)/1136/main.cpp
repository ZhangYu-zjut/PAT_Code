#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//大整数的操作，找到切入点即可
//AC!! 
struct bigint
{
	int num[10000];
	int length;
};
bigint add(bigint a,bigint b)
{
	int i,clength=a.length;
	bigint c;
	int carry=0;
	for(i=0;i<a.length;i++)
	{
		int temp=a.num[i]+b.num[i]+carry;
		if(temp<10)
		{
			c.num[i]=temp;
			carry=0;
		}
		else
		{
			c.num[i]=temp-10;
			carry=1;
		}
	}
	if(carry>0)
	{
		c.num[a.length]=carry;
		c.length=clength+1;
	}
	else c.length=clength;
	return c;
}
bigint same(bigint a)
{
	bigint b;
	for(int i=0;i<a.length;i++)
	{
		b.num[i]=a.num[i];
	}
	b.length=a.length;
	return b;
}
bigint change(bigint a)
{
	bigint b;
	for(int i=0;i<a.length;i++)
	{
		b.num[i]=a.num[a.length-1-i];
	}
	b.length=a.length;
	return b;
}
bool judge(bigint c)
{
	int i,j;
	int length=c.length;
	bool ans=true;
	for(i=0;i<length;i++)
	{
		if(c.num[i]!=c.num[length-1-i])
		{
			ans=false;
			break;
		}
	}
	return ans;
}
void show(bigint b)
{
	for(int i=b.length-1;i>=0;i--)
	{
		cout<<b.num[i];
	}
}
char ch[10000];
int main(int argc, char** argv) {
	int n,i,j,k;
	scanf("%s",ch);
	bigint a,b,c;
	int count=0;
	for(i=strlen(ch)-1;i>=0;i--)
	{
		a.num[count++]=ch[i]-'0';
	}
	a.length=count;
	for(i=0;i<count;i++)
	{
		b.num[i]=a.num[count-1-i];
	}
	b.length=a.length;
	if(judge(a))
	{
		show(a);
		cout<<" is a palindromic number."<<endl;
		return 0;
	}
	for(i=0;i<10;i++)
	{	
		bigint c=add(a,b);
		show(a);
		cout<<" + ";
		show(b);
		cout<<" = ";
		show(c);
		cout<<endl;
		if(judge(c))
		{
			show(c);
			cout<<" is a palindromic number."<<endl;
			break;
		}
		else
		{
			a=same(c);
			b=change(a);
		}
		if(i==9)
		{
			cout<<"Not found in 10 iterations."<<endl;
		}
	}
	return 0;
}
