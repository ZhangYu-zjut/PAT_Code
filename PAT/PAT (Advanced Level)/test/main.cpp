#include <iostream>

#include <stdio.h>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
	char name[100];
	char num[100];
	int grade;
}stu[1000];
bool cmp(student a,student b)
{
	return (a.grade>b.grade);
}
int main(int argc, char* argv[])
{
	int n;
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s%s%d",&stu[i].name,&stu[i].num,&stu[i].grade);
	}
	int start,end;
	int count=0;
	scanf("%d%d",&start,&end);
	sort(stu,stu+n,cmp);
	for(i=0;i<n;i++)
	{
	  if(stu[i].grade>=start&&stu[i].grade<=end)
	  {
	    printf("%s %s\n",stu[i].name,stu[i].num);
	    count++;
	  }
	}
	if(count==0)
	{
	  printf("NONE\n");
	}
/*	void insert(node* &root,int x)
	{
		if(root==NULL)
		{
			root = newnode(x);
		}
		if(x==root->data)
		{
			return;
		}
		else if(x<node->left)
		{
			insert(root->left,x);
		}
		else
		{
			insert(root->right,x);
		}
	} */
	return 0;
}
