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

const string HARD = "hard";
const int N = 1e5 + 5;
const ll oo = 1e18 + 7;

int n, a[N];
ll f[N][6];
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
    cin >> n >> s;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 0, n) FOR(j, 0, 4) f[i][j] = oo;
    f[0][0] = 0;

    FOR(i, 1, n) {
        FOR(j, 0, 3) {
            if (s[i - 1] == HARD[j]) {
                f[i][j] = f[i - 1][j] + a[i];
                if (j > 0) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            } else if (j > 0 && s[i - 1] == HARD[j - 1]) {
                f[i][j] = min(f[i-1][j], f[i-1][j-1]);
            } else f[i][j] = f[i - 1][j];
            //cerr << i << ' ' << j << ' ' << f[i][j] << '\n';
        }
    }
    ll res = oo;
    FOR(j, 0, 3) res = min(res, f[n][j]);
    cout << res;
}
