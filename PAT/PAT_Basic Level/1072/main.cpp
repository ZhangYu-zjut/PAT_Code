#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//PAT_B1072 ¿ªÑ§¼ÄÓï AC!!!
struct student
{
	char name[5];
	int num;
	string goods[11];
}stu[1002];
char str[10];
string check[7];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n,m;
	int i,j;
	int k,p;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int sum_stu=0;
		int sum_goods=0;
		for(i=0;i<m;i++)//×Ö·û´®Êý×é¸³³õÖµ 
		{
			//check[i]='';
		}
		for(i=0;i<m;i++)//¶ÁÈë×Ö·û´® 
		{
			scanf("%s",str);
			for(j=0;j<strlen(str);j++)
			{
				check[i]+=str[j];
			}
		}
		for(i=0;i<n;i++)
		{
			scanf("%s%d",stu[i].name,&stu[i].num);
			for(j=0;j<stu[i].num;j++)
			{
				scanf("%s",str);
				for(p=0;p<strlen(str);p++)
				{
					stu[i].goods[j]+=str[p];
				}
			}
		}
		
		for(i=0;i<n;i++)
		{
			bool have=false;
			bool stu_check=false;
			for(j=0;j<stu[i].num;j++)
			{
				for(k=0;k<m;k++)
				{
					if(check[k]==stu[i].goods[j])
					{
						if(have==false)
						{
							printf("%s:",stu[i].name);
							have=true;
						}
						printf(" ");				
						cout<<stu[i].goods[j];
						sum_goods++;
						stu_check=true;
					}
				}
				
			} 
			if(stu_check==true)
			{
				sum_stu++;
				printf("\n");
			}	
			//printf("\n");
		}
		printf("%d %d",sum_stu,sum_goods);
		 
		
	}
	return 0;
}
