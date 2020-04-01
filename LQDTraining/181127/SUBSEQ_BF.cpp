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

#define task "SUBSEQ"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e6 + 5;

int n, a[N];
long long res, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".ans", "w", stdout);
	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i];

	int res = 0;
	FOR(i, 1, n) {
		long long sum = 0;
		FOR(j, i, n) {
			sum += a[j];
			if (sum > k) break;
			else res ++;
		}
	}
	cout << res;
	return 0;
}
