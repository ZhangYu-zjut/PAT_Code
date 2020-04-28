#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char maze[250][250];
int go[2][4]={0,0,-1,1,-1,1,0,0};
//HDUOJ1242£¬AC!!! 
const int inf=100000;
int max=inf;
int min2;
int stx,sty;
int endx,endy;
int ans;
int n,m;
bool find2=false;
bool vis[210][210];
struct node
{
	int x;
	int y;
}N[200*220];
vector<node>v;
void DFS(int x,int y,int d)//109MS
{
	if(maze[x][y]=='r')
	{
		find2=true;
		if(d<min2)
		{
			min2=d;
		}
	} 
	if(maze[x][y]=='x')
	{
		d++;
	}
	for(int i=0;i<4;i++)
	{
		int nextx=x+go[0][i];
		int nexty=y+go[1][i];
		if(maze[nextx][nexty]=='#')continue;
		if(maze[nextx][nexty]!='#'&&nextx>=0&&nextx<n&&nexty>=0&&nexty<m&&vis[nextx][nexty]==false)
		{
			vis[nextx][nexty]=true;
			DFS(nextx,nexty,d+1);
			vis[nextx][nexty]=false;
		}
	}
}
void DFS2(int x,int y,int d)
{
	//ÕÒµ½´ð°¸ºó¼ôÖ¦ 
	if(maze[x][y]=='r')
	{
		//printf("curr min is%d\n",min2);
		find2=true;
		if(d<min2)
		{
			min2=d;
		}
		return;
	}
	if(maze[x][y]=='x')
	{
		d++;
	}
	//·¶Î§¼ôÖ¦¡¢Ê±¼ä¼ôÖ¦¡¢Â·¾¶¼ôÖ¦ 
	if(x<0||x>=n||y<0||y>=m||d>min2||maze[x][y]=='#')
	{
		return;
	}
	for(int i=0;i<4;i++)
	{
		int nextx=x+go[0][i];
		int nexty=y+go[1][i];
		if(vis[nextx][nexty]==false)
		{
			vis[nextx][nexty]=true;
			DFS2(nextx,nexty,d+1);
			vis[nextx][nexty]=false;
		}
	}
}
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	while(scanf("%d%d\n",&n,&m)!=EOF)
	{
		int i,j,k;
		int count=0;
		scanf("%d%d\n",&n,&m);
		fill(vis[0],vis[0]+210*210,false);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				char ch;
				scanf("%c",&maze[i][j]);
				//printf("ch is%c",maze[i][j]);
				if(maze[i][j]=='a')
				{
					stx=i;
					sty=j;
				}
			}
			getchar();
		}
		vis[stx][sty]=true;
		find2=false;
		min2=inf;
		DFS2(stx,sty,0);//ºÄÊ±124ms 
		//DFS(stx,sty,0);//ºÄÊ±109ms 
		if(find2)
		{
			printf("%d\n",min2);
		}
		else
		{
			printf("Poor ANGEL has to stay in the prison all his life.\n");
		}
	}
	
	return 0;
}
