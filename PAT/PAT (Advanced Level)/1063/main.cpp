#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	set<int>s[51];
	set<int>s_temp;
	int m,n,k,i,j,temp;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&k);
			for(j=1;j<=k;j++)
			{
				scanf("%d",&temp);
				s[i].insert(temp);
			}
		} 
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			set<int>::iterator it1;
			set<int>::iterator it2;
			set<int>::iterator it3;
			int size1=s[a].size();
			int size2=s[b].size();
			int count=0;
			for(it1=s[a].begin();it1!=s[a].end();it1++)
			{
				s_temp.insert(*it1);
			}
			for(it2=s[b].begin();it2!=s[b].end();it2++)
			{
				s_temp.insert(*it2);
			}
			int total_size=s_temp.size();
			s_temp.clear();
			double similarity=(1.0*(size1+size2-total_size))/(1.0*(total_size));
			printf("%.1lf%%\n",similarity*100);
		}
	}
	return 0;
}
