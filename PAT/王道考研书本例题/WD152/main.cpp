#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//WD152 temple of bone AC!!!
//������������㷨�߳��Թ�
//�㷨˼·�� 
//	ȷ������ʱ�̵�״̬��(x,y,t)���Լ�Ŀ���ߵ��Ų���t�պ�Ϊ����ֵ 
//	��ȡ��ǰʱ�̵�״̬���ж��Ƿ�Ϊ����״̬�����ǣ������ж�ʱ���Ƿ�Ϊ����ֵ�����ǣ���������ء� 
//	����������״̬��������һ����������һ�����״̬�����ж����Ƿ�Ϊ�Ϸ�״̬�����Ƿ�������������ѭ�������Ϸ�������µ�״̬����������������ĵݹ� 
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
		mark[nx][ny]=true;//״̬��� 
		DFS(nx,ny,t+1);//ȷ���ߵ���״̬��ʱ���һ 
	
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
