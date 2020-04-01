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

const int N = 1e5 + 5;

int n, a[N], b[N];
ll sumL, sumR, res;
vector<ii> l, r;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
  cin >> n;
  FOR(i, 1, n) {
    cin >> a[i] >> b[i];
    if (a[i] < b[i]) {
      sumL += a[i];
      l.push_back(mp(b[i] - a[i], i));
    } else {
      sumR += b[i];
      r.push_back(mp(a[i] - b[i], i));
    }
  }
  res = max(sumL, sumR);
  sort(all(l), greater<ii>());
  sort(all(r), greater<ii>());
  while (1) {
    if (sumL > sumR) {
      sumL -= a[l.back().se];
      sumR += b[l.back().se];
      r.push_back(a.back());
      l.pop_back();
      if (max(sumL, sumR) > res) break;
      else res = min(res, max(sumL, sumR));
    } else if (sumL < sumR) {
      sumR -= b[r.back().se];
      sumL += a[r.back().se];
      l.push_back(r.back());
      r.pop_back();
      if (max(sumL, sumR) > res) break;
      else res = min(res, max(sumL, sumR));
    } else break;
  }
  cout << res < '\n';
  int idx = 0;
  ll curL = 0, curR = 0;
  while (!l.empty() || ) {
    if ()
  }
}
