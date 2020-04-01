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

void backTrack(int dir, int cnt) {
	if (cnt > n) res ++;
	else if (dir == 0) {
		FOR(i, ptr0 + 1, n) if (!mark[i]) {
			pos0.pb(i);
			backTrack(1, cnt + 1);
		} else 
	}
}
int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	scanf("%d", &n);
	scanf("%s", s + 1);
	ptr0 = 0, ptr1 = n + 1;
	backTrack(0, 0);
}
