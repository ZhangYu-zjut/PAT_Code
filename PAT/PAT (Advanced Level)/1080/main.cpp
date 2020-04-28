#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct stu
{
	int id;
	int ge;
	int gi;
	int gfinal;
	int rank;
	vector<int>choice;
}S[50004];
int school[102];//容量 
int k;
vector<int>ans[102];
bool cmp2(int a,int b)
{
	return a<b;
}
bool cmp1(stu a,stu b)
{
	if(a.gfinal!=b.gfinal)
	{
		return a.gfinal>b.gfinal; 
	}
	else
	{
		return a.ge>b.ge;
	}
}
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	int n,m;
	int i,j,temp;
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<m;i++)
	{
		scanf("%d",&school[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&S[i].ge,&S[i].gi);
		S[i].id=i;
		S[i].gfinal=S[i].ge+S[i].gi;
		for(j=0;j<k;j++)
		{
			scanf("%d",&temp);
			S[i].choice.push_back(temp);
		}
	}
	sort(S,S+n,cmp1);
	S[0].rank=1;
	for(i=1;i<n;i++)//赋值排名 
	{
		if(S[i].gfinal==S[i-1].gfinal&&S[i].ge==S[i-1].ge)
		{
			S[i].rank=S[i-1].rank;
		}
		else
		{
			S[i].rank=i+1;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<S[i].choice.size();j++)//学校序号是S[i].choice[j]
		{
			int school_num=S[i].choice[j];
			int size=ans[school_num].size();
			if(school[school_num]==0)continue;//需要加上这句话！！！！ 
			if(ans[school_num].size()<school[school_num]||((S[i].rank==S[ans[school_num][size-1]].rank)&&(size>0)))//学校有多余的名额或者该学生的排名与最后那个学生排名相同 
			{
				ans[school_num].push_back(S[i].id);
				break;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		sort(ans[i].begin(),ans[i].end(),cmp2);
	}
	for(i=0;i<m;i++)
	{
		if(ans[i].size()>0)
		{
			for(j=0;j<ans[i].size();j++)
			{
				if(j==0)printf("%d",ans[i][j]);
				else printf(" %d",ans[i][j]);
			}
			if(i!=m-1)printf("\n");
		}
		if(ans[i].size()==0)
		{
			printf("\n");
		}
	}
	return 0;
}
