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
	//��������д�����д���
	//getline(cin,ch);//�����ٶ�����ַ�������£������������ʱ��Լ2417ms ,������ʱ��Ϊ6063ms 
	cin.getline(ch,4050000);//�����ٶ�����ַ�������£������������ʱ��Լ365ms,������ʱ��Ϊms 
	//clock_t end=clock();
	cout<<"���ڴ������Ժ󡣡�����";
	for(i=0;i<strlen(ch);i++)
	{
		if(isalnum(ch[i]))//�����жϸ��ַ��Ƿ�Ϊ�涨��Χ���ַ� 
		{
			temp+=tolower(ch[i]);//������뵽�ַ���ans�� 
		}
		if(!isalnum(ch[i])||i==strlen(ch)-1)//�����ǹ涨��Χ���ַ�������iΪ���һ��ѭ��(������Ǹ����ʽ���ͳ��)�� 
		{
			if(temp.length()!=0)//��֤�ַ����г��Ȳ��ܼ� 
			{
				mp[temp]++;//��Ӧ��map���ּ�һ 
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
	cout<<"����ʱ�䣺"<<1.0*(double)(end-start)<<endl;
	return 0;
}
