using namespace std;

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int N = 1e5 + 10;
vector<ii> adj[N];
int par[N], p[N], sign[N], d[N], n, q;

void make_directed(int u) {
    sign[u] = 1;
    FOR(j, 0, adj[u].size() - 1) {
        int v = adj[u][j].fi;
        if (sign[v] == 0 && v != par[u])
            par[v] = u, make_directed(v);
    }
}

void dfs11(int u, int f, int c) {
    //printf("11 %d %d %d\n", u, f, c);
    if (u == f) return;

    FOR(j, 0, adj[u].size() - 1) {
        int v = adj[u][j].fi;
        if (d[v] == -1) {
            //cout << v << "\n";
            //cout << u << " " << j << "\n";
            //cout << adj[u][j].se << "\n";
            d[v] = d[u] + (adj[u][j].se <= c);
            //cout << "ok\n";
            dfs11(v, f, c);
        }
    }
}

void query11() {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    memset(d, -1, sizeof d);
    //memset(p, -1, sizeof p);

    d[u] = 0;
    dfs11(u, v, c);

    printf("%d\n", d[v]);
}

int dfs12(int u, int c) {
    //printf("12: %d %d\n", u, c);
    sign[u] = 1;
    int s = 0;
    FOR(j, 0, adj[u].size()-1) {
        int v = adj[u][j].fi;
        if (sign[v] == 0 && v != par[u])
            s += dfs12(v, c) + (adj[u][j].se <= c);
    }
    return s;
}

void query12() {
    int u, c;
    scanf("%d %d", &u, &c);
    memset(sign, 0, sizeof sign);
    printf("%d\n", dfs12(u, c));
}

void sub1() {
    while (q--) {
        char cmd;
        scanf(" %c", &cmd);
        if (cmd == 'P') query11();
        else query12();
    }
}

void sub2() {

}
int main() {
    freopen("TREE.inp","r",stdin);
    freopen("TREE.out","w",stdout);
    scanf("%d %d", &n, &q);
    FOR(i, 1, n-1) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(mp(v, c));
        adj[v].push_back(mp(u, c));

    }
    memset(sign, 0, sizeof sign);
    memset(par, -1, sizeof par);
    make_directed(1);
    //FOR(i, 1, n) cout << par[i] << " "; cout << endl;

    if (n <= 2001) sub1();
    return 0;
}
/**/
