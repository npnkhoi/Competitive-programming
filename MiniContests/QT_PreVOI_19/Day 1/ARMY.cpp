#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "ARMY"

typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int md = 1e9 + 7, N = 1e6 + 5;

int n;
lint m;
lint fac[N], rev[N], f[N];

lint Exp(lint a, lint n) {
    if (n == 0) return 1;
    lint res = Exp(a, n / 2);
    res = res * res % md;
    if (n & 1) res = res * a % md;
    return res;
}

void init() {
    fac[0] = rev[0] = 1;
    FOR(i, 1, n) {
        fac[i] = fac[i - 1] * i % md;
        //rev[i] = rev[i - 1] * Exp(i, md - 2) % md;
    }
}

void dp() {
    f[0] = 1;
    FOR(i, 2, n) {
        f[i] = (f[i - 1] + f[i - 2]) % md * (i - 1) % md;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	cin >> m >> n;
	if (m == 0 || n == 0) {
        cout << 1;
        exit(0);
	}
    init();
    dp();
    //cerr << fac[n] << ' ' << rev[n] << ' ' << f[n] << '\n';
    cout << fac[n] * Exp(f[n], m - 1) % md;
}
