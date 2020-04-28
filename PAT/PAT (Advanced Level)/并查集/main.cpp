#include <iostream>
#include <stdio.h>

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define N 100
int father[N];
int isroot[N];
int findroot(int x)//�ҵ�x�ĸ��ڵ㲢����
{
	while(x!=father[x])
	{
		x=father[x];
	}
	return x;
} 
void Union(int a,int b)//��a��b�ĸ��ڵ㲻��ͬ����a��b���кϲ�
{
	int fa=findroot(a);
	int fb=findroot(b);
	if(fa!=fb)
	{
		father[fa]=fb;
	}
} 
void init(int n)//�Խڵ���Ϣ���г�ʼ�� 
{
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
		isroot[i]=false;
	}
}
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int a,b,m,n;
	scanf("%d%d",&n,&m);
	init(n);//Ҫ�Ƚ��г�ʼ�����ٽ��в��� 
	int i,j,k;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		Union(a,b);
	}
	int cnt=0;
	for(i=1;i<=n;i++)
	{
		isroot[findroot(i)]=true;	
	}
	for(i=1;i<=n;i++)
	{
		if(isroot[i])
		{
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
