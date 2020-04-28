#include <iostream>
#include <stdio.h>
#include <string.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char str1[1010];
char str2[1010];
bool mark1[1010];//表示第一串是否被标记过，是的话为true。否则为false 
bool mark2[1010];//表示第二串的珠子能否在第一串中找到，能找到的话为true，否则为false。 
int main(int argc, char** argv) {
	int i,j;
	scanf("%s%s",str1,str2);
	int size1=strlen(str1);
	int size2=strlen(str2);
	for(i=0;i<size1;i++)
	{
		mark1[i]=false;//初始都没有被标记过 
	}
	for(i=0;i<size2;i++)
	{
		mark2[i]=false;//初始为不能找到 
	}
	for(i=0;i<size2;i++)
	{
		for(j=0;j<size1;j++)
		{
			if(str1[j]==str2[i]&&mark1[j]==false)
			{
				mark1[j]=true;
				mark2[i]=true;
				break;//一定要加break，不然会把后面所有的字符进行标记 
			}
		}
	} 
	bool have=true;
	int not_have=0;
	for(i=0;i<size2;i++)
	{
		if(mark2[i]==false)
		{
			have=false;
			not_have++;
		}
	}
	have==true?printf("Yes %d\n",size1-size2):printf("No %d\n",not_have); 

	return 0;
}
