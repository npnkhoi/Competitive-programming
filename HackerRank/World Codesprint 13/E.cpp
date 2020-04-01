#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "E"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;
const int sh = 1;
int lab[N], Rank[N], siz[N];
long long ft[N];
int n, q;
map<int, int> data;
map<int, int>::iterator it;

long long get(int idx) {
    ll res = 0;
    for (int i = idx + sh; i; i -= i & -i) res += ft[i];
    return res;
}
long long get(int l, int r) {
    if (l > r) return 0LL;
    else if (l == 0) return get(r);
    else return get(r) - get(l-1);
}
void update(int idx, long long val) {
    for (int i = idx + sh; i <= n + sh; i += i & -i) ft[i] += val;
}
void del(int x) {
    for (it = data.begin(); it != data.end(); it ++)
        update(abs(x - (it->fi)), - it->se + (it->fi == x));
    if (data[x] == 1) data.erase(x);
    else data[x] --;
}
void add(int x) {
    for (it = data.begin(); it != data.end(); it ++)
        update(abs(x - it->fi), it -> se);
    data[x] ++;
}

int root(int u) {
    if (lab[u] == -1) return u;
    else return lab[u] = root(lab[u]);
}
void join(int u, int v) {
    u = root(u), v = root(v);
    if (u != v) {
        del(siz[u]); del(siz[v]); add(siz[u] + siz[v]);
        if (Rank[u] > Rank[v]) {
            lab[v] = u;
            siz[u] += siz[v];
        } else {
            lab[u] = v;
            siz[v] += siz[u];
            Rank[v] += (Rank[u] == Rank[v]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    //scanf("%d%d", &n, &q);
    cin >> n >> q;
    data[1] = n;
    update(0, (ll) n * (n-1) / 2);
    memset(lab, -1, sizeof lab);
    FOR(i, 1, n) siz[i] = 1;

    while (q --) {
        int ask;
        //scanf("%d", &ask);
        cin >> ask;
        if (ask == 1) {
            int u, v;
            //scanf("%d%d", &u, &v);
            cin >> u >> v;
            join(u, v);
        } else {
            int c;
            //scanf("%d", &c);
            cin >> c;
            //printf("%lld\n", get(c, n));
            cout << get(c, n) << '\n';
        }
    }
}
