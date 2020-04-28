#include <iostream>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PAT_B 1055 集体照 （25 分）
//思路：
//对所有同学按照身高降序，名字升序排列 
//按照顺序将学生分为多个组，对每个学生的行号进行赋值
//对同一组内的学生进行列号赋值，左右左右的顺序进行
//根据行号和列号找到对应的学生进行输出。
//注意排序的时候是对[1，n]的学生进行排序，并且按名字降序进行！！！
//注意一些细节。-1，-2.特别是temp2和temp3的值。 

struct student
{
	string name;
	int high;
	int row;
	int column;
}stu[10010];
bool cmp(student a,student b)
{
	if(a.high!=b.high)
	{
		return a.high>b.high;//降序 
	}
	else
	{
		return a.name<b.name;//升序 
	}
}
int row_num[1000];
int main(int argc, char** argv) {
	freopen("test.txt", "r", stdin);
	int t, k;
	int i, j, m,n,g;
	string s;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		int p_row = n/k;//除最后一排外，其他每排人数为 p_row
		int last_row = n-(k-1)*p_row;//最后一排人数为last_row 
		for(i=1;i<=n;i++)
		{
			cin>>s;
			scanf("%d",&stu[i].high);
			stu[i].name=s;
		}
		sort(stu+1,stu+n+1,cmp);
		for(i=1;i<=n;i++)//给每一个学生指定排数 
		{
			if(i<=last_row)
			{
				stu[i].row=1;
			}
			else
			{
				stu[i].row=((i-1-last_row)/p_row)+2;
			}
		}
		for(i=1;i<=k;i++)//将每一排的人数放入row_num中 
		{
			if(i==1)
			{
				row_num[i]=last_row;
			}
			else
			{
				row_num[i]=p_row;
			}
		}
		for(i=1;i<=last_row;i++)//为第一排中的学生指定所在的列数 
		{
			int temp2=(i-2)/2;
			{
				if(i==1)
				{
					stu[i].column=0.5*row_num[1]+1;;
				}
				else
				{
					stu[i].column=stu[1].column+pow(-1,(i-1))*(temp2+1);
				}
			}
		}
		for(i=1+last_row;i<=n;i++)//为其他排中的学生指定所在的列数 
		{
			int temp;
			int temp3=(i-2-last_row-p_row*(stu[i].row-2))/2;
			{
				if((i-1-last_row)%p_row==0)
				{
					stu[i].column=0.5*p_row+1;
					temp=stu[i].column;
				}
				else
				{
					stu[i].column=temp+pow(-1,(i-1-last_row-p_row*(stu[i].row-2)))*(temp3+1);
				}				
			}
		}
		for(i=1;i<=k;i++)//结果输出 
		{
			for(j=1;j<=row_num[i];j++)
			{
				for(g=1;g<=n;g++)
				{
					if(stu[g].row==i&&stu[g].column==j)
					{
						if(j==1)
						{
							cout<<stu[g].name;
						}
						else
						{
							cout<<" "<<stu[g].name;
						}
					}
				}
			}
			printf("\n");
		}
	}
	 
	return 0;
}
