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

const int N = 1e5 + 5;

int n, k, md;
ll fac[N], res = 1, tmp = 1;

ll Exp(ll a, int x) {
    if (x == 0) return 1;
    ll res = Exp(a, x / 2);
    res = res * res % md;
    if (x % 2) res = res * a % md;
    return res;
}

ll comb(int n) {
    return 1LL * n * (n - 1) / 2 % md;
}

void ILoveMinhKhue(int l, int r, int h) {
    if (l == r) return;
    if (h <= 1) {
        res = res * Exp(fac[r - l + 1], md - 2) % md;
        tmp = (tmp - comb(r - l + 1)) % md;
        return;
    }
    int m = (l + r) / 2;
    ILoveMinhKhue(l, m, h - 1);
    ILoveMinhKhue(m + 1, r, h - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
    cin >> n >> k >> md;
    fac[0] = 1;
    FOR(i, 1, n) fac[i] = fac[i-1] * i % md;
    tmp = comb(n);
    ILoveMinhKhue(1, n, k);
    cerr << tmp << "\n";
    if (tmp < 0) tmp += md;
    tmp = tmp * comb(n) % md;
    res = res * tmp % md;
    cout << res;
}
