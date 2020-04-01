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
#define task "KGCD"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e6 + 5;
const int A = 1e5;
int n, k, res;
int cnt[A + 5];

int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d%d", &n, &k);
	FOR(i, 1, n) {
		int val;
		scanf("%d", &val);
		cnt[val] ++;
	}
	FOR(i, 1, A) {
		int tmp = 0;
		for (int j = i; j <= A; j+= i) tmp += cnt[j];
		if (tmp >= k) res = i;
	}
	printf("%d", res);
}
