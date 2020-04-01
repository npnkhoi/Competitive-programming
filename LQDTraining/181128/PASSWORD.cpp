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

#define task ""

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2e4 + 5;

int n, res;
string s[N];
map<string, int> cnt;
vector<string> sub;

bool cmp(string &a, string &b) {
		return a.size() < b.size();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("PASSWORD.inp", "r", stdin);
	freopen("PASSWORD.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		cin >> s[i];
		cnt[s[i]] ++;
	}
	for (int x = 1; x <= n; ++ x) {
		int l = s[x].size();
		sub.clear();
		for (int i = 0; i < l; ++ i) {
			string tmp = "";
			for (int j = i; j < l; ++ j) {
				tmp += s[x][j];
				sub.push_back(tmp);
			}
		}
		sort(all(sub));
		REP(i, sub.size()) {
			if (i > 0 && (sub[i] == sub[i - 1])) continue;
			res += cnt[sub[i]];
		}
	}
	res -= n;
	cout << res;
}