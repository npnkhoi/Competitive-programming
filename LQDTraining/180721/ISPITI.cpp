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
#define task "ISPITI"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2e5 + 5;
struct Node{
	int val, l, r;
};
struct Query{
	char type;
	int sc1, sc2, pos;
} que[N];
vector<Node> IT;
vi dataA, dataB;
map<ii, int> ID;
vector<set<int> > setScore;
vector<ii> a;
int n, m, p, idx;

void compress(vi &v) {
	if (v.empty()) return;
	int p = 1, n = v.size();
	sort(v.begin(), v.end());
	FOR(i, 1, n-1) {
		if (v[i] != v[i-1]) v[p++] = v[i];
	}
	v.resize(p);
}
void build(int p, int l, int r) {
	IT[p].l = l;
	IT[p].r = r;
	if (l < r) {
		int mid = (l + r) / 2;
		build(2*p, l, mid);
		build(2*p+1, mid+1, r);
	}
}
void update(int pos, int x) {
	int p = 1;
	while (1) {
		IT[p].val = max(IT[p].val, x);
		if (IT[p].l == IT[p].r) break;
		if (pos <= IT[2*p].r) {
			p = 2 * p;
		} else {
			p = 2 * p + 1;
		}
	}
}
int get(int p, int l, int r) {
	if (l > IT[p].r || IT[p].l > r) {
		return -1;
	}
	if (l <= IT[p].l && IT[p].r <= r) return IT[p].val;
	return max(get(2*p, l, r), get(2*p+1, l, r));
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	REP(i, n) {
		cin >> que[i].type;
		if (que[i].type == 'D') {
			cin >> que[i].sc1 >> que[i].sc2;
			dataA.pb(que[i].sc1);
			dataB.pb(que[i].sc2);
			p ++;
		} else {
			cin >> que[i].pos;
		}
	}
	compress(dataA); compress(dataB);
	m = dataB.size();
	//debug(m);
	a.resize(p + 1);
	IT.resize(4*m + 1);
	setScore.resize(m + 1);
	//cerr << "resize done\n";
	build(1, 1, m);
	//cerr << "build done\n";
	REP(i, n) if (que[i].type == 'D') {
		//cerr << i << "\n";
		++ idx;
		a[idx].fi = lower_bound(dataA.begin(), dataA.end(), que[i].sc1) - dataA.begin() + 1;
		a[idx].se = lower_bound(dataB.begin(), dataB.end(), que[i].sc2) - dataB.begin() + 1;
		ID[a[idx]] = idx;
		setScore[a[idx].se].insert(a[idx].fi);
		update(a[idx].se, a[idx].fi);
	} else {
		int id = que[i].pos;
		if (!setScore[a[id].se].empty() && *setScore[a[id].se].rbegin() > a[id].fi) {
			int resA = * setScore[a[id].se].upper_bound(a[id].fi);
			cout << ID[mp(resA, a[id].se)] << '\n';
		} else if (a[id].se + 1 <= m && get(1, a[id].se + 1, m) >= a[id].fi) {
			int l = a[id].se + 1, r = m, bs = r;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (get(1, a[id].se + 1, mid) >= a[id].fi) {
					bs = mid;
					r = mid - 1;
				} else l = mid + 1;
			}
			int resB = bs;
			int resA = * setScore[bs].lower_bound(a[id].fi);
			cout << ID[mp(resA, resB)] << '\n';
		} else cout << "NE\n";
	}
}
