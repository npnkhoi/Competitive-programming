#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 3e4 + 5;
const int Q = 2e5 + 5;
int n, q;
vector<pair<int, int> > a;
struct TQuery {
    int id, l, r, k;
};
vector<TQuery> qr;
bool cmp(TQuery a, TQuery b) {
    return a.k < b.k;
}
int IT[4*N], res[Q];

void update(int idx) {
    int p = 1, l = 1, r = n;
    while (1) {
        IT[p] ++;
        if (l == r) break;
        int mid = (l+r) / 2;
        if (idx <= mid) {
            r = mid; p = 2*p;
        }
        else {
            l = mid + 1;
            p = 2*p + 1;
        }
    }
}
int getSum(int p, int l, int r, int L, int R) {
    if (l > r || L > R || l > R || L > r) return 0;
    if (L <= l && r <= R) return IT[p];
    else {
        int mid = (l+r) / 2;
        return getSum(2*p, l, mid, L, R) + getSum(2*p+1, mid+1, r, L, R);
    }
}

int main() {
    //freopen("0.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n+1);
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        a[i] = make_pair(val, i);
    }
    sort(a.begin()+1, a.end());

    cin >> q;
    qr.resize(q+1);
    for (int z = 1; z <= q; z++) {
        qr[z].id = z;
        cin >> qr[z].l >> qr[z].r >> qr[z].k;
    }
    sort(qr.begin()+1, qr.end(), cmp);
    int cur = 1;
    for (int i = 1; i <= q; i++) {
        while (cur <= n && a[cur].fi <= qr[i].k) {
            update(a[cur].se);
            cur ++;
        }
        res[qr[i].id] = (qr[i].r - qr[i].l + 1) - getSum(1, 1, n, qr[i].l, qr[i].r);
    }
    for (int i = 1; i <= q; i++) cout << res[i] << "\n";
}
