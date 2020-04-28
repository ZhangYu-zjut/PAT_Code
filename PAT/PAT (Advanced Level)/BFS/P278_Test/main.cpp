#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//������
//����һ������n,m�Ͷ�ά�ľ�����Ϣ
//Ҫ��Ӹþ������ҵ�����ֵΪ1����ͨ����������ͨ�鲻��Ҫ��ȫ�ڽӡ� 
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
			//ע��������Թ��ַ����пո��û�пո�����𣡣��� 
			char temp;
			scanf("%c",&temp);
			cout<<temp;
			maze[i][j]=temp[0];
			N[i][j].x=i;
			N[i][j].y=j;
		}
		getchar();//��仰һ��Ҫ�� 
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
