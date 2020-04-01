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

#define task "DISCOUNT"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;
const ll oo = 1e18;

int n, k, a[N];
ll s[N], f[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".in", "r", stdin);
	freopen(task".ans", "w", stdout);
    cin >> n >> k;
    FOR(i, 1, n) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    f[n+1] = 0;
    FORD(i, n, 1) {
        f[i] = oo;
        FOR(j, i, min(i + k, n)) {
            f[i] = min(f[i], f[j + 1] + a[i] + (s[j] - s[i]) / 2);
        }
    }
    cout << f[1];
}
