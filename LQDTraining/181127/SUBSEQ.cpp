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

#define task "SUBSEQ"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e6 + 5;

int n, a[N];
long long res, k;

void getInt(int &x) {
	int c;
	do c = getchar(); while (c < '0' || '9' < c);
	x = c - '0';
	while (1) {
		c = getchar();
		if (c < '0' || '9' < c) break;
		x = x * 10 + c - '0';
	}
}

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d %lld", &n, &k);
	FOR(i, 1, n) {
		// getInt(a[i]);
		scanf("%d", &a[i]); 
	}
	int l = 1;
	long long s = 0;

	FOR(r, 1, n) {
		s += a[r];
		while (s > k) {
			s -= a[l];
			l ++;
		}
		res += (r - l + 1);
	}
	printf("%lld\n", res);
	return 0;
}
