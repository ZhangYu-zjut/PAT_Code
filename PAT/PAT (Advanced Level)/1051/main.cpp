#include <iostream>
#include <stdio.h>
#include <stack> 

using namespace std;
stack<int>s;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//��ջģ���⣬˼·����judge��¼Y��N��num[]��¼��ջ���У�num2[]��¼��ջ���� 
//n��ѭ����ÿ������ջ�������ջ���е����֣�curr��Ϊ��ջ���еĵ�ǰ��š�
//while����ջ��Ԫ�����ջԪ����ͬ�Ҷ�ջ���գ�����ջ��Ԫ�س�ջ��curr++ 
//����ջ��������������ʱ��ֱ��flag=false
//������ѭ������ʱ������ջ��Ϊ�գ���flag=false
//����flag���YES����NO 
int num[1003];
int num2[1003];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int cap,length,n;
	int i,j,k;
	cin>>cap>>length>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<length;j++)
		{
			num[j]=j+1;
			scanf("%d",&num2[j]);
		}
		int curr=0;
		bool judge=true;
		while(!s.empty())
		{
			s.pop();
		}
		for(j=0;j<length;j++)
		{
			s.push(num[j]);
			if(s.size()>cap)
			{
				judge=false;
				break;
			}
			while(!s.empty()&&s.top()==num2[curr])//һ��Ҫ��!s.empty()������������ 
			{
				s.pop();
				curr++;
			}
		}
		if(!s.empty())judge=false;
		if(judge==true)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
