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

const int N = 1e3 + 5, LO = 1000, HI = 2011;

int n, a[N], x[4], y[4];

void parse(int x, int dig[]) {
  FORD(i, 4, 1) {
    dig[i] = x % 10;
    x /= 10;
  }
}

int diff(int a, int b) {
  parse(a, x);
  parse(b, y);
  int res = 0;
  FOR(i, 1, 4) res += x[i] != y[i];
  return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	int cur = LO;
  cin >> n;
  FOR(i, 1, n) {
    cin >> a[i];
    while (diff(cur, a[i]) > 1) {
      cur ++;
      if (cur > HI) {
          cout << -1;
          exit(0);
      }
    }
    a[i] = cur;
  }
  FOR(i, 1, n) cout << a[i] << '\n';
	return 0;
}
