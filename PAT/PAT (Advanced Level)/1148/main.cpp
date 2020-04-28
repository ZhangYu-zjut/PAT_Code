#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//AC!!!
vector<int>ans;
int num[103];
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	int n;
	int i,j,k,temp;
	char ch;
	fill(num,num+103,1);
	while(scanf("%d\n",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%c%d\n",&ch,&temp);

			if(ch=='-')
			{
				num[i]=temp*-1;
			}
			else
			{
				num[i]=temp;
			}
			//printf("%d",num[])
		}
		bool find=false;
		int lie=0;
		int lie_wolf=0;
		for(i=1;i<=n;i++)
		{
			if(find)
			{
				break;
			}
			for(j=i+1;j<=n;j++)
			{
				if(find)
				{
					break;
				}
				lie=0;
				lie_wolf=0;
				for(k=1;k<=n;k++)
				{
					if((k==i||k==j))
					{
						if(num[k]<0)
						{
							if(abs(num[k])!=i&&abs(num[k])!=j)
							{
								lie_wolf++;
								lie++;
							}
						}
						else
						{
							if(num[k]==i||num[k]==j)
							{
								lie_wolf++;
								lie++;
							}
						}
					}
					else
					{
						if(num[k]<0)
						{
							if(abs(num[k])!=i&&abs(num[k])!=j)
							{
								lie++;
							}
						}
						else
						{
							if(num[k]==i||num[k]==j)
							{
								lie++;
							}
						}
					}
						
				}
				if(lie_wolf==1&&lie==2)
				{
					ans.push_back(i);
					ans.push_back(j);
					find=true;
					break;
				}
			}
		}

		if(!find)
		{
			printf("No Solution\n");
		}
		else
		{
			printf("%d %d\n",ans[0],ans[1]);
		}
	}
	return 0;
}
