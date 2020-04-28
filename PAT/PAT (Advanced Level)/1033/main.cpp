#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct station
{
	double price;
	int dis;
}s[501];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//用now_dis,nowprice分别存储当前位置以及当前加油站的价格，用leftdis存储还能走的路程（还有的油量）
//用cost存储总的油费。minprice，minpricedis分别存储当前找到的最小的油价以及对应的距离位置。 
//每次在距离范围内，查找油价比当前油价小的加油站，每次都希望能以更低的油价进行行驶（贪心） 
//查找第一个在范围内的加油站，找到，说明当前位置加一定的油就能到达下一个加油站，到达下一个加油站时，leftdis=0。另外更新开支和当前距离和当前油价，并增加总油费 
//若没有找到，则查找是否存在小于inf的油价，若找到，说明需要在当前位置的加油站加满油，然后到达下一个加油站，到达下一个加油站时，leftdis>0更新开支和当前距离和当前油价，并增加总油费 
//若均没有找到，说明不存在对应的加油站，更新能够到达的最远距离，并直接将最终的距离输出 
//AC!!!!
bool cmp(station a,station b)
{
	return a.dis<b.dis;
}
int main(int argc, char** argv) {
	int inf=1000000;
	int cap,distance,avg,n;
	scanf("%d%d%d%d",&cap,&distance,&avg,&n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		scanf("%lf%d",&s[i].price,&s[i].dis);
	}
	sort(s,s+n,cmp);
	double now_price,next_price;//当前油价和下一站的油价 
	double next_pos;//当前位置，下一站位置 
	double cost=0.0;//总的花费 
	double min_price=150;
	if(s[0].dis!=0)//特殊情况，起始位置没有加油站，直接结束！！！！ 
	{
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	s[n].price=0;
	s[n].dis=distance;
	double now_dis=0;
	now_price=s[0].price;
	double leftdis=0.0;
	while(now_dis<distance)
	{
		double max_dis=now_dis+cap*avg;
		double minpricedis=0;
		double minprice=inf;
		bool find_sta=false;//是否找到了最便宜的加油站 
		bool sta=false;//是否存在加油站 
		int flag=0;		
		for(i=1;i<=n&&max_dis>=s[i].dis;i++)
		{
			if(s[i].dis<=now_dis)continue; 
			if(s[i].price<now_price)
			{
				cost+=(s[i].dis-now_dis-leftdis)/avg*now_price; 
				now_price=s[i].price;
				now_dis=s[i].dis;
				flag=1;
				leftdis=0;//????
				break;
			}
			if(s[i].price<minprice)
			{
				minprice=s[i].price;
				minpricedis=s[i].dis;
			}
			//没找到的话，可能是没有加油站，或者价格都比当前的加油站高 
		}
		if(flag==0&&minprice!=inf)//找到价格较大的加油站 
		{
			cost+=(cap-leftdis/avg)*now_price;//??????
			//leftdis=avg*cap-(s[i].dis-now_dis);?????
			leftdis=avg*cap-(minpricedis-now_dis);////??????
			now_price=minprice;
			now_dis=minpricedis;
		}
		if(flag==0&&minprice==inf)//没有找到加油站 
		{
			now_dis+=cap*avg; 
			printf("The maximum travel distance = %.2lf",now_dis); 
			return 0;
		}
	}
	printf("%.2lf",cost);
	return 0;
}
