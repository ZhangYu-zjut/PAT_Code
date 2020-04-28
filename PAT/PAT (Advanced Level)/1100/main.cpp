#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//由于数据范围不大，直接对所有数据进行打表处理，然后读入对应数据，输出即可
//在读入数据时候，由于会有数字或者字符，所以用getline(cin,str)读取一行数据
//若第一个字符为数字，则判断为数字，然后将字符串转化为数字即可
//若读入的是字符串，则直接从表中找到对应的数字输出即可，注意打表的时候也需要加上空格一起打表！！ 
//由于火星上是十三进行，将火星文转化为地球上的数字时候，十位要乘以13 
//AC!!
string unit[]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string ten[]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
map<string,int>str2int;
string int2str[1000];
void init()
{
	int i,j;
	for(i=0;i<13;i++)
	{
		int2str[i]=unit[i];
		str2int[unit[i]]=i;
		int2str[i*13]=ten[i];
		str2int[ten[i]]=i*13;
	}
	for(i=1;i<13;i++)
	{
		for(j=1;j<13;j++)
		{
			int2str[i*13+j]=ten[i]+" "+unit[j];
			str2int[ten[i]+" "+unit[j]]=i*13+j;
		}
	}
}
int main(int argc, char** argv) {
	init();
	string str;
	int n,i,j;
	scanf("%d%*c",&n);
	for(i=0;i<n;i++)
	{
		getline(cin,str);
		if(str[0]<='9'&&str[0]>='0')
		{
			int num=0;
			for(j=0;j<str.length();j++)
			{
				num = num*10 + (str[j]-'0');
			}
			cout<<int2str[num]<<endl;
		}
		else
		{
			cout<<str2int[str]<<endl;
		}
	}
	return 0;
}
