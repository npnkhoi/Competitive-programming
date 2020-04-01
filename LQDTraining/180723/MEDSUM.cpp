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
#define task "MEDSUM"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 200 + 5;
const int L = 2e4 + 5;
const int md = 1e9;
int n, l, a[N][L];
bool flag;
int res;
int countSmaller(int a[], int b[], int val) {
	return upper_bound(a + 1, a + l + 1, val - 1) - (a + 1) + upper_bound(b + 1, b + l + 1, val - 1) - (b + 1);
}
int get(int a[], int b[], int k) {
	int l = 1, r = k, bs = 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (countSmaller(a, b, a[mid]) < k) {
			bs = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	if (countSmaller(a, b, a[bs]) <  k && k <= countSmaller(a, b, a[bs] + 1)) flag = 1;
	return a[bs];
}
int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d%d", &n, &l);
	FOR(i, 1, n) {
		FOR(j, 1, l) scanf("%d", &a[i][j]);
	}
	FOR(i, 1, n-1) FOR(j, i+1, n) {
		flag = 0;
		int tmp = get(a[i], a[j], l);
		if (flag == 0) tmp = get(a[j], a[i], l);
		//cerr << i << " " << j << " " << tmp << "\n";
		res = (res + tmp) % md;
	}
	printf("%d", res);
}
