#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()
#define task ""
typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;

multiset<int> s;
int n, a[N], b[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) cin >> b[i];
	if (a[1] != b[1] || a[n] != b[n]) {
		cout << "No";
		exit(0);
	}
	FOR(i, 2, n) s.insert(a[i] - a[i - 1]);
	FOR(i, 2, n) {
		if (s.find(b[i] - b[i - 1]) == s.end()) {
			cout << "No\n";
			// cerr << i << '\n';
			exit(0);
		}
		s.erase(s.find(b[i] - b[i - 1]));
	}
	cout << "Yes";
}
