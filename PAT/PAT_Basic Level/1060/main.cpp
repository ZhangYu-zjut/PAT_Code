#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1000000];
//���������±�1��ʼ�洢n��Ĺ�����������a�У���n�����ݴӴ�С����i��ʾ���ﳵ����������ô����a[i] > i�����ֵ��Ϊ����
//AC!!!
bool cmp1(int a, int b) {
    return a > b;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1, cmp1);
    int ans = 0, p = 1;
    while(ans <= n && a[p] > p) {
        ans++;
        p++;
    }
    printf("%d", ans);
    return 0;
}
