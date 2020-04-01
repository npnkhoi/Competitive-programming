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

int n, w, status, wide;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> w;
	int tmp = -1, head = 0;
	FOR(i, 1, n) {
		cin >> status >> wide;
		if (status) {
			if (tmp == -1) {
				head = i;
				tmp = 0;
			}
			tmp += wide;
			if (tmp >= w) {
				cout << head;
				return 0;
			}
		} else tmp = -1;
	}
	cout << -1;
}
