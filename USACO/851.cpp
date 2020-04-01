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

#define task "teamwork"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e4 + 5, K = 1e3 + 5;

int n, k, a[N];
ll f[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".in", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> n >> k;
    FOR(i, 1, n) {
        cin >> a[i];
        int cur = 0;
        FORD(j, i - 1, max(i - k, 0)) {
            cur = max(cur, a[j + 1]);
            f[i] = max(f[i], f[j] + (ll)cur * (i - j));
        }
    }
    //FOR(i, 1, n) cerr << f[i] << ' '; cerr << '\n';;
    cout << f[n];
}
