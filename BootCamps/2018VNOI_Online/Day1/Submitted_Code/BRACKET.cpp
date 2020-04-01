#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <cstdlib>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define REP(i,n) for (int i = 0; i < n; ++i)
#define task "bracket"
typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e6 + 5;
const long long md = 1e9 + 7;
vector<int> adj[N];
long long f[N];
ii a[N];
int m, n, b[N];
stack<int> st;
long long Pow(int a, int n) {
    if (n == 0) return 1;
    else {
        long long tmp = Pow(a, n/2);
        if (n&1) return tmp * tmp % md * a % md;
        return tmp * tmp % md;
    }
}
long long Cat(int n) {
    long long res = 1;
    FOR(i, n+2, 2*n) res = res * i % md;
    FOR(i, 2, n) res = res * Pow(i, md - 2) % md;
    return res;
}
void dfs(int u) {
    //printf("dfs %d\n", u);
    f[u] = 1;
    int siz = a[u].se - a[u].fi - 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        dfs(v);
        siz -= (a[v].se - a[v].fi + 1);
        f[u] = f[u] * f[v] % md;
    }
    if (siz%2) {
        printf("0");
        exit(0);
    }
    //printf("siz %d: %d\n", u, siz);
    if (siz > 2) f[u] = f[u] * Cat(siz/2) % md;
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    if (n%2) {
        printf("0");
        exit(0);
    }
    //cerr << "ok\n";
    a[0] = mp(0, n+1);
    FOR(i, 1, m) {
        //printf("%d\n", i);
        scanf("%d%d", &a[i].fi, &a[i].se);
        if (b[a[i].fi] != -b[a[i].se]) {
            printf("0");
            exit(0);
        } else {
            b[a[i].fi] = i;
            b[a[i].se] = -i;
        }
    }
    //FOR(i, 1, n) cerr << b[i] << " " ; cerr << "\n";
    FOR(i, 1, n) if (b[i] > 0) {
        if (st.empty()) adj[0].pb(b[i]);
        else adj[st.top()].pb(b[i]);
        st.push(b[i]);
    } else if (b[i] < 0) {
        if (st.empty() || st.top() != -b[i]) {
            printf("0");
            exit(0);
        } else st.pop();
    }
    /*FOR(i, 1, m) {
        printf("adj %d\n", i);
        REP(j, adj[i].size()) cerr <<adj[i][j] << " ";
    }*/
    //cerr << "ok\n";
    if (!st.empty()) {
        printf("0");
        exit(0);
    }
    //cerr << "ok\n";
    dfs(0);
    printf("%lld", f[0]);
}
