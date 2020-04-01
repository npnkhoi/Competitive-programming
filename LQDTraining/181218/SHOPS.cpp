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

#define task "SHOPS"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 5e5 + 5;

int n, s;
pair<ll, int> a[N];
deque<int> q;

bool cmp(ii u, ii v) {
    if (u.fi != v.fi) return u.fi > v.fi;
    else return u.se < v.se;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> n >> s;
    FOR(i, 1, n) {
        cin >> a[i].fi;
        a[i].fi += a[i-1].fi;
        a[i].se = i;
    }
    sort(a, a + n + 1);
    int len = 0, pos, mi = n + 1, idx = n + 1;
    FORD(i, n, 0) {
        //cerr << "a[i] = " << a[i].fi << ' ' << a[i].se << '\n';
        while (idx > 0 && a[idx - 1].fi >= a[i].fi - s) {
            --idx;
            mi = min(mi, a[idx].se);
        }
        //cerr << idx << ' ' << mi << '\n';
        if (a[i].se - mi > len) {
            len = a[i].se - mi;
            pos = a[i].se;
        } else if (a[i].se - mi == len && pos > a[i].se) {
            pos = a[i].se;
        }
    }
    cout << len << ' ' << pos - len + 1;
}

