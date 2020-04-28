#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//描述：
//给定一定整数n,m,l和三维的矩阵信息
//要求从该矩阵中找到所有值为1的联通块数量，联通块不需要完全邻接。
//这题思路与迷宫寻路类似，不过需要建立一个三维的矩阵。注意全局变量不要跟局部变量重复！！！ 
const int maxn=1300;
int n,m,k;
int final_ans=0;
int ans;
int maze[1290][130][65];
bool inq[1290][130][65];
struct node
{
	int x,y,z;
}Node;
int x[]={-1,1,0,0,0,0};
int y[]={0,0,0,0,-1,1};
int z[]={0,0,-1,1,0,0};
bool judge(int x,int y,int z)
{
	if(x<0||x>=n||y<0||y>=m||z<0||z>=k)
	{
		return false; 
	} 
	else return true;
}
void BFS(node a)
{
	node ntemp;
	queue<node>q;
	q.push(a);
	inq[a.x][a.y][a.z]=true;//这句话不能漏下！！！！ 
	ans++;//这句话要加 
	while(!q.empty())
	{
		node temp = q.front();
		q.pop();
		for(int i=0;i<6;i++)
		{
			int nx=temp.x+x[i];
			int ny=temp.y+y[i];
			int nz=temp.z+z[i];
			if(maze[nx][ny][nz]==1&&inq[nx][ny][nz]==false&&judge(nx,ny,nz))
			{
				ntemp.x=nx,ntemp.y=ny,ntemp.z=nz;
				q.push(ntemp);
				inq[nx][ny][nz]=true;
				ans++;
			}
		}
	}
}

int main(int argc, char** argv) {
	int i,j,t,s;
	freopen("test.txt","r",stdin);
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(s=0;s<k;s++)
	{
		//fill(inq[0],inq[0]+1290*130*65,0);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				int temp;
				scanf("%d",&temp);
				maze[i][j][s]=temp;
			}
		}
	}
	for(s=0;s<k;s++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(maze[i][j][s]==1)
				{
					if(inq[i][j][s]==false)//找到一个新的为访问的点 
					{
						ans=0;
						Node.x=i;
						Node.y=j;
						Node.z=s;
						BFS(Node);//访问这个点所在的块 
						if(ans>=t)//访问结束，对这个块的节点个数进行判断 
						{
							final_ans+=ans;
						}
					}
				}
			}
		}	
	}
	printf("%d",final_ans);
	return 0;
}
