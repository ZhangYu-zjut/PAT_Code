#include <iostream>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PAT_B 1055 ������ ��25 �֣�
//˼·��
//������ͬѧ������߽��������������� 
//����˳��ѧ����Ϊ����飬��ÿ��ѧ�����кŽ��и�ֵ
//��ͬһ���ڵ�ѧ�������кŸ�ֵ���������ҵ�˳�����
//�����кź��к��ҵ���Ӧ��ѧ�����������
//ע�������ʱ���Ƕ�[1��n]��ѧ���������򣬲��Ұ����ֽ�����У�����
//ע��һЩϸ�ڡ�-1��-2.�ر���temp2��temp3��ֵ�� 

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
		return a.high>b.high;//���� 
	}
	else
	{
		return a.name<b.name;//���� 
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
		int p_row = n/k;//�����һ���⣬����ÿ������Ϊ p_row
		int last_row = n-(k-1)*p_row;//���һ������Ϊlast_row 
		for(i=1;i<=n;i++)
		{
			cin>>s;
			scanf("%d",&stu[i].high);
			stu[i].name=s;
		}
		sort(stu+1,stu+n+1,cmp);
		for(i=1;i<=n;i++)//��ÿһ��ѧ��ָ������ 
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
		for(i=1;i<=k;i++)//��ÿһ�ŵ���������row_num�� 
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
		for(i=1;i<=last_row;i++)//Ϊ��һ���е�ѧ��ָ�����ڵ����� 
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
		for(i=1+last_row;i<=n;i++)//Ϊ�������е�ѧ��ָ�����ڵ����� 
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
		for(i=1;i<=k;i++)//������ 
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
