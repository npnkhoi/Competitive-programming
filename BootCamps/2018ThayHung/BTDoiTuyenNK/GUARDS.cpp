#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task "guards"

const int N = 1e5 + 5;
int n, m, k, res, A, B, ft[N];
pair<ii, int> a[N];
map<int, int> id;
vi data, anslist;
vector<ii> tmp;
priority_queue<ii> heap;
int get(int i) {
    //cerr << "get "<< i << "\n";
    int res = 0;
    for (; i; i -= (i & -i)) {
        //cerr << i << "\n";
        res += ft[i];
    }
    return res;
}
void update(int i, int val) {
    //cerr << "update " << i << " " << val << "\n";
    for (; i <= m; i += (i & -i)) {
        // cerr << i << "\n";
        ft[i] += val;
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d%d%d", &n, &k, &A, &B);
    data.pb(A);
    data.pb(B);
    FOR(i, 1, n) {
        scanf("%d%d", &a[i].fi.fi, &a[i].fi.se);
        data.pb(a[i].fi.fi);
        data.pb(a[i].fi.se);
        a[i].se = i;
    }
    // roi rac
    sort(data.begin(), data.end());
    REP(i, data.size()) if (i == 0 || data[i] != data[i-1])
        id[data[i]] = ++m;
    A = id[A]; B = id[B];
    FOR(i, 1, n) {
        a[i].fi.fi = id[a[i].fi.fi];
        a[i].fi.se = id[a[i].fi.se];
    }
    sort(a + 1, a + n + 1);
    //FOR(i, 1, n) cerr << a[i].fi.fi << " " << a[i].fi.se << "\n";
    //cerr << "ok\n";

    int p = 1;
    FOR(i, A, B) if (get(i) < k) {
        int delta = k - get(i);
        //cerr << i << " " << delta << " " << p <<  "\n";
        res += delta;
        for (; a[p].fi.fi <= i && p <= n; p++) {
            heap.push(mp(a[p].fi.se, a[p].se));
        }
        update(i, delta);
        while (delta --) {
            while (!heap.empty() && heap.top().fi < i) heap.pop();
            if (heap.empty()) {
                printf("-1");
                exit(0);
            }
            update(heap.top().fi + 1, -1);
            anslist.push_back(heap.top().se);
            heap.pop();
        }
        //FOR(j, A, B) cerr << get(j) << " "; cerr << "\n";
    }
    printf("%d\n", res);
    REP(i, anslist.size()) printf("%d ", anslist[i]);
}
/** Happy Coding :D */
