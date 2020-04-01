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

const int N = 25e4 + 5;
struct Node{
	int cnt[10];
	int l, r, lazy;
} IT[8*N];
int tmp[10];
int n, q, a[N];


void build(int p, int l, int r) {
	IT[p].l = l;
	IT[p].r = r;
	if (l == r) {
		IT[p].cnt[a[l]] = 1;
	} else {
		int mid = (l + r) / 2;
		build(2*p, l, mid);
		build(2*p+1, mid + 1, r);
		REP(i, 10) IT[p].cnt[i] = IT[2*p].cnt[i] + IT[2*p+1].cnt[i];
	}
}
void lazyDown(int p) {
	REP(i, 10) tmp[i] = IT[p].cnt[(i-IT[p].lazy+10) % 10];
	REP(i, 10) IT[p].cnt[i] = tmp[i];
	IT[2*p].lazy = (IT[2*p].lazy + IT[p].lazy) % 10;
	IT[2*p+1].lazy = (IT[2*p+1].lazy + IT[p].lazy) % 10;
	IT[p].lazy = 0;
}
int get(int p, int l, int r) {
	lazyDown(p);
	if (l > IT[p].r || IT[p].l > r) return 0;
	if (l <= IT[p].l && IT[p].r <= r) {
		int res = 0;
		REP(i, 10) res += IT[p].cnt[i] * i;
		return res;
	} else {
		int mid = (l + r) / 2;
		return get(2*p, l, r) + get(2*p+1, l, r);
	}
}
void update(int p, int l, int r) {
	lazyDown(p);
	if (l > IT[p].r || IT[p].l > r) return;
	//cerr << "update " << IT[p].l << " " << IT[p].r << "\n";
	if (l <= IT[p].l && IT[p].r <= r) {
		IT[p].lazy = 1;
		lazyDown(p);
	} else {
		int mid = (l + r) / 2;
		update(2*p, l, r);
		update(2*p+1, l, r);
		REP(i, 10) IT[p].cnt[i] = IT[2*p].cnt[i] + IT[2*p+1].cnt[i];
	}
}
void show(int p) {
	cerr << "vtx: " << p << " (" << IT[p].l << ", " << IT[p].r << ")\n";
	REP(i, 10) REP(j, IT[p].cnt[i]) cerr << i << " "; cerr << "\n";
	if (IT[p].l < IT[p].r) {
		show(2*p);
		show(2*p+1);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> q;
	FOR(i, 1, n) {
		char ch;
		cin >> ch;
		a[i] = ch - '0';
		//cerr << a[i] << '\n';
	}
	build(1, 1, n);
	//show(1);
	REP(khue, q) {
		int l, r;
		cin >> l >> r;
		cout << get(1, l, r) << '\n';
		update(1, l, r);
		//show(1);
		//FOR(i, 1, n) cerr << get(1, i, i) << " "; cerr << "\n";
	}
}
