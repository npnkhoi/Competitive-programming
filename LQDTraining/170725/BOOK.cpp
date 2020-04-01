using namespace std;
#include <bits/stdc++.h>
const int N = 1e5 + 10;
int n, a[N];
int main() {
    freopen("BOOK.inp", "r", stdin);
    freopen("BOOK.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    long long s = 0;
    for (int i = 0; i < n; i++) if (i%3 != n%3) s += 1LL*a[i];
    printf("%lld", s);
}
