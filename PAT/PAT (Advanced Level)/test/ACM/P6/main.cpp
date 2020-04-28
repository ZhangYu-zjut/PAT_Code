#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

vector<int>v[100];
string s;
char ch[10000];
bool find2=false;
void BFS(int x)
{
	if(x=='m'-'a')
	{
		find2=true;
		return;
	}
	for(int i=0;i<v[x].size();i++)
	{
		BFS(v[x][i]);
	}
}
int main(int argc, char** argv) {
	int T=100;
	int i,j; 
	while(scanf("%s",ch)!=EOF)
	{
		for(i=0;i<100;i++) 
		{
			v[i].clear();
		}
		int n=0;
		int size=strlen(ch);
			int st=ch[0]-'a';
			int ed=ch[size-1]-'a';
			v[st].push_back(ed);
			n++;
		
		find2=false;
		for(;;)
		{
			scanf("%s",ch);
			if(ch[0]=='0')
			{
				break;
			}
			int size=strlen(ch);
			int st=ch[0]-'a';
			int ed=ch[size-1]-'a';
			v[st].push_back(ed);
			n++;
		} 
		int b='b'-'a';
		for(i=0;i<v[b].size();i++)
		{
			BFS(b);
		}
		if(find2)printf("Yes.\n");
		else printf("No.\n");
	} 
	
	return 0;
}
