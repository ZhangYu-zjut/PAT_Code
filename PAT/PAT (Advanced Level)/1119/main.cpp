#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
vector<int>in,pre,post;
bool uni=true;
int n;
void get(int prel,int prer,int postl,int postr)
{
	if(prel==prer)//��������������׶� 
	{
		in.push_back(pre[prel]);
		return;
	}
	if(post[postr]==pre[prel])//???
	{
		int x = postr-1;
		int i=prel+1;
		while(post[x]!=pre[i]&&i<=prer)i++;
		int leftnum = i-prel-1;//??
		if(leftnum>=1)//����������ʱ�Ŷ����������еݹ� 
		{
			get(prel+1,i-1,postl,postl+i-prel-2);
		}
		else
		{
			uni=false;
		}
		//�������ݹ������post[postr]��Ϊ�������ĸ��ڵ� 
		in.push_back(post[postr]);//???
		get(i,prer,postl+i-prel-1,postr-1);
	}
} 
int main(int argc, char** argv) {
	int temp;
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		pre.push_back(temp);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		post.push_back(temp);
	}
	get(0,n-1,0,n-1);
	if(uni)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	for(i=0;i<in.size();i++)
	{
		if(i==0)printf("%d",in[i]);
		else printf(" %d",in[i]);
	}
	printf("\n");//��仰������ϣ��� 
	return 0;
}
