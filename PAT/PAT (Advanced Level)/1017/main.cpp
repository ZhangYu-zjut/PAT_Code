#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//可能会有一些特殊情况：窗口数量》排队人数；有部分顾客没有被服务到；排队人数为0等等 
struct person
{
	int arrive;
	int start;
	int leave;
	int serve_time;
}P[100004];
double ans=0.0;
int wait_time=0;
int open_time=8*3600;
int close_time=17*3600;
vector<person>wait_line;
vector<person>serve_line;
bool cmp1(person a,person b)//等待队列 
{
	return a.arrive>b.arrive;
}
bool cmp2(person a,person b)//服务队列 
{
	return a.leave>b.leave;
}
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	int n,k,i,j;
	int invalid=0;
	int hh,mm,ss,during;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&during);
		if(during>60)during=60;
		P[i].arrive=hh*3600+mm*60+ss;
		P[i].serve_time=during*60;
		if(P[i].arrive<=close_time)
		{
			wait_line.push_back(P[i]);
		}
		else
		{
			invalid++;
		}
	}
	if(wait_line.size()==0||k>=wait_line.size())
	{
		printf("0.0");
		return 0; 
	} 
	sort(wait_line.begin(),wait_line.end(),cmp1);//sort
	for(i=0;i<k;i++)
	{
		person p_in=wait_line[wait_line.size()-1];
		if(p_in.arrive<open_time)
		{
			p_in.start=open_time;
			p_in.leave=p_in.start+p_in.serve_time;
		}
		else
		{
			p_in.start=p_in.arrive;
			p_in.leave=p_in.start+p_in.serve_time;
		}
		wait_time+=p_in.start-p_in.arrive;
		serve_line.push_back(p_in);//sort
		wait_line.pop_back();
		//有可能这里就全部出队了
		if(wait_line.size()==0)
		{
			double temp=1.0*wait_time/60.0;
			ans = temp/(n-invalid);
			printf("%.1f",ans);
			return 0;
		} 
	}
	while(wait_line.size()>0)
	{
		sort(serve_line.begin(),serve_line.end(),cmp2);
		person p_in=wait_line[wait_line.size()-1];
		person p_out=serve_line[serve_line.size()-1]; 
		if(p_out.leave>close_time)
		{
			p_in.start=17*3600;
		}
		else
		{
			p_in.start=p_out.leave;
		}

		p_in.leave=p_in.serve_time+p_in.start;
		wait_time+=p_in.start-p_in.arrive;
		serve_line.pop_back();
		wait_line.pop_back(); 
		serve_line.push_back(p_in);
	}
	//printf("%d",wait_time);
	double temp=1.0*wait_time/60;
	ans = temp/(n-invalid);
	printf("%.1f",ans);
	return 0;
}
