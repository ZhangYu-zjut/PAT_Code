#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//注意给出的所有节点并不都是有效的
//要考虑没有有效节点的情况！！
//AC!!! 
struct node {
	int addr;
	int data;
	int next;
	int flag;
} N[100005];
bool cmp(node a,node b) {
	if(a.flag==0||b.flag==0) {
		return a.flag>b.flag;
	} else return a.data<b.data;
}
int main(int argc, char** argv) {
	int i,j,k;
	for(i=0; i<100005; i++) {
		N[i].flag=false;
	}
	int n,head;
	scanf("%d%d",&n,&head);
	int a,b,c;
	for(i=0; i<n; i++) {
		scanf("%d%d%d",&a,&b,&c);
		N[a].addr=a;
		N[a].data=b;
		N[a].next=c;
	}
	int s=head;
	int count=0;
	while(s!=-1) {
		count++;
		N[s].flag=1;
		s=N[s].next;
	}
	if(count==0) {
		printf("0 -1");
		return 0;
	}
	sort(N,N+100005,cmp);
	printf("%d %d\n",count,N[0].addr);
	for(i=0; i<count; i++) {
		if(i==count-1)printf("%05d %d -1\n",N[i].addr,N[i].data);
		else printf("%05d %d %05d\n",N[i].addr,N[i].data,N[i+1].addr);
	}
	return 0;
}
