#include <iostream>
#include <stdio.h>
#include <stack> 

using namespace std;
stack<int>s;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//堆栈模拟题，思路：用judge记录Y或N，num[]记录入栈序列，num2[]记录出栈序列 
//n次循环，每次往堆栈里加入入栈序列的数字，curr记为出栈序列的当前序号。
//while（若栈顶元素与出栈元素相同且堆栈不空），则将栈顶元素出栈，curr++ 
//当堆栈个数大于总容量时，直接flag=false
//当上述循环结束时，若堆栈不为空，则flag=false
//根据flag输出YES或者NO 
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
			while(!s.empty()&&s.top()==num2[curr])//一定要加!s.empty()条件！！！！ 
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
