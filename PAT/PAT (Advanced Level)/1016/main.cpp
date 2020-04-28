#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AC!!!!
struct record
{
	char name[25];
	int month,dd,hh,mm;
	bool status;
}
rec[1005],temp;
int roll[26];
bool cmp(record a,record b)
{
	if(strcmp(a.name,b.name)!=0)
	{
		return strcmp(a.name,b.name)<0;
	}
	else if(a.month!=b.month)return a.month<b.month;
	else if(a.dd!=b.dd)return a.dd<b.dd;
	else if(a.hh!=b.hh)return a.hh<b.hh;
	else return a.mm<b.mm;
}
void ans(int on,int off,double &money,int &time)
{
	record temp = rec[on];
	while(temp.dd<rec[off].dd||temp.hh<rec[off].hh||temp.mm<rec[off].mm)
	{
		time++;
		temp.mm++;
		money+=roll[temp.hh];
		if(temp.mm>59)
		{
			temp.mm=0;
			temp.hh++;
			if(temp.hh>23)
			{
				temp.hh=0;
				temp.dd++;
			}
		}		
	}
}
int n,m;
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int i,j;
	for(i=0;i<24;i++)
	{
		scanf("%d",&roll[i]);
	} 
	scanf("%d",&n);
	char line[10];
	for(i=0;i<n;i++)
	{
		scanf("%s",rec[i].name);
		scanf("%d:%d:%d:%d",&rec[i].month,&rec[i].dd,&rec[i].hh,&rec[i].mm);
		scanf("%s",line);
		if(strcmp(line,"on-line")==0)
		{
			rec[i].status=true;
		}
		else rec[i].status=false;	
	}
	sort(rec,rec+n,cmp);

	int on=0,off,next;
	while(on<n)
	{
		int needprint=0;
		next=on;
		//找到后一个用户 
		while(next<n &&strcmp(rec[next].name,rec[on].name)==0)
		{
			if(needprint==0&&rec[next].status==true)
			{
				needprint=1;
			}
			else if(needprint==1&&rec[next].status==false)
			{
				needprint=2;
			}
			next++;
		}
		if(needprint<2)
		{
			on=next;
			continue;
		}
		double total=0.0;
		printf("%s %02d\n",rec[on].name,rec[on].month);
		while(on<next)//对每一个用户进行操作 进行对应的输出和数据的相加 
		{
			while(on<next-1&&!(rec[on].status==true&&(rec[on+1].status==false)))
			{
				on++;
			}
			off=on+1;
			if(off==next)
			{
				on = next;
				break;
			}
			int time=0;
			double money=0.0;
			ans(on,off,money,time);
			total+=money;
			printf("%02d:%02d:%02d ",rec[on].dd,rec[on].hh,rec[on].mm);
			printf("%02d:%02d:%02d %d $%.2lf\n",rec[off].dd,rec[off].hh,rec[off].mm,time,money/100.0);
			on=off+1;
		}
		printf("Total amount: $%.2lf\n",total/100.0); 
	}
	return 0;
}
