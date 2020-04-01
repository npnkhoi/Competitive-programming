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

#define task "CUTTREE"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 3e5 + 5;

int n, p;
int a[N], b[N], x[N], y[N], z[N], t[N];
vi hubx, huby, row[N], col[N];

int cnt(vi &v, int l, int r) {
    return upper_bound(all(v), r) - upper_bound(all(v), l - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i] >> b[i];
        hubx.push_back(a[i]);
        huby.push_back(b[i]);
    }
    cin >> p;
    FOR(i, 1, p) {
        cin >> x[i] >> y[i] >> z[i] >> t[i];
        hubx.push_back(x[i]);
        huby.push_back(y[i]);
        hubx.push_back(z[i]);
        huby.push_back(t[i]);
    }
    sort(all(hubx));
    hubx.resize(unique(all(hubx)) - hubx.begin());
    huby.resize(unique(all(huby)) - huby.begin());
    FOR(i, 1, n) {
        a[i] = upper_bound(all(hubx), a[i]) - hubx.begin();
        b[i] = upper_bound(all(huby), b[i]) - huby.begin();
        col[a[i]].push_back(b[i]);
        row[b[i]].push_back(a[i]);
    }
    FOR(i, 1, p) {
        x[i] = upper_bound(all(hubx), x[i]) - hubx.begin();
        y[i] = upper_bound(all(huby), y[i]) - huby.begin();
        z[i] = upper_bound(all(hubx), z[i]) - hubx.begin();
        t[i] = upper_bound(all(huby), t[i]) - huby.begin();
        cout << cnt(col[x[i]], y[i] + 1, t[i]) + cnt(row[y[i]], x[i], z[i] - 1) +
            cnt(col[z[i]], y[i], t[i] - 1) + cnt(row[t[i]], x[i] + 1, z[i]) << '\n';

    }
}

