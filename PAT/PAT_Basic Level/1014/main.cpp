#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PAT_B 1014 福尔摩斯的约会 （20 分）有一个测试点过不了，只能拿18分 
char s1[100]; 
char s2[100]; 
char s3[100]; 
char s4[100]; 
char days[][4]={
	"","MON","TUE","WED","THU","FRI","SAT","SUN"
};
char hours[][4]={
	"00","01","02","03",
	"04","05","06","07",
	"08","09","10","11",
	"12","13","14","15",
	"16","17","18","19",
	"20","21","22","23"
};
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n;
	int i,j;
	int day,hour,min;
	scanf("%s",s1);
	scanf("%s",s2);
	scanf("%s",s3);
	scanf("%s",s4);
	bool first=true;
	for(i=0;i<strlen(s1);i++)
	{
		if(s1[i]==s2[i]&&first==false)
		{
			if(s1[i]>='0'&&s1[i]<='9')
			{
				hour=s1[i]-'0';
			}
			else if(s1[i]>='A'&&s1[i]<='N')
			{
				hour=s1[i]-'A'+10;
			}
		}
		if(s1[i]==s2[i]&&first==true&&s1[i]>='A'&&s1[i]<='G')
		{
			day=s1[i]-'A'+1;
			first=false;
		}
	}
	for(i=0;i<strlen(s3);i++)
	{
		if(s3[i]==s4[i]&&((s3[i]>='a'&&s3[i]<='z')||(s3[i]>='A'&&s3[i]<='Z')))
		{
			min=i;
		}
	}
	printf("%s %s:%02d\n",days[day],hours[hour],min);
	return 0;
}
