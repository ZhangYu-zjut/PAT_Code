#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//通过打表方式能够减少循环次数，避免超时！！！
//AC!! 
int num1[10004];
int num2[10004];
int query[10004];
int ext[10004]={0};
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n,m,i,j,k,g,t;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&num1[i]);
		scanf("%d",&num2[i]);
	}
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&k);
		for(j=0;j<k;j++)
		{
			scanf("%d",&query[j]);
			ext[query[j]]=1;
		}
		bool judge=true;
		for(j=0;j<m;j++)
		{
			if(ext[num1[j]]==0&&ext[num2[j]]==0)
			{
				judge=false;
			}
		}
		if(judge==true)printf("Yes\n");
		else printf("No\n");
		for(j=0;j<10004;j++)
		{
			ext[j]=0;
		}
	}
	return 0;
}
