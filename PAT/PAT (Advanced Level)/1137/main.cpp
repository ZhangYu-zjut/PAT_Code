#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
using namespace std;
map<string,int>str2int;
map<int,string>int2str;
int stu_num=0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//简单的排序题目，思路清晰，注意细节就能通过！！
//注意题目中发final是计算后的总评分数，不是期末考试的分数！！ 
struct student
{
	string name;
	int gp=-1;
	int gmid=-1;
	int gfinal=-1;
	int g=-1;
}stu[100004];
bool cmp(student a,student b)
{
	if(a.g!=b.g)
	{
		return a.g>b.g;
	}
	else
	{
		return a.name<b.name;
	}
}
int change(string str)
{
	if(str2int.find(str)!=str2int.end())
	{
		return str2int[str];
	}
	else
	{
		str2int[str]=stu_num;
		int2str[stu_num]=str;
		return stu_num++;
	}
}
int main(int argc, char** argv) {
	int p,m,n;
	scanf("%d%d%d",&p,&m,&n);
	int i,j,k;
	string a;
	int temp,id;
	for(i=0;i<p;i++)
	{
		cin>>a>>temp;
		id=change(a);
		stu[id].gp=temp;
		stu[id].name=a;
	}
	for(i=0;i<m;i++)
	{
		cin>>a>>temp;
		id=change(a);
		stu[id].gmid=temp;
		stu[id].name=a;
	}
	for(i=0;i<n;i++)
	{
		cin>>a>>temp;
		id=change(a);
		stu[id].gfinal=temp;
		stu[id].name=a;
	}
	for(i=0;i<stu_num;i++)
	{
		if(stu[i].gmid>0||stu[i].gfinal>0)
		{
			if(stu[i].gmid>stu[i].gfinal)
			{
				stu[i].g=0.4*stu[i].gmid+0.6*stu[i].gfinal+0.5;
			}
			else
			{
				stu[i].g=stu[i].gfinal;	
			}
		} 
	} 
	sort(stu,stu+stu_num,cmp);
	for(i=0;i<stu_num;i++)
	{
		if(stu[i].gp>=200&&stu[i].g>=60)//注意题目的意思是最后的总评成绩！！！ 
		{
			cout<<stu[i].name<<" "<<stu[i].gp<<" ";
			cout<<stu[i].gmid<<" "<<stu[i].gfinal<<" ";
			cout<<stu[i].g<<endl;
		}
	}
	return 0;
}
