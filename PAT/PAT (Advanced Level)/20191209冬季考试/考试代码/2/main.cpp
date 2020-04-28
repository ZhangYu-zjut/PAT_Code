#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct stu
{
	string id;
	char rank;
	string place;
	string time;
	int score;
	int chose=0;
}su[10004];
struct site
{
	int id;
	int cnt;
}s[1005];
int str2int(string s)
{
	int ans=0;
	int size=s.length();
	int c=1;
	for(int i=size-1;i>=0;i--)
	{
		ans+=(s[i]-'0')*c;
		c*=10;
	}
	return ans;
}
bool cmp(stu a,stu b)
{
	/*if(a.rank!=b.rank)
	{
		return a.rank<b.rank;
	}*/
	if(a.score!=b.score)
	{
		return a.score>b.score;
	}
	else
	{
		return a.id<b.id;
	}
}
bool cmp2(site a,site b)
{
	if(a.cnt!=b.cnt)
	{
		return a.cnt>b.cnt;
	}
	else
	{
		return a.id<b.id;
	}
}
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	int m,n;
	scanf("%d%d",&n,&m);
	int i,j,k;
	int num;
	string temp;
	string no;
	for(i=0;i<n;i++)
	{
		cin>>no;
		cin>>num;
		su[i].rank=no[0];
		for(j=1;j<=3;j++)
		{
			temp+=no[j];
		}
		su[i].place=temp;
		temp.clear();
		for(j=5;j<=10;j++)
		{
			temp+=no[j];
		}
		su[i].time=temp;
		temp.clear();
		su[i].score=num;
		su[i].id=no;
	}
	int kind;
	string term;
	for(i=0;i<m;i++)
	{
		cin>>kind;
		cin>>term;
		if(kind==1)
		{
			cout<<"Case "<<i+1<<": "<<kind<<" "<<term<<endl;
			bool find=false;
			for(i=0;i<n;i++)
			{
				if(su[i].rank==term[0])
				{
					cout<<su[i].id<<" "<<su[i].score<<endl;
					find=true;
				}
			}
			if(!find)
			{
				printf("NA\n");
			}
		}
		if(kind==2)
		{
			int toscore=0,tonum=0;
			for(i=0;i<n;i++)
			{
				if(su[i].place==term)
				{
					toscore+=su[i].score;
					tonum++;
				}
			}
			cout<<"Case "<<i+1<<": "<<kind<<" "<<term<<endl;
			if(toscore==0&&tonum==0)
			{
				printf("NA\n");
			}
			else
			{
				printf("%d %d\n",tonum,toscore);
			}
		}
		if(kind==3)
		{
			cout<<"Case "<<i+1<<": "<<kind<<" "<<term<<endl;
			bool find=false;
			int length=0;
			for(i=0;i<1005;i++)
			{
				s[i].cnt=0;
			}
			for(i=0;i<n;i++)
			{
				if(su[i].time==term)
				{
					s[str2int(su[i].place)].cnt++;//
					s[str2int(su[i].place)].id=str2int(su[i].place);//
					find=true;
				}
			}
			if(!find)
			{
				printf("NA\n");
			}
			else
			{
				sort(s,s+1003,cmp2);
				for(j=0;j<1003;j++)
				{
					if(s[j].cnt==0)
					{
						break;
					}
					if(s[j].cnt>0)
					{
						printf("%d %d\n",s[j].id,s[j].cnt);	
					}	
				}
			}
			length=0;
		}
	}
	return 0;
}
