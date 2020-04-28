#include <iostream>
#include <stdio.h> 
#include <map>
#include <set>
#include <string>
#include <string.h>
#include <time.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//string ch;
char ch[4050000];
//string c; 
string temp;
string ans;
int main(int argc, char** argv) {
	clock_t start=clock(); 
	freopen("test.txt","r",stdin);
	map<string,int>mp;
	int m,n,k,i,j;
	//下面这种写法会有错误：
	//getline(cin,ch);//在三百多万个字符的情况下，这条语句运行时间约2417ms ,总运行时间为6063ms 
	cin.getline(ch,4050000);//在三百多万个字符的情况下，这条语句运行时间约365ms,总运行时间为ms 
	//clock_t end=clock();
	cout<<"正在处理，请稍后。。。。";
	for(i=0;i<strlen(ch);i++)
	{
		if(isalnum(ch[i]))//首先判断该字符是否为规定范围的字符 
		{
			temp+=tolower(ch[i]);//是则加入到字符串ans中 
		}
		if(!isalnum(ch[i])||i==strlen(ch)-1)//若不是规定范围的字符串或者i为最后一次循环(对最后那个单词进行统计)。 
		{
			if(temp.length()!=0)//保证字符串有长度才能加 
			{
				mp[temp]++;//对应的map数字加一 
			}
			temp="";
		}
		//temp="";
	}
	int max=0;
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		if(it->second>max)
		{
			max=it->second;
			ans=it->first;
		}
	}
	cout<<ans<<" "<<max<<endl;
	clock_t end=clock();
	printf("end is:%d\n",end);
	cout<<"运行时间："<<1.0*(double)(end-start)<<endl;
	return 0;
}
