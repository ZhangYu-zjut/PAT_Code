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
//��now_dis,nowprice�ֱ�洢��ǰλ���Լ���ǰ����վ�ļ۸���leftdis�洢�����ߵ�·�̣����е�������
//��cost�洢�ܵ��ͷѡ�minprice��minpricedis�ֱ�洢��ǰ�ҵ�����С���ͼ��Լ���Ӧ�ľ���λ�á� 
//ÿ���ھ��뷶Χ�ڣ������ͼ۱ȵ�ǰ�ͼ�С�ļ���վ��ÿ�ζ�ϣ�����Ը��͵��ͼ۽�����ʻ��̰�ģ� 
//���ҵ�һ���ڷ�Χ�ڵļ���վ���ҵ���˵����ǰλ�ü�һ�����;��ܵ�����һ������վ��������һ������վʱ��leftdis=0��������¿�֧�͵�ǰ����͵�ǰ�ͼۣ����������ͷ� 
//��û���ҵ���������Ƿ����С��inf���ͼۣ����ҵ���˵����Ҫ�ڵ�ǰλ�õļ���վ�����ͣ�Ȼ�󵽴���һ������վ��������һ������վʱ��leftdis>0���¿�֧�͵�ǰ����͵�ǰ�ͼۣ����������ͷ� 
//����û���ҵ���˵�������ڶ�Ӧ�ļ���վ�������ܹ��������Զ���룬��ֱ�ӽ����յľ������ 
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
	double now_price,next_price;//��ǰ�ͼۺ���һվ���ͼ� 
	double next_pos;//��ǰλ�ã���һվλ�� 
	double cost=0.0;//�ܵĻ��� 
	double min_price=150;
	if(s[0].dis!=0)//�����������ʼλ��û�м���վ��ֱ�ӽ����������� 
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
		bool find_sta=false;//�Ƿ��ҵ�������˵ļ���վ 
		bool sta=false;//�Ƿ���ڼ���վ 
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
			//û�ҵ��Ļ���������û�м���վ�����߼۸񶼱ȵ�ǰ�ļ���վ�� 
		}
		if(flag==0&&minprice!=inf)//�ҵ��۸�ϴ�ļ���վ 
		{
			cost+=(cap-leftdis/avg)*now_price;//??????
			//leftdis=avg*cap-(s[i].dis-now_dis);?????
			leftdis=avg*cap-(minpricedis-now_dis);////??????
			now_price=minprice;
			now_dis=minpricedis;
		}
		if(flag==0&&minprice==inf)//û���ҵ�����վ 
		{
			now_dis+=cap*avg; 
			printf("The maximum travel distance = %.2lf",now_dis); 
			return 0;
		}
	}
	printf("%.2lf",cost);
	return 0;
}
