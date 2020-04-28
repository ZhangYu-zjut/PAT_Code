#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//思路，读取字符串放入字符串数组中，然后按照间隔进行抽奖，判定该字符串是否已经被抽过，若没有被抽过，则输出。
//若抽过了，则顺延后一位，再进行判定，直到后一位没有被抽过，进行输出。 
//PAT1069 微博转发抽奖 （20 分） AC!!!
string win[1010];
int main(int argc, char** argv) {
	//freopen("test.txt","r",stdin);
	int i,j,m,n;
	char ch;
    string s;
    cin >> s >> n;
    for (int cnt = 1; cnt < n; cnt++) {
        string t;
        for (int i = 0; i < s.length(); i = j) {
            for (j = i; j < s.length() && s[j] == s[i]; j++);
            t += to_string((s[i] - '0') * 10 + j - i);
        }
        s = t;
    }
    cout << s;

	return 0;
}
