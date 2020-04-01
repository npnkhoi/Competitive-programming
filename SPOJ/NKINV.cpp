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

const int N = 6e4 + 5;
int n, a[N], ft[N];
long long res;
void update(int pos, int val) {
	for (int i = pos; i <= 6e4; i += i & -i) ft[i] += val;
}
int get(int pos) {
	int res = 0;
	for (int i = pos; i; i -= i & -i) res += ft[i];
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	res = 1LL * n * (n-1) / 2;
	FOR(i, 1, n) {
		cin >> a[i];
		res -= get(a[i]);
		update(a[i], +1);
	}			
	cout << res;
}

