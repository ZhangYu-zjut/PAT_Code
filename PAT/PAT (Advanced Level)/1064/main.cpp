#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//思路：
//利用递归的思想，将中序序列中的数据放到最后的序列中 
//根据开始、结束序列的下标，获得节点个数n，并计算得到除了最后一层以外的层数。 
//根据层数，计算获得根节点的下标，然后将中序序列中的数据放到最后的序列中。 
//对根节点的左右子树进行相同的递归操作，左子树下标为2*i+1，右子树下标为2*i+2，注意递归结束条件。
//AC!!!!
int ans[1000];
int inorder[1000];
void levelorder(int start,int end,int index)
{
	if(start>end)return;
	int n=end-start+1;//节点总数
	int h=log(n+1)/log(2);//层高,除了最下面一层的层数,log(n+1)!!!!
	int leves=n-(pow(2,h)-1);//求最底层的叶子节点个数，2^h-1是除了叶子之外的节点个数 
	int root=start+(pow(2,h-1)-1)+min((int)pow(2,h-1),leves); //2^(h-1)是最下层的左子树的节点个数，想不清楚的时候就画个图！！ 
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
