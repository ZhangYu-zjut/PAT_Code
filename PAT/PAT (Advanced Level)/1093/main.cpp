#include <iostream>
#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�������ᳬʱ
//PAT�ǶԳƵģ�����Aǡ�����м��λ��
//�����ҵ�ĳ��A��ߵ�P�������ұߵ�T������������˾��Ǻ������A��PAT����
//ֻ��Ҫ���һ��ѭ���Ϳ��Լ���������������ʱ�临�Ӷȣ��� 
//AC!!!
char ch[100005];
int rightt[100005];
int leftp[100005];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	while(scanf("%s",ch)!=EOF)
	{
		int length=strlen(ch);
		int i,j;
		int countp=0;
		for(i=0;i<length;i++)
		{
		
			if(ch[i]=='P')
			{
				countp++;
			}
			if(ch[i]=='A')
			{
				leftp[i]=countp;
			}
		} 
		int countt=0;
		for(i=length-1;i>=0;i--)
		{
			if(ch[i]=='T')
			{
				countt++;
			}
			if(ch[i]=='A')
			{
				rightt[i]=countt;
			}
		}
		long long sum=0;
		for(i=0;i<length;i++)
		{
			if(ch[i]=='A')
			{
				sum+=leftp[i]*rightt[i];
			}
		}	
		printf("%lld\n",sum%1000000007);//ע����Ŀ˵�ģ��ܴ�ʱ��ȡģ 
	} 
	return 0;
}
