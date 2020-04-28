#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int num[10004];
int ans[10004][10004];
bool vis[10004][10004];
int direction[][2]=
{
	0,1,
	1,0,
	0,-1,
	-1,0
};
bool cmp(int a,int b)
{
	return a>b;
}
int main(int argc, char** argv) {
	fill(vis[0],vis[0]+10004*10004,false);
	int N;
	scanf("%d",&N);
	int i,j,k,m,n;
	int a,b;
	int MIN=100000;
	int temp=sqrt(N);
	for(i=1;i<=temp;i++)//m*n;
	{
		if(N%i==0)
		{
			b = N/i;
			if(b-i<MIN)
			{
				MIN = b-i;
				m = b;
				n = i;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+N,cmp);
	int count=1;
	ans[0][0]=num[0];
	vis[0][0]=true;//这句话不能忘！！ 
	int x=0,y=0,nx,ny;
	int step=0,next;
	while(count<N)
	{
		nx=x+direction[step][0];
		ny=y+direction[step][1];
		if(nx>=m||nx<0||ny>=n||ny<0||vis[nx][ny]==true)
		{
			step++;
			x=x+direction[(step)%4][0];
			y=y+direction[(step)%4][1];
			ans[x][y]=num[count];
			vis[x][y]=true;
			//printf("x:%d y:%d ans is:%d step is%d\n",x,y,ans[x][y],step);
		}
		else
		{
			x=nx;
			y=ny;
			ans[x][y]=num[count];
			vis[x][y]=true;
			//printf("x:%d y:%d ans is:%d step is:%d\n",x,y,ans[x][y],step);
		}
		count++;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==0)printf("%d",ans[i][j]);
			else printf(" %d",ans[i][j]);
		}	
		printf("\n");	
	}
	return 0;
}
