#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n,m;
int go[2][4]={{-1,1,0,0},{0,0,-1,1}};
int st,ed;
char maze[210][210];
bool find2;
int mindis;
bool vis[210][210];
void DFS(int x,int y,int d)
{
	if(d>mindis)return;
	if(x<0||x>=n||y<0||y>=m||maze[x][y]=='#'||vis[x][y]==true)
	{
			return;
	}
	if(maze[x][y]=='r')
	{
		find2=true;
		if(d<mindis)
		{
			mindis=d;
		}
		return;
	}
	if(maze[x][y]=='x')
	{
		++d;
	}
	vis[x][y]=true;
	DFS(x+1,y,d+1);
	DFS(x-1,y,d+1);
	DFS(x,y+1,d+1);
	DFS(x,y-1,d+1);
	/*for(int i=0;i<4;i++)
	{
		int nextx=x+go[0][i];
		int nexty=y+go[1][i];
		if(nextx<0||nextx>=n||nexty<0||nexty>=m||maze[nextx][nexty]=='#'||vis[nextx][nexty]==true)
		{
			continue;
		}
		
		DFS(nextx,nexty,d+1);
		
	}*/
	vis[x][y]=false;
}
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	int i,j,k;
	while(scanf("%d%d*c",&n,&m)!=EOF) 
	{
		//getchar();
		for(i=0;i<n;++i)
		{
			for(j=0;j<m;++j)
			{
				maze[i][j]=getchar();
				/*char ch;
				scanf("%c",&ch);
				maze[i][j]=ch;*/
				if(maze[i][j]=='a')
				{
					st=i;
					ed=j;	
				}	
			}
			getchar();
		}
		fill(vis[0],vis[0]+210*210,false);
		mindis=1000000;
		DFS(st,ed,0);
		
		if(mindis!=1000000)
		{
			printf("%d\n",mindis);
		}
		else
		{
			printf("Poor ANGEL has to stay in the prison all his life.\n");
		}
	} 
	
	return 0;
}
