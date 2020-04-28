#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//ºÚµ•Ã‚£¨AC!!! 
struct node 
{
	char data;
	int next;
	int flag;
}N[100000];
int main(int argc, char** argv) {
	int s1,s2,n;
	int a,c;
	char b;
	scanf("%d%d%d",&s1,&s2,&n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		scanf("%d %c %d",&a,&b,&c);
		N[a].data=b;
		N[a].next=c;
	}
	int p;
	for(p=s1;p!=-1;p=N[p].next)
	{
		N[p].flag=true;
	}
	for(p=s2;p!=-1;p=N[p].next)
	{
		if(N[p].flag)
		{
			break;
		}
	}
	if(p!=-1)
	{
		printf("%05d",p);
	 } 
	else
	{
		printf("-1");
	}
	return 0;
}
