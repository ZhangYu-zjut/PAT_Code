#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�㷨˼·�� 
//�������ֵ��abc 
//��ʼ������ 
//����BFS�������� 
//	���в�Ϊ�յ�ʱ���������ѭ���� 
//	����ͷ��������ͷ 
// 	�Ե�ǰ��״̬���б仯
//	�ж���״̬�ĺϷ��� 
//	�Ϸ���������
//	�ж��Ƿ��յ㣬�ǵĻ��ͷ�������Ҫ���ѵ�ʱ�䡣
//���ݷ��ؽ����������� 
int maze[50][50][50];
bool mark[50][50][50];//���ĳ��״̬�Ƿ���չ����true��ʾ�Ѿ�����չ�� 
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
int BFS(int a,int b,int c)//����abc���й��������������󷵻���Сʱ�䡣 
{
	//��ȡ��ǰ����ͷ�ڵ����Ϣ 
	//��ȡ��һ��״̬����Ϣ
	//�ж���һ��״̬�Ƿ���Ч������Ч����뵽������
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
		for(i=0;i<a;i++)//�����Թ���Ϣ 
		{
			for(j=0;j<b;j++)
			{
				for(k=0;k<c;k++)
				{
					scanf("%d",&maze[i][j][k]);
				} 
			}
		}
		//������ն��� 
		while(Q.empty()==false)Q.pop();
		//��ʼ������ 
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
