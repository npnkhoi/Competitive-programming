using namespace std;
#include <bits/stdc++.h>
typedef pair<int, int> ii;
typedef pair<int , ii> iii;
#define mp make_pair
#define fi first
#define se second

const int N = 1e3 + 20;
const long long oo = 1e18;
int n, m;
vector<ii> adj[N];
long long d[N][N];
double res;
vector <bool> Free (N, 1);
bool hasTour;
int par[N], sign[N];
void dfs(int u) {
    if (hasTour) return;
    sign[u] = 1;
    //cout << u << endl;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j].first;
        if (sign[v] == 0) par[v] = u, dfs(v);
            else if (sign[v] == 1) hasTour = 1;
    }
    sign[u] = 2;
}
int main() {
    freopen("TOUR.inp", "r", stdin);
    freopen("TOUR.out", "w", stdout);
    scanf("%d %d", &n, &m);

    while (m --) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(make_pair(v, c));
    }
    /** create virtual node */
    int s = 0;
    for (int i = 1; i <= n; i++) adj[s].push_back(ii(i, 0));

    /** check for non-cycle*/
    /*hasTour = 0;
    dfs(s);
    if (!hasTour) {
        cout << "NO TOUR";
        return 0;
    }*/

    /** compute d[k][u] */
    for (int k = 0; k <= n+1; k++)
    for (int u = 0; u <= n; u++) d[k][u] = oo;
    d[0][s] = 0;

    for (int k = 0; k <= n; k++)
    for (int u = 0; u <= n; u++)
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j].first;
        long long w = 1LL * adj[u][j].second;
        d[k+1][v] = min(d[k+1][v], d[k][u] + w);
        }
    /** compute res*/
    res = oo;
    for (int v = 1; v <= n; v++) {
        if (d[n+1][v] == oo) continue;
        double tmp = 0;
        for (int k = 1; k <= n; k++)
        tmp = max(tmp, (d[n+1][v] - d[k][v]) / (double) (n-k+1));
        //cout << tmp << endl;
        res = min(res, tmp);
    }
    //cout << res;
    if (res == oo) cout << "NO TOUR";
    else printf("%.2f", res);
}
