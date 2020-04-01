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

int n, a[N], dig[6], Exp[6];

void parse(int x) {
  FORD(i, 4, 1) {
    dig[i] = x % 10;
    x /= 10;
  }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	Exp[1] = 1000;
  Exp[2] = 100;
	Exp[3] = 10;
	Exp[4] = 1;
  cin >> n;
  int last = LO;
  FOR(i, 1, n) {
    cin >> a[i];
    parse(a[i]);
    FOR(i, 1, 4) cerr << dig[i] << ' '; cerr << '\n';
    if (a[i] < last) {
      FORD(i, 4, 1) {
        if (a[i] + (9 - dig[i]) * Exp[i] < last) {
          continue;
        }
        a[i] += (last - a[i] + Exp[i] - 1) / Exp[i] * Exp[i];
        break;
      }
      if (a[i] < last) {
        cout << -1;
        exit(0);
      }
    } else {
      cerr << "here\n";
      FOR(i, 1, 4) {
        cerr << dig[i] << " " << a[i] - Exp[i] << " " << last << "\n";
        if (dig[i] > 0 && a[i] - Exp[i] >= last) {
          a[i] -= (a[i] - last) / Exp[i] * Exp[i];
          cerr << "dec at " << i << "\n";
          break;
        } else continue;
      }
      if (a[i] > HI) {
        cout << -1;
        exit(0);
      }
    }
    last = a[i];
    cerr << last << '\n';
  }
  FOR(i, 1, n) {
    cout << a[i] << '\n';
  }
	return 0;
}
