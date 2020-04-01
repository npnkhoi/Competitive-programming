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

#define task "BPHOTO"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

ll Rand(ll l, ll r) {
	ll res = l + (
		(long long) rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) + 
		(long long) rand() * (RAND_MAX + 1) * (RAND_MAX + 1) + 
		(long long) rand() * (RAND_MAX + 1) + 
		(long long) rand()) % (r - l + 1);
	if (res < l) res += r - l + 1;
	return res;
	// return l + (long long) rand() * (long long) rand() % (r - l + 1) 
	// * (long long) rand() % (r - l + 1);
}

const int N = 3e5 + 5;
const int C = 1e4 + 5;

int n, c, nQuery;
int a[N];
vi pos[C];

int count(int val, int l, int r) {
	return upper_bound(all(pos[val]), r) - upper_bound(all(pos[val]), l - 1);
}

int main() {
	srand(time(NULL));
	// ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);
	// freopen(task".inp", "r", stdin);
	// freopen(task".out", "w", stdout);
	// cin >> n >> c;
	scanf("%d%d", &n, &c);
	FOR(i, 1, n) {
		// cin >> a[i];
		scanf("%d", &a[i]);
		pos[a[i]].push_back(i);
	}
	// cin >> nQuery;
	scanf("%d", &nQuery);
	REP(i, nQuery) {
		int l, r;
		// cin >> l >> r;
		scanf("%d%d", &l, &r);
		int bound = (r - l + 1) / 2 + 1;
		int flag = 0;
		REP(i, 20) {
			int x = a[Rand(l, r)];
			// cerr << "try " << x << "\n";
			if (count(x, l, r) >= bound) {
				cout << "1 " << x << "\n";
				flag = 1;
				break;
			}
		}
		if (flag == 0) cout << "0\n";
	}
	return 0;
}
