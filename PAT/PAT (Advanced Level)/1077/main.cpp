#include <iostream>
#include <string>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//ע��˼·��
//���Ȱ������ַ�����ת
//Ȼ��ѵ�һ���ַ����ĵ�һ���ַ������������ַ����бȽϣ���������������һ
//ֱ�����ڲ���ȵ��ַ���������ռ���ֵ�����Ӧ���ַ����ɣ����� 
//AC!!
string str[200];
int main(int argc, char** argv) {
	int n,i,j,k;
	scanf("%d%*c",&n);
	int minlen=256;
	for(i=0;i<n;i++)
	{
		getline(cin,str[i]);
		if(str[i].length()<minlen)minlen=str[i].length();
		for(j=0;j<str[i].length()/2;j++)
		{
			char temp = str[i][j];
			str[i][j]=str[i][str[i].length()-1-j];
			str[i][str[i].length()-1-j]=temp;
		}
	}
	int count=0;
	bool exit=true;
	for(i=0;i<minlen;i++)
	{
		char te=str[0][i];
		for(j=1;j<n;j++)
		{
			if(te!=str[j][i])
			{
				exit=false;
				break;
			}
		}
		if(exit)
		{
			count++;	
		}
		else break;
	}
	if(count>0)
	{
		for(i=count-1;i>=0;i--)
		{
			printf("%c",str[0][i]);
		}
	}
	else
	{
		cout<<"nai";
	}
	return 0;
}
