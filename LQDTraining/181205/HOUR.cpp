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

const int END_DAY = 24 * 3600;

void getInt(int &x) {
  int c = getchar();
  while (c < '0' || '9' < c) c = getchar();
  x = c - '0';
  while (1) {
    c = getchar();
    if (c < '0' || '9' < c) break;
    x = x * 10 + c - '0';
  }
}

void getTime(int &t) {
  int h, m, s;
  getInt(h); getInt(m); getInt(s);
  t = h * 3600 + m * 60 + s;
}

int n, q, cnt[END_DAY + 2], s[END_DAY + 2];

int sum(int l, int r) {
  if (l == 0) return s[r];
  else return (s[r] - s[l - 1]);
}

int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
  getInt(n);
  FOR(i, 1, n) {
    int x1, x2;
    getTime(x1); getTime(x2);
    cerr << x1 << " " << x2 << "\n";
    if (x1 <= x2) {
      cnt[x1] ++; cnt[x2 + 1] --;
    } else {
      cnt[x1] ++; cnt[END_DAY] --;
      cnt[0] ++; cnt[x2 + 1] --;
    }
  }
  s[0] = cnt[0];
  FOR(i, 1, END_DAY - 1) {
    cnt[i] += cnt[i - 1];
    s[i] = s[i - 1] + cnt[i];
    //cerr << s[i] << '\n';
  }
  getInt(q);
  REP(i, q) {
    int x1, x2;
    getTime(x1); getTime(x2);
    if (x1 <= x2) printf("%.10lf\n", (double) sum(x1, x2) / (x2 - x1 + 1));
    else printf("%.10lf\n", (double) (sum(x1, END_DAY - 1) + sum(0, x2)) / (END_DAY - x1 + x2 + 1));
  }
	return 0;
}
