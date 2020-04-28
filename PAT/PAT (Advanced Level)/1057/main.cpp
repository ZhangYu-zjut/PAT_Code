#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int block[317];
int hashtable[100005];
const int sqrn=316;//这个数值是316还是317都可以AC 
stack<int>st;
void Push(int x)
{
	st.push(x);
	block[x/sqrn]++;
	hashtable[x]++;
}
void Pop()
{
	if(st.size()==0)
	{
		printf("Invalid\n");
		return;
	}
	int ans=st.top();
	printf("%d\n",ans);
	st.pop();
	block[ans/sqrn]--;
	hashtable[ans]--;
}
void Median()
{
	if(st.size()==0)
	{
		printf("Invalid\n");
		return;
	}
	int k,n=st.size();
	if(n%2==0)
	{
		k=n/2;
	}
	else k=(n+1)/2;
	int sum=0,index=-1;
	while(sum < k)
	{
		index++;
		sum += block[index];
	}
	int num=index*sqrn;//下一步开始加的位置 
	sum = sum - block[index];
	int t=num-1;
	while(sum<k)//这个地方刚开始的时候错误，应该从在sum的基础上，从位置hashtable[num]处开始相加！！！ 
	{
		t++;
		sum+=hashtable[t];
	}
	printf("%d\n",t);
	
}
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	int i,j,k,n;
	string str;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		cin>>str;
		if(str=="Push")
		{
			int temp;
			cin>>temp;
			Push(temp);
		}
		else if(str=="Pop")
		{
			Pop();
		}
		else
		{
			Median();
		}
	}
	return 0;
}
