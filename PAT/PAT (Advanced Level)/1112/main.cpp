#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char ch[2000];
map<char,set<int>>ma;
map<char,int>m2;
map<char,int>m3;
set<char>st;
set<int>::iterator it;
int main(int argc, char** argv) {
	int k;
	bool last=true;
	scanf("%d%*c",&k);
	scanf("%s",ch);
	int length=strlen(ch);
	int i,j;
	for(i=0;i<length-1;i++)
	{
		int count=1;
		char ctemp=ch[i];
		while(ch[i]==ch[i+1]&&i<length-1)
		{
			count++;
			i++;
		}
		ma[ctemp].insert(count);
		m2[ctemp]=1;
		//i++;
	}
	for(i=0;i<length-1;i++)
	{
		it=ma[ch[i]].begin();
		bool judge=true;
		for(it=ma[ch[i]].begin();it!=ma[ch[i]].end();it++)
		{
			if(*it%k!=0)
			{
				judge=false;
				break;
			}
		}
		if(judge&&m2[ch[i]]==1)
		{
			m2[ch[i]]=2;
			m3[ch[i]]=1;
			printf("%c",ch[i]);
		}
	}
	printf("\n");
	for(i=0;i<length-1;i++)
	{
		if(m3[ch[i]]==1)
		{
			printf("%c",ch[i]);
			i+=k-1;
		}
		else
		{
			printf("%c",ch[i]);
		}
	}
	if(m3[ch[i]]!=1)
	{
		printf("%c",ch[i]);//
	}
	return 0;
}
