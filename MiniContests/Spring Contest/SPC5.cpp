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

#define task "SPC5"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1005, md = 1e9 + 7;

int tc, n, k;
int a[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	cin >> tc;
	REP(NhiThunCute, tc) {
		cin >> n >> k;
		int res = 0;
		FOR(i, 1, n) a[i] = i;
		do {
			int cnt = 0;
			FOR(i, 1, n) cnt += (abs(a[i] - i) == 1);
			res += (cnt == k);
		} while (next_permutation(a + 1, a + n + 1));
		cout << res << '\n';
	} 
}
