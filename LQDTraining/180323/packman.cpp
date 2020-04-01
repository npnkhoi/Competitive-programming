#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, p, a[N], gra[N], pac[N];

bool ok(int x) {
    int ptr = 1;
    for (int i = 1; i <= m && ptr <= p; i++) {
        if (gra[ptr] < pac[i]) {
            int d = pac[i] - gra[ptr];
            if (d > x) return false;
            int tmp = pac[i] + max(x - 2*d, (x-d)/2);
            while (ptr <= p && gra[ptr] <= tmp) ptr ++;
        } else {
            int tmp = pac[i] + x;
            while (ptr <= p && gra[ptr] <= tmp) ptr ++;
        }
    }
    return ptr > p;
}
int main() {
    freopen("packman.inp", "r", stdin);
    freopen("packman.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &a[i]);
        if (a[i] == 'P') pac[++m] = i;
        if (a[i] == '*') gra[++p] = i;
    }
    //for (int i = 1; i <= m; i++) cerr << pac[i] << " ";  cerr << "\n";
    //for (int i = 1; i <= p; i++) cerr << gra[i] << " ";  cerr << "\n";
    int l = 0, r = 2*n, res = r;
    while (l <= r) {
        int mid = (l+r) / 2;
        if (ok(mid)) {
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    printf("%d", res);
    //cerr << ok(3);
}
