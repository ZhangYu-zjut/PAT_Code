#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//理解一下堆排序和插入排序，要求能够自己写代码！！！ 
const int N=110;
int n;
int origin[N],temp[N],change[N];
void show(int a[])
{
	for(int i=1;i<=n;i++)
	{
		if(i==1)printf("%d",a[i]);
		else printf(" %d",a[i]);
	}
}
bool same(int a[],int b[])
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
			return false;
		}
	}
	return true;
}
void downadjust(int low,int high)
{
	int i=low,j=2*i;
	while(j<=high)
	{
		if(j+1<=high&&temp[j+1]>temp[j])
		{
			j++;
		}
		if(temp[j]>temp[i])
		{
			swap(temp[i],temp[j]);
			i=j;
			j=2*i;
		}
		else
		{
			break;
		}
	}	
}

void heapsort()
{
	int i;
	bool flag=false;
	for(i=n/2;i>=1;i--)
	{
		downadjust(i,n);
	}
	for(i=n;i>1;i--)
	{
		if(i!=n && same(temp,change))
		{
			flag=true;
		}
		swap(temp[i],temp[1]);
		downadjust(1,i-1);
		if(flag==true)
		{
			show(temp);
			return;
		}
	}
	
}
bool insert()
{
	bool flag=false;
	for(int i=2;i<=n;i++)
	{
		if(i!=2&&same(change,temp))
		{
			flag=true;
		}
		sort(temp+1,temp+i+1);
		//下面这句话也能通过，很奇怪。。 
		//sort(temp,temp+i+1);
		if(flag==true)
		{
			return true;
		}
	}
	return false;
}
int main(int argc, char** argv) {
	cin>>n;
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&origin[i]);
		temp[i]=origin[i];
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&change[i]);
	}
	if(insert())
	{
		printf("Insertion Sort\n");
		show(temp);
	}
	else
	{
		printf("Heap Sort\n");
		for(i=1;i<=n;i++)
		{
			temp[i]=origin[i];
		}
		heapsort();
	}
	return 0;
}
