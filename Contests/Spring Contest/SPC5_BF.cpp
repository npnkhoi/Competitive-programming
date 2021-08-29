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



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	int n = 5, a[100];
	FOR(i, 1, n) {
		FOR(j, 1, i) a[j] = j;
		do {
			int cnt = 0;
			FOR(j, 1, i) cnt += (abs(a[j] - j) == 1);
			FOR(j, 1, i) cerr << a[j] << ' '; cerr << " => " << cnt << '\n';
		}  while (next_permutation(a + 1, a + i + 1));
	}
}
