#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AC!!!!
struct student
{
	char id[10];
	char name[10];
	int score;
}stu[100001];
bool cmp1(student a,student b)
{
	return strcmp(a.id,b.id)<0;
}
bool cmp2(student a,student b)
{
	if(strcmp(a.name,b.name)!=0)
	{
		return strcmp(a.name,b.name)<0;
	}
	else
	{
		return strcmp(a.id,b.id)<0;
	}
	
}
bool cmp3(student a,student b)
{
	if(a.score!=b.score)
	{
		return a.score<b.score;
	}
	else
	{
		return strcmp(a.id,b.id)<0;
	}
}
int main(int argc, char** argv) {
	int i,j,k,m,n,choice;
	scanf("%d%d",&n,&choice);
	for(i=0;i<n;i++)
	{
		scanf("%s%s%d",stu[i].id,stu[i].name,&stu[i].score);
	}
	if(choice==1)
	{
		sort(stu,stu+n,cmp1);
	}
	if(choice==2)
	{
		sort(stu,stu+n,cmp2);
	}
	if(choice==3)
	{
		sort(stu,stu+n,cmp3);
	}
	for(i=0;i<n;i++)
	{
		printf("%s %s %d\n",stu[i].id,stu[i].name,stu[i].score);
	}
	return 0;
}
