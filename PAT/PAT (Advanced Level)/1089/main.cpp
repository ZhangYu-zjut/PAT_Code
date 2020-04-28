#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int origin[103],copy2[103],changed[103];
int n;
void show(int a[])
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i==0)printf("%d",a[i]);
		else printf(" %d",a[i]);
	}
	printf("\n");
}
bool cmp(int a[],int b[])
{
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			return false;
		}
	}
	return true;
}
void merge()
{
	int i,j;
	bool ans=false;
	for(i=2;i/2<=n;i*=2)
	{
		if(i!=2&&cmp(copy2,changed))
		{
			ans=true;
		}
		for(j=0;j<n;j+=i)
		{
			sort(copy2+j,copy2+min(j+i,n));
		}
		if(ans)
		{
			show(copy2);
			return;
		}
	}
	return;
}
bool insert()
{
	int i,j;
	bool ans=false;//一定要赋初值 ！！！！ 
	for(i=1;i<n;i++)
	{
		if(i!=1&&cmp(copy2,changed))	
		{
			ans=true;
		}
		j=i;
		int temp=copy2[j];
		while(j>0&&copy2[j-1]>temp)
		{
			copy2[j]=copy2[j-1];
			j--;
		}
		copy2[j]=temp;
		if(ans)
		{
			return true;
		}
	} 
	return false;
}
int main(int argc, char** argv) {
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		scanf("%d",&origin[i]);
		copy2[i]=origin[i];
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&changed[i]);
	}
	if(insert())
	{
		printf("Insertion Sort\n");
		show(copy2);
	}
	else
	{
		printf("Merge Sort\n");
		for(i=0;i<n;i++)
		{
			copy2[i]=origin[i];
		}
		merge(); 
	}
	return 0;
}
