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
#define task "PORDER"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2e5 + 5;

int n;
int a[N], w[N], ft[N];

void update(int pos, int val) {
	for (int i = pos; i <= n; i += i & -i) ft[i] += val;
}
int get(int pos) {
	int res = 0;
	for (int i = pos; i; i -= i & -i) res += ft[i];
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	int tc; cin >> tc;
	REP(khue, tc) {
		cin >> n;
		//scanf("%d", &n);
		FOR(i, 1, n) 
			cin >> w[i];
			//scanf("%d", &w[i]);
		FOR(i, 1, n) ft[i] = i & -i;
		FORD(i, n, 1) {
			int l = 1, r = n, bs = r;
			while (l <= r) {
				int mid = (l+r) / 2;
				if (get(mid) >= i - w[i]) 
					bs = mid, r = mid - 1;
				else l = mid + 1;
			}
			a[i] = bs;
			update(bs, -1);
			//cerr << bs << "\n";
			//FOR(i, 1, n) cerr << get(i) << " "; cerr << "\n";
		}
		FOR(i, 1, n) 
			cout << a[i] << " "; cout << "\n";
			//printf("%d ", a[i]); printf("\n");
		//cerr << "\n";
	}			
}
