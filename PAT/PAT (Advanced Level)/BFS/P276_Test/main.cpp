#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//描述：
//给定一定整数n,m和二维的矩阵信息
//要求从该矩阵中找到所有值为1的联通块数量，联通块不需要完全邻接。 
const int maxn=200;
int n,m;
int maze[maxn][maxn];
bool inq[maxn][maxn];
struct node
{
	int x,y;
}N[maxn][maxn];
int x[]={-1,1,0,0};
int y[]={0,0,-1,1};
bool judge(int x,int y,int n,int m)
{
	if(x>=0&&x<n&&y>=0&&y<m)return true;
	else return false;
}
void BFS(node a)
{
	queue<node>q;
	q.push(a);
	inq[a.x][a.y]=true;
	while(!q.empty())
	{
		node temp = q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=temp.x+x[i];
			int ny=temp.y+y[i];
			if(maze[nx][ny]==1&&inq[nx][ny]==false&&judge(nx,ny,n,m))
			{
				q.push(N[nx][ny]);
				inq[nx][ny]=true;
			}
		}
	}
}

int main(int argc, char** argv) {
	int i,j,k;
	freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	fill(inq[0],inq[0]+maxn*maxn,0);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			int temp;
			scanf("%d",&temp);
			maze[i][j]=temp;
			N[i][j].x=i;
			N[i][j].y=j;
		}
	}
	int ans=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(maze[i][j]==1)
			{
				if(inq[i][j]==false)
				{
					BFS(N[i][j]);
					ans++;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
