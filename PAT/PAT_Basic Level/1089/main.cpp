#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//有一个测试点没过,下列程序可以完全通过 
/*
#include<iostream>
#include<vector>
using namespace std;
int judge(vector<int> key, vector<int> wolf, int length) {
	int error_count = 0;     //假话数
	int wolf_count = 0;      //说假话的狼人数
	for (int i = 0; i < length; i++) {
		if (wolf[abs(key[i]) - 1] * key[i] < 0) {   //异号为负，说明说谎
			if (wolf[i] == -1)
				wolf_count++;
			error_count++;
		}
	}
	if (error_count == 2 && wolf_count == 1)   //2个人说谎，且其中有一个是狼人
		return 1;
	return 0;
}
int main() {
	vector<int> key;
	int n, t;
	cin >> n;
	key.resize(n);
	for (int i = 0; i < n; i++)
		cin >> key[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			vector<int> wolf(n, 1);
			wolf[i] = wolf[j] = -1;
			if (judge(key, wolf, n)) {
				cout << i + 1 << " " << j + 1 << endl;  //找到狼人，输出，结束程序
				return 0;
			}
		}
	}
	cout << "No Solution";
	return 0;
}

*/ 
int wolf[200];
bool judge[200]; 
char ch[200][5];
int main(int argc, char** argv) {
	freopen("test.txt","r",stdin);
	int n,i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%s",ch[i]);
		}
		for(i=1;i<=200;i++)
		{
			judge[i]=true;
			wolf[i]=1;
		}
		
		bool find=false;
		for(i=1;i<=n;i++)
		{
			wolf[i]=-1;
			for(j=i+1;j<=n;j++)
			{
				int lie=0;
				int wolf_lie=0;
				wolf[j]=-1;
				if(find==false)
				{
					for(k=1;k<=n;k++)
					{
						if(ch[k][0]=='-')
						{
							int t=1;
							int num=0;
							int c=1;
							while(ch[k][t]!='\0')
							{
								num+=(ch[k][t]-'0')*c;
								c*=10;
								t++;
							}
							if(wolf[num]>0)
							{
								lie++;
								if(wolf[k]==-1)
								{
									wolf_lie++;
								}
							}
						}
						if(ch[k][0]=='+')
						{
							int t=1;
							int num=0;
							int c=1;
							while(ch[k][t]!='\0')
							{
								num+=(ch[k][t]-'0')*c;
								c*=10;
								t++;
							}
							if(wolf[num]<0)
							{
								lie++;
								if(wolf[k]==-1)
								{
									wolf_lie++;
								}
							}
							
						}
					}
				}		
				if(lie==2&&wolf_lie==1)
				{
					printf("%d %d\n",i,j);
					find=true;
					break;
				}
				
				wolf[j]=1;
			}
			wolf[i]=1;
		}
		if(find==false)
		{
			printf("No Solution");
		}

	} 
	return 0;
}
