#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AC!!!!
//AC!!! ע����0���ڵ�λ�ú������ֵ��� 
int pos[100005];
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	int n;	
	while(scanf("%d",&n)!=EOF)
	{
		int i,j,k=1;
		int left=0,count=0,te;
		int st,temp,temp2,tar;
		for(i=0;i<n;i++)
		{
			scanf("%d",&te);
			pos[te]=i; 
			if(pos[te]!=te&&te!=0)//ע��left++������ 
			{
				left++;
			}
		}
		while(left>0)
		{
			if(pos[0]==0)//��ֵ0���ڵ�λ��Ϊ0  
			{
				while(pos[k]==k)
				{
					k++;
				}
				//printf("k is%d\n",k);
				swap(pos[0],pos[k]);
				count++;
			}
			while(pos[0]!=0)
			{
				swap(pos[0],pos[pos[0]]);
				left--;
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
