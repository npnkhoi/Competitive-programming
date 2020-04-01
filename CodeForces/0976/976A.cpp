#include <bits/stdc++.h>
using namespace std;
int n, cnt[2];
char ch;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &ch);
        cnt[ch - '0'] ++;
    }
    if (cnt[1] > 0) printf("1");
    for (int i = 1; i <= cnt[0]; i++) printf("0");
}
