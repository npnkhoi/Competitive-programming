#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int N = 1e4 + 5;
int n, a[N], f[N], res;
set<int> data;
int main() {
    for (long long i = 1, s = 1; s <= 1e8 + 2; i++, s+= i)
        data.insert(s);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (data.find(a[i]) == data.end()) f[i] = 0;
        else if (a[i] >= a[i-1]) f[i] = f[i-1] + 1;
        else f[i] = 1;
        res = max(res, f[i]);
    }
    cout << res;
}
