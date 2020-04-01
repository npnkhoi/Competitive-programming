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

int n, k, a[N], res;
map<int, int> cnt;
vi ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
  cin >> n >> k;
  int l = 1;
  FOR(r, 1, n) {
    cin >> a[r];
    cnt[a[r]] ++;
    while (cnt.rbegin() -> first - cnt.begin() -> first > k) {
      int tmp = a[l];
      l ++;
      if (cnt[tmp] == 1) cnt.erase(tmp);
      else cnt[tmp] --;
    }
    //cerr << l << "\n";
    if (r - l + 1 > res) {
        res = r - l + 1;
      ans.clear();
      ans.push_back(l);
    } else if (r - l + 1 == res) {
      ans.push_back(l);
    }
  }
  cout << res << ' ' << ans.size() << '\n';
  REP(i, ans.size()) {
    cout << ans[i] << ' ' << ans[i] + res - 1 << '\n';
  }
	return 0;
}
