#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string str2[]={"","yi","er","san","si","wu","liu","qi","ba","jiu"};
string str[]={"","","Shi","Bai","Qian"};
string swan="Wan";
string syi="Yi";
string sling="ling";
string sfu="fu";
char ch[20];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n;
	int i,j;
	while(scanf("%s",ch)!=EOF)
	{
		int length=0;
		bool pos=true;
		bool yi=false;
		bool wan=false;
		bool ge=false;
		if(ch[0]=='-')
		{
			pos=false; 
			length=strlen(ch);
			if(length==10)
			{
				yi=true;
				wan=true;
			}
			else if(length>=6&&length<=9)
			{
				wan=true;
			}
		}
		
		else
		{
			pos=true;
			length=strlen(ch);	
			if(length==9)
			{
				yi=true;
				wan=true;
			}
			else if(length>=5&&length<=8)
			{
				wan=true;
			}
		}
		
		if(pos==false)
		{
			cout<<"Fu ";
			bool zero=false;
			for(i=1;i<length;i++)//
			{
				int temp=((length-1-i)%4);
				if(ch[i]=='0')
				{
					zero=true;
					continue;
				}
				if(ch[i]!='0')
				{
					if(zero==true)
					{
						cout<<" ling";
						zero=false;
					}
					if(i==1)cout<<str2[ch[i]-'0'];
					else cout<<" "<<str2[ch[i]-'0'];
					switch(temp)
					{
						case 1:cout<<" Shi";break;
						case 2:cout<<" Bai";break;
						case 3:cout<<" Qian";break;
					}
					if(i==1&&yi==true)
					{
						cout<<" Yi";
					}
					if(i==length-5&&wan==true)
					{
						cout<<" Wan";
					}
				}
			}
		}
		else
		{
			bool zero=false;
			int count=0;
			int count1=0;
			int count2=0;
			for(i=0;i<length;i++)//
			{
				int temp=((length-1-i)%4);
				if(ch[i]=='0')
				{
					if(i>=length-4&&i<=length-1&&length>5&&length<8)
					{
						count1++;
						if(i==length-1)
						{
							if(count1==4)cout<<" Wan";
						}
					}
					if(i>=length-8&&i<=length-1&&length>8)
					{
						count2++;
						if(i==length-1)
						{
							if(count2==8)cout<<" Yi";
						}
					}	
					else continue;
					zero=true;
					continue;
				}
				if(ch[i]!='0')
				{
					if(zero==true)
					{
						{
							cout<<" ling";
							zero=false;
						}

					}
					if(i==0)cout<<str2[ch[i]-'0'];
					else cout<<" "<<str2[ch[i]-'0'];
					switch(temp)
					{
						case 1:cout<<" Shi";break;
						case 2:cout<<" Bai";break;
						case 3:cout<<" Qian";break;
					}
					if(i==0&&yi==true)
					{
						cout<<" Yi";
					}
					if(i==(length-5)&&wan==true)
					{
						cout<<" Wan";
					}
				}
			}
			cout<<endl;
		}
	} 
	return 0;
}
