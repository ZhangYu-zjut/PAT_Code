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
char maze[maxn][maxn];
bool inq[maxn][maxn];
struct node
{
	int x,y;
	int layer;
}N[maxn][maxn];
int x[]={-1,1,0,0};
int y[]={0,0,-1,1};
bool judge(int x,int y,int n,int m)
{
	if(x<0||x>=n||y<0||y>=m)
	{
		return false;
	}
	if(maze[x][y]=='*')
	{
		return false;
	}
	return true;
}
void BFS(node a,node b)
{
	queue<node>q;
	inq[a.x][a.y]=true;
	a.layer=0;
	q.push(a);
	while(!q.empty())
	{
		node temp = q.front();
		q.pop();
		if(temp.x==b.x&&temp.y==b.y)
		{
			return;
		}
		for(int i=0;i<4;i++)
		{
			int nx=temp.x+x[i];
			int ny=temp.y+y[i];
			if(inq[nx][ny]==false&&judge(nx,ny,n,m))
			{
				N[nx][ny].layer=temp.layer+1;
				q.push(N[nx][ny]);
				inq[nx][ny]=true;
			}
		}
	}
}

int main(int argc, char** argv) {
	int i,j,k;
	freopen("test.txt","r",stdin);
	scanf("%d%d%*c",&n,&m);
	fill(inq[0],inq[0]+maxn*maxn,0);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			//注意输入的迷宫字符中有空格和没有空格的区别！！！ 
			char temp;
			scanf("%c",&temp);
			cout<<temp;
			maze[i][j]=temp[0];
			N[i][j].x=i;
			N[i][j].y=j;
		}
		getchar();//这句话一定要加 
		cout<<"i sis"<<i<<endl;

	}
	int stx,sty,edx,edy;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(maze[i][j]=='S')
			{
				stx=i;
				sty=j;
				break;
			}
			if(maze[i][j]=='T')
			{
				edx=i;
				edy=j;
				break;
			}
		}
	}
	BFS(N[stx][sty],N[edx][edy]);
	printf("%d",N[edx][edy].layer);
	return 0;
}
