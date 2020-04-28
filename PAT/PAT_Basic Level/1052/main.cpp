#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define N 20
struct emoji
{
	string hand[N];
	string eye[N];
	string mouth[N];
	int len[3]={0};
}s;
int num[5];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n,i,j,k,t;
	char str[200];
	string temp;
	int count;
	for(t=0;t<3;t++)
	{
		cin.getline(str,160);
		int k=0;
		count=0;
		for(i=0;i<strlen(str);i++)
		{
			if(str[i]=='[')
			{
				j=i+1;
				count++;
				while(str[j]!=']')
				{
					temp+=str[j];
					j++;
				}
				if(t==0)
				{
					s.hand[k]=temp;
					k++;	
				}
				if(t==1)
				{
					s.eye[k]=temp;
					k++;	
				}
				if(t==2)
				{
					s.mouth[k]=temp;
					k++;	
				}
					
			}
			temp="";
		}
		s.len[t]=count;
		//printf("%d\n",count);
	}
	int a;
	while(scanf("%d",&n)!=EOF)
	{
		for(j=0;j<n;j++)
		{
			for(i=0;i<5;i++)
			{
				scanf("%d",&num[i]);
				//cout<<s.hand[i]<<endl;
				//printf("s.len is:%d\n",s.len[i]);
			}
			if(num[0]>s.len[0]||num[1]>s.len[1]||num[2]>s.len[2]||num[3]>s.len[1]||num[4]>s.len[0])
			{
				printf("Are you kidding me? @\/@\n");
				break;
			}
			else
			{
				cout<<s.hand[num[0]-1]<<"("<<s.eye[num[1]-1]<<s.mouth[num[2]-1]<<s.eye[num[3]-1]<<")"<<s.hand[num[4]-1]<<endl;
			}
		}
	
	} 
	return 0;
}
