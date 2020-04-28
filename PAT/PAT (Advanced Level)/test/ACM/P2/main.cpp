#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node
{
	int value;
	int cost;
	double vc;
}N[1003];
bool cmp(node a,node b)
{
	return a.vc>b.vc;
}
int main(int argc, char** argv) {
	int m,n,i,j,k,a,b;
	while(scanf("%d%d",&m,&n)!=EOF&&m!=-1&&n!=-1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			N[i].value=a;
			N[i].cost=b;
			N[i].vc=1.0*a/b;
		}
		sort(N,N+n,cmp);
		double ans=0;
		double sum=0;
		double temp=0;
		for(i=0;i<n;i++)
		{
			temp+=N[i].cost;
			if(temp<=m)
			{
				ans+=N[i].value;
			}
			if(temp>m)
			{
				ans+=1.0*(m-(temp-N[i].cost))*N[i].vc;
				break;
			}
			//printf("%lf\n",ans);
		}
		printf("%.3lf\n",ans);
	}
	
	return 0;
}
