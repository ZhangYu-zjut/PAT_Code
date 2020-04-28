#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//思路：将10进制转化为13进制，然后找到对应的火星文进行输出 
string huoxing[]={"","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string add[]={"","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
char dec[10]; 
char thirteen[10];
char high[10];
char low[10];
char temp[10];
char target[10];
int main(int argc,char** argv) {
	map<string,int>ma;
	map<string,int>map_add;
	int i,j;
	for(i=1;i<=12;i++)
	{
		ma.insert(pair<string,int>(huoxing[i],i));
		map_add.insert(pair<string,int>(add[i],i));
	}
	map<string,int>::iterator iter1;  
	map<string,int>::iterator iter2;  
    /*iter = ma.find("may");  
    if(iter != ma.end())    
       cout<<"Find, the value is "<<iter->second<<endl;  
    else    
       cout<<"Do not Find"<<endl;  */
    
    int n;
    while(scanf("%d",&n)!=EOF)
    {
    	scanf("%s",temp);
    	int num=0; 
    	int ten=1;
    	if(temp[0]<='9'&&temp[0]>='0')//地球文 
    	{
    		for(i=strlen(temp);i>=0;i--)
    		{
    			num+=(temp[i]-'0')*ten;
    			ten*=10;
    		}
    		int ans=num%13;
    		int k=0;
    		while(1)
    		{
    			target[k]=ans%10;
    			ans/=10;
    			k++;
    			if(ans<1)
    			{
    				break;
    			}
    		}
    		for(j=k-1;j>=0;j--)
    		{
    			if(k==1)
    			{
    				cout<<huoxing[target[j]];
    			}
    			if(k>1)
    			{
    				if(j==k-1)
    				{
    					cout<<huoxing[target[j]]<<" "<<huoxing[target[j-1]]<<endl;
    				}
    				//cout<<huoxing[target[j]]<<" "<<huoxing[target[j]];
    			}
    		}
    	}
    	else//火星文 (可能要多读一个字符串)
    	{
    		scanf("%s%s",high,low);
    		
    	}
	} 



	return 0;
}
