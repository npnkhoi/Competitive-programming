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

#define task "MEMORIES"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;

int n, k, a[N];

bool ok(int x) {
    int sum = 0, cnt = 1;
    FOR(i, 1, n) {
        if (sum + a[i] > x) sum = 0, cnt ++;
        sum += a[i];
    }
    return cnt <= k;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    int l = 0, r = 1e9, mid, bs = r;
    while (l <= r) {
        mid = (l + r) / 2;
        if (ok(mid)) {
            bs = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << bs;
}
