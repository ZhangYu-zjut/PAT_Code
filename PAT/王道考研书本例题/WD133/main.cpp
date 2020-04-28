#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//算法思路： 
//读入矩阵值和abc 
//初始化队列 
//利用BFS进行搜索 
//	队列不为空的时候进行下列循环： 
//	读队头，并弹出头 
// 	对当前的状态进行变化
//	判断新状态的合法性 
//	合法则加入队列
//	判断是否到终点，是的话就返回所需要花费的时间。
//根据返回结果进行输出。 
int maze[50][50][50];
bool mark[50][50][50];//标记某个状态是否被扩展过，true表示已经被扩展。 
int pos[6][3]=
{
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1,
};
struct status
{
	int x,y,z;
	int time;
};
queue<status> Q;
int BFS(int a,int b,int c)//根据abc进行广度优先搜索，最后返回最小时间。 
{
	//获取当前队列头节点的信息 
	//获取下一个状态的信息
	//判断下一个状态是否有效，若有效则加入到队列中
	int i,j,k;
	while(Q.empty()==false)
	{
		status curr=Q.front();
		Q.pop();
		for(i=0;i<6;i++)
		{
			int nx=curr.x+pos[i][0];
			int ny=curr.y+pos[i][1];
			int nz=curr.z+pos[i][2];
			if(nx<0||nx>=a||ny<0||ny>=b||nz<0||nz>=c)
			{
				continue;
			}
			if(mark[nx][ny][nz]==true||maze[nx][ny][nz]==1)
			{
				continue;
			}
			status news;
			news.x=nx;
			news.y=ny;
			news.z=nz;
			news.time=curr.time+1;
			mark[nx][ny][nz]=true;
			if(nx==a-1&&ny==b-1&&nz==c-1)
			{
				return news.time;
			}
			Q.push(news);
		}
		
	} 

	return 5500;
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int i,j,n,k;
	int T;
	int a,b,c;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&T);
		for(i=0;i<a;i++)//读入迷宫信息 
		{
			for(j=0;j<b;j++)
			{
				for(k=0;k<c;k++)
				{
					scanf("%d",&maze[i][j][k]);
				} 
			}
		}
		//首先清空队列 
		while(Q.empty()==false)Q.pop();
		//初始化队列 
		status init;
		init.x=init.y=init.z=0;
		init.time=0;
		mark[0][0][0]=true;
		Q.push(init);
		int cost=BFS(a,b,c);
		cost<=T?printf("%d\n",cost):printf("-1");
	} 
	return 0;
}
