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

#define task ""

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 4005, K = 805, oo = 1e9 + 7;

int n, k, a[N][N], dp[K][N], opt[K][N];

void getInt(int &x) {
    int c;
    while (1) {
        c = getchar();
        if (isdigit(c)) break;
    }
    x = c - '0';
    while (1) {
        c = getchar();
        if (!isdigit(c)) break;
        x = x * 10 + c - '0';
    }
}

int sum(int x, int y, int u, int v) {
    return a[u][v] - a[x - 1][v] - a[u][y - 1] + a[x - 1][y - 1];
}

int cost(int l, int r) {
    return sum(l, l, r, r) / 2;
}

void calc(int i, int l, int r, int u, int v) {
    //cerr << "calc " << i << ' ' << l << ' ' << r << ' ' << u << ' ' << v << '\n';
    if (l > r) return;
    int mid = (l + r) / 2;
    opt[i][mid] = u;
    FOR(j, u + 1, min(mid, v)) {
        if (dp[i - 1][opt[i][mid] - 1] + cost(opt[i][mid], mid) > dp[i - 1][j - 1] + cost(j, mid)) {
            opt[i][mid] = j;
        }
    }
    dp[i][mid] = dp[i - 1][opt[i][mid] - 1] + cost(opt[i][mid], mid);
    calc(i, l, mid - 1, u, opt[i][mid]);
    calc(i, mid + 1, r, opt[i][mid], v);
}

int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
    getInt(n);
    getInt(k);
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            getInt(a[i][j]);
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    FOR(j, 1, n) dp[0][j] = oo;
    FOR(i, 1, k) {
        calc(i, 1, n, 1, n);
        //FOR(j, 1, n) cerr << i << ' ' << j << ' ' << opt[i][j] << ' ' << dp[i][j] << '\n';
    }
    cout << dp[k][n];
}
