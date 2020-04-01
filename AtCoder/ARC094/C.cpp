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

void update(int a, int &tmp) {

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	int a[3], res;
	REP(i, 3) cin >> a[i];
	res = 10000;
	FOR(x, -1, 51) {
		int tmp = 0;
		REP(i, 3) {
			if (x < a[i]) tmp += a[i] - x;
			else if (x > a[i]) tmp += (x - a[i] + 1) / 2 + (x - a[i]) % 2; 
		}
		res = min(res, tmp);
	} 	
	cout << res;
}
