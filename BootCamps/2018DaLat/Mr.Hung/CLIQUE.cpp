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

//ifstream inp(".inp");
//ofstream out(".out");
const int N = 205;
int n, m, res, maxRes;
int deg[N];
vector<int> cur;
bool a[N][N], sign[N], stop = 0;
double Time;

bool ok(int u) {
    if (sign[u] == 1) return 0;
    REP(j, cur.size()) {
        int v = cur[j];
        if (a[u][v] == 0) return 0;
    }
    return 1;
}
void backTrack(int u) {
    if (res == maxRes) return;
    if ((clock() - Time)/CLOCKS_PER_SEC >= 0.85) {
        printf("%d\n", res);
        exit(0);
    }
    res = max(res, u-1);
    FOR(i, 1, n) if (deg[i] >= u-1 && ok(i)) {
        sign[i] = 1;
        cur.push_back(i);
        backTrack(u+1);
        sign[i] = 0;
        cur.pop_back();
    }
}
int main() {
    Time = clock();
    freopen("CLIQUE.inp", "r", stdin);
    freopen("CLIQUE.out", "w", stdout);
    scanf("%d %d", &n, &m);
    REP(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u][v] = a[v][u] = 1;
        ++ deg[u]; ++ deg[v];
    }
    for (int i = 1; i*(i-1)/2 <= m; ++i) maxRes = i;
    //cerr << maxRes << "\n";

    backTrack(1);
    printf("%d\n", res);
    return 0;
}
/** Happy Coding :D */
