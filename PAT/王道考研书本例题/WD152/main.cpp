#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//WD152 temple of bone AC!!!
//利用深度优先算法走出迷宫
//算法思路： 
//	确定各个时刻的状态：(x,y,t)，以及目标走到门并且t刚好为给定值 
//	读取当前时刻的状态，判定是否为最终状态，若是，继续判定时间是否为给定值。若是，则结束返回。 
//	若不是最终状态，则走下一步，并对下一步后的状态进行判定，是否为合法状态，若非法，则跳过本次循环。若合法，则对新的状态进行深度优先搜索的递归 
//
#define N 20
char maze[N][N];
bool mark[N][N];
int T;
int t;
int n,m;
int count;
bool success;
struct point
{
	int x,y;
	int t;
}P[100];  
int go[][2]=
{
	1,0,
	-1,0,
	0,1,
	0,-1
};
void DFS(int x,int y,int t)
{

	for(int i=0;i<4;i++)
	{
		int nx=x+go[i][0];
		int ny=y+go[i][1];
		if(maze[nx][ny]=='D')
		{
			if(T==(t+1))
			{
				success=true;
				return;
			}
			else
			{
				continue; 
			}
		}
		if(mark[nx][ny]==true)
		{
			continue;
		} 
		if(nx>=n||nx<0||ny<0||ny>=m)
		{
			continue;
		}
		if(maze[nx][ny]=='X')
		{
			continue;
		}
		mark[nx][ny]=true;//状态标记 
		DFS(nx,ny,t+1);//确认走到该状态，时间加一 
	
	}
	
}

int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	while(scanf("%d%d%d",&n,&m,&T)!=EOF &&n!=0&&m!=0&&T!=0)
	{
		success=false; 
		count=0;
		int i,j,k;
		for(i=0;i<n;i++) 
		{
			{
				scanf("%s",maze[i]);
			}			
		}
		for(i=0;i<n;i++) 
		{
			for(j=0;j<m;j++)
			{
				mark[i][j]=false;
			}			
		}
		int x=0,y=0,t=0;
		for(i=0;i<n;i++) 
		{
			for(j=0;j<m;j++)
			{
				if(maze[i][j]=='S')
				{
					x=i;
					y=j;
					
				}				 
			}		
		}
		DFS(x,y,t);
		success==true?printf("YES\n"):printf("NO\n"); 
	}
	return 0;
}
