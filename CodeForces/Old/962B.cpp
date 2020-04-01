#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int v[N];
int a, b, n;
bool cmp(int a, int b) {
    return a % 2 > b % 2;
}
int main() {
    scanf("%d%d%d", &n, &a, &b);
    if (a < b) swap(a, b);
    int m = 0, tmp = 0;
    for (int i = 1; i <= n; i++) {
        char ch;
        scanf(" %c", &ch);
        if (ch == '.') tmp ++;
        else {
            if (tmp > 0) {
                v[++m] = tmp;
                tmp = 0;
            }
        }
    }
    if (tmp > 0) v[++m] = tmp;
    sort(v+1, v+m+1, cmp);

    int res = 0;
    for (int i = 1; i <= m; i++) {
        int x = min(v[i] / 2, b);
        v[i] -= 2 * x;
        a -= x;
        b -= x;
        res += 2 * x;
    }
    if (b > 0) a += b;
    for (int i = 1; i <= m && a > 0; i++) {
        int x = min((v[i] + 1) / 2, a);
        res += x;
        a -= x;
    }
    printf("%d", res);
}
