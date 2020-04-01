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
	return l + (
		1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) + 
		1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) + 
		1LL * rand() * (RAND_MAX + 1) + 
		1LL * rand()) % (r - l + 1);
}

const int N = 3e5 + 5;
const int C = 1e4 + 5;

vector<vector<int> > s;
int n, c, nQuery, a[N];

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".ans", "w", stdout);
	cin >> n >> c;
	s.resize(c + 5);
	FOR(i, 0, c) s[i].resize(n + 5);
	FOR(i, 1, n) {
		cin >> a[i];
	}
	FOR(i, 1, c) {
		s[i][0] = 0;
		FOR(j, 1, n) {
			s[i][j] = s[i][j - 1] + (a[j] == i);
		}
	}
	cin >> nQuery;
	REP(i, nQuery) {
		int l, r;
		cin >> l >> r;
		int bound = (r - l + 1) / 2 + 1;
		int flag = 0;
		FOR(i, 1, c) {
			if (s[i][r] - s[i][l - 1] >= bound) {
				cout << "1 " << i << "\n";
				flag = 1;
				break; 
			}
		}
		if (!flag) cout << "0\n";
	}
}
