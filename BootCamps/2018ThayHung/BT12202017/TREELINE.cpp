#include <bits/stdc++.h>
using namespace std;
#define task "treeline"
const int N = 1e5 + 5;
const int maxPF = 1e6 + 2;
const long long md = 1e9;
int n, a[N], minPF[maxPF + 2], cnt[2*N];
void sieve() {
    for (int i = 2; i <= maxPF; i++)
    if (minPF[i] == 0) {
        minPF[i] = i;
        for (long long j = 1LL * i * i; j <= maxPF; j += 1LL * i)
        if (minPF[j] == 0) minPF[j] = i;
    }
}
void update(int x, int val)  {
    while (x > 1) {
        cnt[minPF[x]] += val;
        x /= minPF[x];
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    sieve();
    //for (int i = 90000; i <= 90020; i++) cout << minPF[i] << endl;
    scanf("%d %d", &n, &a[0]);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int pos;
    for (pos = n; pos >= 1; pos --) if (a[pos-1] > a[pos]) break;
    printf("%d\n", n - pos + 2);
    n++;
    for (int i = 2; i <= n; i++) {
        update(i, -1);
        update(n+i, +1);
    }
    long long res = 1LL;
    for (int i = 1; i <= 2*n; i++)
        while (cnt[i] > 0) {
            res = res * (1LL * i) % md;
            cnt[i] --;
        }
    cout << res;
}
