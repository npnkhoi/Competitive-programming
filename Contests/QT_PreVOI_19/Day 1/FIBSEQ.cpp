#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "FIBSEQ"

typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5, md = 1e9 + 7;

int n, q;
int f[N];

struct STNode {
    int l, r, cur, nxt, lazy;
};

struct LazySegmentTree {
    vector<STNode> a;

    void build(int p, int l, int r) {
        a[p].l = l;
        a[p].r = r;
        a[p].cur = a[p].lazy = 0;
        a[p].nxt = r - l + 1;

        if (l < r) {
            int mid = (l + r) / 2;
            build(2 * p, l, mid);
            build(2 * p + 1, mid + 1, r);
        }
    }
    void init (int n) {
        a.resize(8 * n + 1);
        build(1, 1, n);
    }

    void down(int p) {
        if (a[p].lazy == 0) return;
        if (a[p].l < a[p].r) {
            a[2 * p].lazy += a[p].lazy;
            a[2 * p + 1].lazy += a[p].lazy;
        }
        // depend on type of query
        int t = a[p].lazy;
        int cur2 = ((lint)a[p].cur * f[t - 1] % md + (lint)a[p].nxt * f[t] % md) % md;
        int nxt2 = ((lint)a[p].cur * f[t] % md + (lint)a[p].nxt * f[t + 1] % md) % md;
        a[p].cur = cur2;
        a[p].nxt = nxt2;
        a[p].lazy = 0;
    }
    void update(int p, int l, int r, int val) {
        down(p);
        if (a[p].l > r || l > a[p].r) return;
        if (l <= a[p].l && a[p].r <= r) {
            a[p].lazy = val;
            down(p);
            return;
        }
        update(2 * p, l, r, val);
        update(2 * p + 1, l, r, val);
        // depend on type of query
        a[p].cur = (a[2 * p].cur + a[2 * p + 1].cur) % md;
        a[p].nxt = (a[2 * p].nxt + a[2 * p + 1].nxt) % md;
    }
    int get(int p, int l, int r) {
        down(p);
        if (a[p].l > r || l > a[p].r) return 0;
        if (l <= a[p].l && a[p].r <= r) {
            return a[p].cur;
        }
        // depend on type of query
        return (get(2 * p, l, r) + get(2 * p + 1, l, r)) % md;
    }
} ST;  

void Init() {
    cin >> n >> q;
    f[1] = 1;
    FOR(i, 2, q) f[i] = (f[i - 1] + f[i - 2]) % md;
    ST.init(n);
}

void Solve() {
    REP(i, q) {
        char ch;
        int x, y;
        cin >> ch >> x >> y;
        if (ch == 'D') {
            ST.update(1, x, y, 1);
            // FOR(i, 1, n) cerr << ST.a[i].cur << ' '; cerr << '\n';
        } else {
            cout << ST.get(1, x, y) << '\n';
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    Init();
    Solve();
}
