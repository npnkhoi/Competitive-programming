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

const int N = 1005, K = 7;

int n, k;
int a[K][N], pos[K][5*N], f[N], res;
vi v;

bool noCut(int u, int v) {
    u = a[1][u], v = a[1][v];
    FOR(i, 2, k) {
        if (pos[i][u] == 0 || pos[i][v] == 0 || pos[i][u] > pos[i][v]) return false;
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
    cin >> n >> k;
    FOR(i, 1, k) {
        FOR(j, 1, n) {
            cin >> a[i][j];
            v.push_back(a[i][j]);
        }
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    FOR(i, 1, k) {
        FOR(j, 1, n) {
            a[i][j] = upper_bound(all(v), a[i][j]) - v.begin();
            pos[i][a[i][j]] = j;
        }
    }
    FOR(i, 1, n) {
        if (a[1][i] == 0) break;
        f[i] = 1;
        FOR(j, 1, i - 1) {
            if (noCut(j, i)) f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }
    cout << res;
}
