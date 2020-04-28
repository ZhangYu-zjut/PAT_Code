#include <iostream>
#include <stdio.h>
#include <string.h>
//有个负号的问题没有解决！！！ 
using namespace std;
struct bigint
{
	int num[1000];
	int length;
	bigint()
	{
		memset(num,0,sizeof(num));
		length=0;
	}
}b[100]; 
bigint change(char str[])
{
	bigint b;
	b.length=strlen(str);
	for(int i=0;i<b.length;i++)
	{
		b.num[i]=str[b.length-1-i]-'0';
	}
	return b;
}
bigint add(bigint a,bigint b)
{
	int i,j;
	bigint c;
	int carry=0;
	for(i=0;i<a.length||i<b.length;i++)
	{
		c.num[c.length++]=(a.num[i]+b.num[i]+carry)%10;
		carry=(a.num[i]+b.num[i])/10;
	}
	if(carry>0)
	{
		c.num[c.length++]=carry;
	}
	return c;
}
bigint sub(bigint a,bigint b)
{
	int i,j;
	bigint c;
	int carry=0;
	for(i=0;i<a.length||i<b.length;i++)
	{
		if(a.num[i]<b.num[i])
		{
			a.num[i]+=10;
			a.num[i+1]--;
		}
		c.num[c.length++]=(a.num[i]-b.num[i]);
	}
	while(c.length-1>=1&&c.num[c.length-1]==0)
	{
		c.length--;
	}
	return c;
}
bigint mul(bigint a,int b)
{
	int i,j;
	bigint c;
	int carry=0;
	for(i=0;i<a.length;i++)
	{
		int temp=(a.num[i]*b+carry);
		c.num[c.length++]=temp%10;
		carry=temp/10;
	}
	while(carry>0)//buyiy
	{
		c.num[c.length++]=carry%10;
		carry/=10;
	}
	return c;
}
bigint divide(bigint a,int b,int &r)
{
	int i,j;
	bigint c;
	c.length=a.length;
	int carry=0;
	for(i=a.length-1;i>=0;i--)
	{
		r = r*10+a.num[i];//r是余数 
		if(r<b)
		{
			c.num[i]=0;//商为0,余数不变 
		}
		else
		{
			c.num[i]=(r)/b; 
			r = r%b;
		}
	}
	while(c.length-1>=1&&c.num[c.length-1]==0)
	{
		c.length--;
	}
	return c;
	
}

bool larger(bigint a,bigint b)
{
	if(a.length>b.length)
	{
		return true;
	}
	else if(a.length<b.length)
	{
		return false;
	}
	else
	{
		for(int i=0;i<a.length;i++)
		{
			if(a.num[i]>b.num[i])return true;
			else if(a.num[i]<b.num[i])return false;
		}
		return false;
	}
}
void print(bigint a)
{
	for(int i=a.length-1;i>=0;i--)
	{
		printf("%d",a.num[i]);
	}
	//printf("\n"); 
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char str1[1000],str2[1000];
	char str3[1000]; 
	int n; 
	int r=0;
	int b;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s%s%s",str1,str2,str3);
		bigint a=change(str1);
		bigint b=change(str2);
		bigint sum=add(a,b);
		bigint c=change(str3);
		if(larger(sum,c))printf("Case #%d: true\n",i+1);
		else printf("Case #%d: false\n",i+1);
	}
/*	scanf("%s%d",str1,&b);
	bigint a=change(str1);
	bigint b=change(str2);
	bigint c=add(a,b);
	//bigint c=divide(a,b,r);
	print(c);
	printf(" %d",r);*/
	
	return 0;
}
