#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <utility>
using namespace std;

const int N = 3010;
int main() {
    freopen("virus.inp", "r", stdin);
    freopen("virus.ans", "w", stdout);
    int q; scanf("%d", &q);
    char str[N];
    scanf("%s", &str); int n = strlen(str);
    while (q--) {
        int k;
        int res = 0;
        scanf("%d", &k);
        for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) if (2*j - i + 1 < n) {
            int cnt = 0;
            for (int t = 0; t <= j-i; t++) cnt += (str[i+t] != str[j+1+t]);
            if (cnt <= k) res = max(res, j-i+1);
        }
        printf("%d\n", res);
    }
}
