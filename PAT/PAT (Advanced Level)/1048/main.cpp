#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//两端搜索的想法会在两个测试用例超时
//另外一种思路：打表，开一个数组存放每个数字出现的次数，直接比较num[i]和num[m-i]的数值是否大于0 
//注意特殊情况，目标和为14，而数字序列中只有一个7. 
int num[100100]={0};
int main(int argc, char** argv) {
	int n,m,i,j,k,temp;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		num[temp]++;
	}
	for(i=0;i<1001;i++)//num[i]>0才有可能是最后的答案 
	{
		if(num[i]>0)
		{
			num[i]--;//尝试减一 
			if(num[m-i]>0&&m>i)//m>i这句话没有也可以，因为当i>m时候，num[i]都是0，对最后的结果无影响 
			{
				printf("%d %d\n",i,m-i);
				return 0;
			}
			num[i]++;
		}
	}
	printf("No Solution\n");
	return 0;
}
