#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//˼·��
//���õݹ��˼�룬�����������е����ݷŵ����������� 
//���ݿ�ʼ���������е��±꣬��ýڵ����n��������õ��������һ������Ĳ����� 
//���ݲ����������ø��ڵ���±꣬Ȼ�����������е����ݷŵ����������С� 
//�Ը��ڵ����������������ͬ�ĵݹ�������������±�Ϊ2*i+1���������±�Ϊ2*i+2��ע��ݹ����������
//AC!!!!
int ans[1000];
int inorder[1000];
void levelorder(int start,int end,int index)
{
	if(start>end)return;
	int n=end-start+1;//�ڵ�����
	int h=log(n+1)/log(2);//���,����������һ��Ĳ���,log(n+1)!!!!
	int leves=n-(pow(2,h)-1);//����ײ��Ҷ�ӽڵ������2^h-1�ǳ���Ҷ��֮��Ľڵ���� 
	int root=start+(pow(2,h-1)-1)+min((int)pow(2,h-1),leves); //2^(h-1)�����²���������Ľڵ�������벻�����ʱ��ͻ���ͼ���� 
	ans[index]=inorder[root];
	levelorder(start,root-1,2*index+1);
	levelorder(root+1,end,2*index+2);
}
int main(int argc, char** argv) {
	int n,i,j,k,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&inorder[i]);
	} 
	sort(inorder,inorder+n);
	levelorder(0,n-1,0);
	for(i=0;i<n;i++)
	{
		if(i==0)printf("%d",ans[i]);
		else printf(" %d",ans[i]);
	}
	return 0;
}
