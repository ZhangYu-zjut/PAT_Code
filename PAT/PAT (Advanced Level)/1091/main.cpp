#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//������
//����һ������n,m,l����ά�ľ�����Ϣ
//Ҫ��Ӹþ������ҵ�����ֵΪ1����ͨ����������ͨ�鲻��Ҫ��ȫ�ڽӡ�
//����˼·���Թ�Ѱ·���ƣ�������Ҫ����һ����ά�ľ���ע��ȫ�ֱ�����Ҫ���ֲ������ظ������� 
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
	inq[a.x][a.y][a.z]=true;//��仰����©�£������� 
	ans++;//��仰Ҫ�� 
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
					if(inq[i][j][s]==false)//�ҵ�һ���µ�Ϊ���ʵĵ� 
					{
						ans=0;
						Node.x=i;
						Node.y=j;
						Node.z=s;
						BFS(Node);//������������ڵĿ� 
						if(ans>=t)//���ʽ������������Ľڵ���������ж� 
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
