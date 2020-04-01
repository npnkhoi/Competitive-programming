using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
const int N = 1e5 + 5;
int root[N], Rank[N];
int n;
vector<ii> v;
int getRoot(int u) {
    if (root[u] == u) return u;
    else return root[u] = getRoot(root[u]);
}
void join(int u, int v) {
    u = getRoot(u), v = getRoot(v);
    if (u == v) return;
    if (Rank[u] > Rank[v]) root[v] = u;
    else {
        root[u] = v;
        Rank[v] += (Rank[u] == Rank[v]);
    }
}

int main() {
    freopen("SMS.inp", "r", stdin);
    freopen("SMS.out", "w", stdout);
    scanf("%d", &n);
    int t;
    FOR(i, 1, n) {
        scanf("%d", &t);
        for (int j = 1; j * j <= t; ++j)
        if (t%j == 0) {
            v.push_back(mp(j, i));
            if (j*j != t) v.push_back(mp(t/j, i));
        }
    }
    sort(v.rbegin(), v.rend());
    FOR(i, 1, n) root[i] = i;

    ll res = 0;
    int size = v.size();
    for (int i = 0; i < size; ) {
        int j = i+1;
        for (j = i+1; j < size && v[i].fi == v[j].fi; ++j) {
            if (getRoot(v[i].se) != getRoot(v[j].se)) {
                res += v[i].fi;
                join(v[i].se, v[j].se);
            }
        }
        i = j;
    }
    printf("%lld\n", res);
    return 0;
}
/** Happy Coding ^^ */

