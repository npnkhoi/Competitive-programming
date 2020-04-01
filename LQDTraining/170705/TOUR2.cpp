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

    while (m --) scanf("%d %d %f", &e[i].u, &e[i].v, &e[i].c);

    float lo = 0;
    float hi = 1e9 + 1;
    while (lo < hi) {
        float mi = (lo + hi) / 2;
        if (nonNeg(mi)) lo = mi;
        else hi = mi - eps;
    }
}
