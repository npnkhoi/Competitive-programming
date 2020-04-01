#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a[N], ft[N];
pair<int, int> b[N];
void update(int idx, int v) {
    for (int i = idx; i <= n; i += i & (-i)) ft[i] += v;
}
int get(int idx) {
    int res = 0;
    for (int i = idx; i; i -= i & -i) res += ft[i];
    return res;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = make_pair(a[i], i);
        update(i, 1);
    }
    sort(b+1, b+n+1);
    int p = 1;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        while (p <= n && b[p].first < i) {
            update(b[p].second, -1);
            p ++;
        }
        res += max(0, get(min(n, a[i])) - get(i));
    }
    printf("%lld", res);
}
