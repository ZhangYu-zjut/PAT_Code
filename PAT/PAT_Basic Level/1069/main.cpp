#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//˼·����ȡ�ַ��������ַ��������У�Ȼ���ռ�����г齱���ж����ַ����Ƿ��Ѿ����������û�б�������������
//������ˣ���˳�Ӻ�һλ���ٽ����ж���ֱ����һλû�б��������������� 
//PAT1069 ΢��ת���齱 ��20 �֣� AC!!!
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
