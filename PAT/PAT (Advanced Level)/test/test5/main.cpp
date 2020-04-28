#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
vector<int>v;
vector<int>::iterator it;
int main(int argc, char** argv) {
	
	/*第一种和第二种方式比较好用,string转int时候别忘了参数为s.c_str()*/
	string a="15326";
	int ansa=atoi(a.c_str());
	
	char b[]="595326";
	int ansb=atoi(b); 
	
	string c="987";
	std::string::size_type st;
	int ansc=stoi(c,&st);
	printf("a is %d\n",ansa);
	printf("b is %d\n",ansb);
	printf("c is %d\n",ansc);
	return 0;
}
