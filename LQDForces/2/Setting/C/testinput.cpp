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

int tc, n, foo;
string s, t;

bool check(string &t, string &s) {
  for (int i = 0, j = 0; i < t.size() && j < s.size(); ++ i, ++ j) {
    while (j < s.size() && t[i] != s[j]) ++ j;
    if (j >= s.size() || t[i] != s[j]) return false;
  }
  return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	//freopen(task".out", "w", stdout);
  cin >> tc;
  while  (tc -- ) {
    cin >> s >> t;
    n = s.size();
    if (check(t, s)) {
      cerr << "yes\n";
    } else {
      cerr << "no\n";
    }
    REP(i, n) cin >> foo;
  }
	return 0;
}
