#include <iostream>
#include <stdio.h>
//#include <string>
#include <string.h>
//using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//������볤��
//�Ƿ��зǷ��ַ� 
//�Ƿ������ĸ����
////ע������ʱ��Ҫ��scanf,��Ϊ�п���������пո񣬿�����cin.getline(str,90),�����ڶ�������nʱ����scanf("%d\n",&n)!=EOF
char str[100]; 
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n;
	int i,j,k;
	while(scanf("%d\n",&n)!=EOF)
	{
		for(j=0;j<n;j++)
		{
			gets(str);
			if(strlen(str)<6)
			{
				printf("Your password is tai duan le.\n");
			}
			else
			{
				bool word=false;
				bool num=false;
				bool point=false;
				bool luan=false;
				for(i=0;i<strlen(str);i++)
				{
					if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
					{
						word=true;
					}
					else if(str[i]>='0'&&str[i]<='9')
					{
						num=true;
					}
					else if(str[i]=='.')
					{
						point=true;
					}
					else
					{
						printf("Your password is tai luan le.\n");
						luan=true;
						break;
					}
				}
				if(luan==false)
				{
					if(num==true&&word==true)
					{
						printf("Your password is wan mei.\n");
					}
					if(num==false&& word == true)
					{
						printf("Your password needs shu zi.\n");
					}
					if(word==false&& num == true)
					{
						printf("Your password needs zi mu.\n");
					}
				}
				
			}
		}
		
	}
	return 0;
}
