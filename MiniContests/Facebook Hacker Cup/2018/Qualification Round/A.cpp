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
#define task "A"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 55;
int n, k;
ll v;
string name[N];
int id[N], cnt[N];
bool cmp(int a, int b) {
	if (cnt[a] != cnt[b]) return cnt[a] < cnt[b];
	else return a < b;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	int tc; cin >> tc;
	FOR(khue, 1, tc) {
		cin >> n >> k >> v;
		FOR(i, 1, n) cin >> name[i];
		//cerr << n << " " << k << " " << v << "\n";
		//FOR(i, 1, n) cerr << name[i] << "\n"; 
		v = 1 + (v - 1) % (n * k);
		memset(cnt, 0, sizeof cnt);
		FOR(i, 1, n) id[i] = i;
		FOR(i, 1, v) {
			sort(id + 1, id + n + 1, cmp);
			FOR(i, 1, k) cnt[id[i]] ++;
		}
		sort(id + 1, id + k + 1);
		cout << "Case #" << khue << ":";
		FOR(i, 1, k) cout << " " << name[id[i]];
		cout << " \n"; 
	}		
}
