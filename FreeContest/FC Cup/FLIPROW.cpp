#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "FLIPROW"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

struct Pack {
    int val, row, type;
    Pack(int a, int b, int c): val(a), row(b), type(c) {}
    bool operator < (const Pack &oth) {
        return val < oth.val;
    }
};

const int N = 1005;

vector<Pack> v;
int n, m, a[N][N], vCheck[N], color[N];
vector<ii> adj[N];
vi ans;

void check(int col) {
    FOR(i, 1, n) vCheck[i - 1] = a[i][col];
    sort(vCheck, vCheck + n);
    REP(i, n - 1) {
        if (vCheck[i] == vCheck[i + 1]) {
            cout << "No";
            exit(0);
        }
    }
}

void process(int col) {
    v.clear();
    FOR(i, 1, n) {
        if (a[i][col] == a[i][m-col+1]) {
            v.push_back(Pack(a[i][col], i, 0));
        } else {
            v.push_back(Pack(a[i][col], i, -1));
            v.push_back(Pack(a[i][m-col+1], i, 1));
        }
    }
    sort(all(v));
    REP(i, v.size() - 1) {
        if (v[i].val != v[i + 1].val) continue;
        if (v[i].type == 0 || v[i+1].type == 0) {
            cout << "No";
            exit(0);
        }
        int c = (v[i].type == v[i + 1].type);
        //cerr << v[i].row << ' ' << v[i + 1].row << ' ' << c << '\n';
        adj[v[i].row].push_back(mp(v[i + 1].row, c));
        adj[v[i + 1].row].push_back(mp(v[i].row, c));
    }
}

void dfs(int u) {
    //cerr << "dfs " << u << '\n';
    if (color[u] == 1) {
        ans.push_back(u);
        FOR(j, 1, m/2) swap(a[u][j], a[u][m-j+1]);
    }
    REP(i, adj[u].size()) {
        ii v = adj[u][i];
        if (color[v.fi] == -1) {
            color[v.fi] = color[u] ^ v.se;
            dfs(v.fi);
        } else {
            if (color[v.fi] != color[u] ^ v.se) {
                cout << "No";
                exit(0);
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
    FOR(j, 1, m/2) {
        process(j);
    }
    memset(color, -1, sizeof color);
    FOR(i, 1, n) if (color[i] == -1) {
        color[i] = 0;
        dfs(i);
    }
    FOR(j, 1, m) check(j);
    cout << "Yes\n" << ans.size() << '\n';
    REP(i, ans.size()) cout << ans[i] << ' ';
}
