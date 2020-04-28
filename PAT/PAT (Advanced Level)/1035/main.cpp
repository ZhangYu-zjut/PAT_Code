#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//ºÚµ•Ã‚£¨AC!!!! 
char name[1001][20];
char pass[1001][20];
vector <int>v;
int main(int argc, char** argv) {
	int n,i,j,k;
	int count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		//cin>>name[i]>>pass[i];
		scanf("%s%s",name[i],pass[i]);
	}
	for(i=0;i<n;i++)
	{
		bool flag=false;
		for(j=0;j<strlen(pass[i]);j++)
		{
			if(pass[i][j]=='1')
			{
				pass[i][j]='@';
				flag=true;
			}
			if(pass[i][j]=='l')
			{
				pass[i][j]='L';
				flag=true;
			}
			if(pass[i][j]=='O')
			{
				pass[i][j]='o';
				flag=true;
			}
			if(pass[i][j]=='0')
			{
				pass[i][j]='%';
				flag=true;
			}
		}
		if(flag==true)
		{
			v.push_back(i);
			count++;
		}
	}
	if(count==0)
	{
		if(n==1)printf("There is %d account and no account is modified",n);
		else printf("There are %d accounts and no account is modified",n);
	}
	else
	{
		printf("%d\n",count);
		for(i=0;i<v.size();i++)
		{
			printf("%s %s\n",name[v[i]],pass[v[i]]);
			//cout<<name[v[i]]<<" "<<pass[v[i]]<<endl;
		}
	}
	return 0;
}
