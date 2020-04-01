#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <bitset>
#include <complex>
#include <utility>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i,b,a) for (int i = b; i >= a; --i)

#define all(v) v.begin(), v.end()
#define debug(a) cerr << #a << " = " << a << '\n'

#define task "CONNECT"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

struct Edge {
    int u, v;
    ll c;
    Edge() {}
    Edge(int a, int b, ll c): u(a), v(b), c(c) {}
};

const int N = 1e5 + 5, P = 3e5 + 5;

int n, m, p, q;
ll md, res;
vector<Edge> e;
int lab[N];

ll mul(ll a, ll b) {
    if (b == 0) return 0;
    ll res = mul(a, b/2);
    res = (res + res) % md;
    if (b % 2) res = (res + a) % md;
    return res;
}

int root(int u) {
    if (lab[u] < 0) return u;
    else return lab[u] = root(lab[u]);
}

void merge(int u, int v) {
    u = root(u);
    v = root(v);
    if (lab[u] > lab[v]) swap(u, v);
    lab[u] -= (lab[u] == lab[v]);
    lab[v] = u;
}

int id(int x, int y) {
    return (x - 1) * m + y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    cin >> n >> m >> p >> q >> md;
    FOR(i, 1, p) {
        int u, v, c;
        cin >> u >> v >> c;
        res = (res + mul(c, n)) % md;
        FOR(i, 1, n) {
            e.push_back(Edge(id(i, u), id(i, v), c));
        }
    }
    FOR(i, 1, q) {
        int u, v, c;
        cin >> u >> v >> c;
        res = (res + mul(c, m)) % md;
        FOR(i, 1, m) {
            e.push_back(Edge(id(u, i), id(v, i), c));
        }
    }
    //cerr << res << '\n';
    sort(all(e), [](Edge a, Edge b) {
        return a.c < b.c;
    });
    memset(lab, -1, sizeof lab);
    REP(i, e.size()) {
        int u = e[i].u, v = e[i].v;
        if (root(u) != root(v)) {
            //cerr << u << ' ' << v << ' ' << e[i].c << '\n';
            merge(u, v);
            res = (res - e[i].c) % md;
        }
    }
    if (res < 0) res += md;
    cout << res;
}
