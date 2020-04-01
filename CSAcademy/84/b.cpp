#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 5e5 + 5;
char s[N];
int n, res, cnt;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	cin >> s + 1;
	int j = 0;
	FOR(i, 1, n) {
		while (cnt < 3 && j < n) cnt += (s[++j] == '1');
		//cerr << i << " " << j << "\n";
		if (cnt < 3) {
			res = max(res, n - i + 2);
			break;
		} else {
			res = max(res, j - i + 1);
		}
		cnt -= (s[i] == '1');
	}
	cout << res;
}
