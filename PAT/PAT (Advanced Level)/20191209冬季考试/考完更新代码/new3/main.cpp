#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//���ñ߱����ж������ߵĵ���ɫ��ͬ����,AC!!
//���Ե�ʱ����ʹ�õ���������������Ե�û��ͨ��,Ҫ��ȥ��һ��ԭ�� 
int n,m;
struct edge
{
	int s,v;
}e[10004];
int num[10004];
set<int>s;
int main(int argc, char** argv) {
	scanf("%d%d",&n,&m);
	int i,j,k;
	for(i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		e[i].s=a;
		e[i].v=b;
	}
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		s.clear(); 
		for(j=0;j<n;j++)
		{
			scanf("%d",&num[j]);
			s.insert(num[j]);
		}
		int allcolor=s.size();
		bool ans=true;
		for(j=0;j<m;j++)
		{
			if(num[e[j].s]==num[e[j].v])
			{
				printf("No\n");
				ans=false;
				break;
			}
		}
		if(ans)
		{
			printf("%d-coloring\n",allcolor);
		}
	}
	return 0;
}
