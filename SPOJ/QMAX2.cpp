#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
struct TNode {
    ll val, lazy;
};
const int N = 5e4 + 5;
const ll oo = 1e18;
TNode IT[8*N];

void lazyDown(int p) {
    IT[p].val += IT[p].lazy;
    IT[2*p].lazy += IT[p].lazy;
    IT[2*p+1].lazy += IT[p].lazy;
    IT[p].lazy = 0;
}
void update(int p, int l, int r, int L, int R, ll x) {
    lazyDown(p);
    if (l > r || L > R || l > R || L > r) return;
    //printf("update %d %d %d %d %d %d\n", p, l, r, L, R, x);
    if (L <= l && r <= R) {
        IT[p].lazy += x;
        lazyDown(p);
        return;
    }
    lazyDown(p);
    int mid = (l+r) / 2;
    update(2*p, l, mid, L, R, x);
    update(2*p+1, mid+1, r, L, R, x);
    IT[p].val = max(IT[2*p].val, IT[2*p+1].val);
}
ll getMax(int p, int l, int r, int L, int R) {
    if (l > r || L > R || l > R || L > r) return -oo;
    lazyDown(p);
    if (L <= l && r <= R) return IT[p].val;
    else {
        int mid = (l+r) /2;
        ll x = getMax(2*p, l, mid, L, R);
        ll y = getMax(2*p+1, mid+1, r, L, R);
        return max(x, y);
    }
}
void show(int p, int l, int r) {
    printf("%d %d %d: %lld %lld\n", p, l, r, IT[p].val, IT[p].lazy);
    if (l < r) {
        int mid = (l+r) / 2;
        show(2*p, l, mid);
        show(2*p+1, mid+1, r);
    }
}
int main() {
    //freopen("QMAX2.inp", "r", stdin);
    //freopen("QMAX2.out", "w", stdout);
    int n, q;
    scanf("%d%d", &n, &q);
    for (int z = 1; z <= q; z++) {
        //for (int i = 1; i <= n; i++) cerr << getMax(1, 1, n, i, i) << " "; cerr << "\n";
        int que, x, y;
        ll val;
        scanf("%d", &que);
        if (que == 0) {
            scanf("%d%d%lld", &x, &y, &val);
            update(1, 1, n, x, y, val);
            //show(1, 1, n);
            //cerr << endl;
        } else {
            scanf("%d%d", &x, &y);
            printf("%lld\n", getMax(1, 1, n, x, y));
        }
    }
}
