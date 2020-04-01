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

int n, a[N], b[N], x, idx;
vi v[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
        v[n - a[i]].push_back(i);
    }
    FOR(i, 1, n) {
        //cerr << cnt[i] << "\n";
        if (v[i].size() % i != 0) {
            cout << "Impossible";
            return 0;
        }
        REP(j, v[i].size()) {
            if (j % i == 0) ++ idx;
            b[v[i][j]] = idx;
        }
    }
    cout << "Possible\n";
    FOR(i, 1, n) cout << b[i] << ' ';
}
