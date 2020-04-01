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
#define task "0"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

string contains(string &a, string &b) {
	int i = 0, j = 0;
	while (1) {
		cerr << i << " " << j << "\n";
		if (i >= (int) a.size()) return "TRUE";
		if (j >= (int) b.size()) return "FALSE";
		if (a[i] == b[j]) i ++, j ++;
		else if (i == 0) j ++;
		else i = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	string a, b;
	cin >> a >> b;
	cout << contains(a, b);
}
