#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AC!!!
struct student
{
	char name[12];
	char sex;
	char id[20];
	int score;
}stu[10000];
int main(int argc, char** argv) {
	int i,n,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s %c %s %d",stu[i].name,&stu[i].sex,stu[i].id,&stu[i].score);
	}
	int min=101;
	int max=-1;
	int index1=-1,index2=-1;
	for(i=0;i<n;i++)
	{
		if(stu[i].sex=='F')
		{
			if(stu[i].score>max)
			{
				max=stu[i].score;
				index1=i;
			}
		} 
		else
		{
			if(stu[i].score<min)
			{
				min=stu[i].score;
				index2=i;
			}
		} 
	}
	if(index1>=0&&index2>=0)
	{
		printf("%s %s\n",stu[index1].name,stu[index1].id);
		printf("%s %s\n",stu[index2].name,stu[index2].id);
		printf("%d\n",stu[index1].score-stu[index2].score);
	}
	else if(index1<0&&index2>=0)
	{
		printf("Absent\n");
		printf("%s %s\n",stu[index2].name,stu[index2].id);
		printf("NA\n");
	}
	else if(index2<0&&index1>=0)
	{
		printf("%s %s\n",stu[index1].name,stu[index1].id);
		printf("Absent\n");
		printf("NA\n");
	}
	else
	{
		printf("Absent\n");
		printf("Absent\n");
		printf("NA\n");
	}
	return 0;
}
