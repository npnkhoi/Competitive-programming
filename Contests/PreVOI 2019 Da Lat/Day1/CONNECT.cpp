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
    int u, v, type;
    ll c;
    Edge() {}
};

const int N = 1e5 + 5, P = 3e5 + 5;

int n, m, p, q;
ll md, res;
Edge e[2 * P];
int labRow[N], labCol[N];

ll mul(ll a, ll b) {
    if (b == 0) return 0;
    ll res = mul(a, b/2);
    res = (res + res) % md;
    if (b % 2) res = (res + a) % md;
    return res;
}

bool cmp(Edge a, Edge b) {
    return a.c < b.c;
}

int root(int lab[], int u) {
    if (lab[u] < 0) return u;
    else return lab[u] = root(lab, lab[u]);
}

void merge(int lab[], int u, int v) {
    u = root(lab, u);
    v = root(lab, v);
    if (lab[u] > lab[v]) swap(u, v);
    lab[u] -= (lab[u] == lab[v]);
    lab[v] = u;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> m >> p >> q >> md;
    FOR(i, 1, p) {
        cin >> e[i].u >> e[i].v >> e[i].c;
        res = (res + mul(e[i].c, n)) % md;
        e[i].type = 0;
    }
    FOR(i, p + 1, p + q) {
        cin >> e[i].u >> e[i].v >> e[i].c;
        res = (res + mul(e[i].c, m)) % md;
        e[i].type = 1;
    }
    //debug(res);
    sort(e + 1, e + p + q + 1, cmp);
    memset(labRow, -1, sizeof labRow);
    memset(labCol, -1, sizeof labCol);
    int cntRow = n, cntCol = m;
    FOR(i, 1, p + q) {
        int u = e[i].u, v = e[i].v;
        if (e[i].type == 0) {
            if (root(labCol, u) == root(labCol, v)) continue;
            res = (res - mul(e[i].c, cntRow)) % md;
            cntCol --;
            merge(labCol, u, v);
            //cerr << u << ' ' << v << ' ' << e[i].c << '\n';
        } else {
            if (root(labRow, u) == root(labRow, v)) continue;
            res = (res - mul(e[i].c, cntCol)) % md;
            cntRow --;
            //cerr << u << ' ' << v << ' ' << e[i].c << '\n';
            merge(labRow, u, v);
        }
    }
    if (res < 0) res += md;
    cout << res;
}
