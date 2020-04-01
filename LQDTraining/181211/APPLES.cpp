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

#define task "APPLES"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

int tc, n;
ll a;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".in", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> tc;
    REP(khue, tc) {
        cin >> n >> a;
        if (n == 2) {
            if (a % 5) cout << "-1\n";
            else cout << a << ' ' << a / 5 * 3;
        } else if (n == 3) {
            if (a % 13) cout << "-1\n";
            else cout << a << ' ' << a / 13 * 7 << ' ' << a / 13 * 4 << '\n';
        }
    }
}
