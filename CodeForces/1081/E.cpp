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

const int N = 1e5 + 5, oo = 1e9 + 7;

int n, a[N], b[N];
ll x[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
    cin >> n;
    FOR(i, 1, n / 2) {
        int j = 2 * i;
        cin >> a[j];
        b[j] = oo;
        bool flag = 0;
        FOR(u, 1, sqrt(a[j])) {
            if (a[j] % u) continue;
            int v = a[j] / u;
            if ((v - u) % 2) continue;
            int pre = (v - u) / 2, cur = (v + u) / 2;
            if (pre <= b[j - 2]) continue;
            flag = 1;
            if (cur < b[j]) {
                b[j] = cur;
                b[j - 1] = pre;
            }
        }
        if (!flag) {
            cout << "No\n";
            exit(0);
        }
    }
    FOR(j, 1, n) {
        x[j] = (ll)b[j] * b[j] - (ll)b[j - 1] * b[j - 1];
        if (x[j] > 1e13 || x[j] < 1) {
            cout << "No";
            exit(0);
        }
    }
    cout << "Yes\n";
    FOR(i, 1, n) cout << x[i] << ' ';
}
