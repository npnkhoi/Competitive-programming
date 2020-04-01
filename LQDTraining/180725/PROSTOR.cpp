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

const int N = 1e5 + 5;
const int COOR = 1000;
struct Query {
	int x, type, y1, y2;
	Query(): x(0), type(0), y1(0), y2(0) {}
	Query(int _x, int _type, int _y1, int _y2): x(_x), type(_type), y1(_y1), y2(_y2) {}
};

int n;
int a[N][6], ft1[COOR + 5], ft2[COOR + 5][COOR + 5], flat[6];
vi dim;
vector<Query> que;
vector<ii> v;
long long res, tmp1, tmp2, ans;

bool cmp(Query a, Query b) {
	if (a.x != b.x) return a.x < b.x;
	else return a.type < b.type;
} 

void update1(int pos, int val) {
	for (; pos <= COOR; pos += pos & -pos) ft1[pos] += val;
}
int get1(int pos) {
	int res = 0;
	for (; pos; pos -= pos & -pos) res += ft1[pos];
	return res;
}
void update2(int x, int y, int val) {
	for (int i = x; i <= COOR; i += i&-i) 
	for (int j = y; j <= COOR; j += j&-j) 
		ft2[i][j] += val;
}
int get2(int x, int y) {
	int res = 0;
	for (int i = x; i; i -= i&-i)
		for (int j = y; j; j -= j&-j) {
			res += ft2[i][j];
		}
	return res;
}
int get2(int x, int y, int u, int v) {
	int res = get2(u, v);
	if (x > 0) res -= get2(x-1, v);
	if (y > 0) res -= get2(u, y-1);
	if (x > 0 && y > 0) res += get2(x-1, y-1);
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	flat[0] = flat[1] = flat[2] = 1;
	FOR(i, 1, n) {
		REP(j, 6) {
			cin >> a[i][j];
		}	
		REP(j, 3) {
			if (a[i][j] == a[i][j+3]) flat[i] = j;
		}
		//cerr << flat[i] << "\n";
	}
	REP(x, 3) REP(y, 3) if (x < y) {
		memset(ft2, 0, sizeof ft2);
		int z;
		REP(i, 3) if (i != x && i != y) z = i;
		FOR(i, 1, n) {
			int u = a[i][z], v = a[i][z+3];
			if  (u > v) swap(u, v);
			if (flat[i] == x) update2(u, v, +1);
		}
		FOR(i, 1, n) if (flat[i] == y) {
			int u = a[i][z], v = a[i][z+3];
			if (u > v) swap(u, v);
			ans += get2(u, 1, COOR, v);
		}
	}
	REP(x, 3) {
		memset(ft2, 0, sizeof ft2);
		if (x == 0) dim = {1, 2};
		else if (x == 1) dim = {0, 2};
		else dim = {0, 1};
		que.clear();
		FOR(i, 1, n) {
			REP(j, 3) if (a[i][j] > a[i][j+3]) swap(a[i][j], a[i][j+3]); 
			if (flat[i] == x) {
				que.pb(Query(a[i][dim[0]], 0, a[i][dim[1]], a[i][dim[1] + 3]));
				que.pb(Query(a[i][dim[0] + 3], 1, a[i][dim[1]], a[i][dim[1] + 3]));
			}
		}
		sort(que.begin(), que.end(), cmp);
		res = 0, tmp1 = 0, tmp2 = 0;
		REP(i, que.size()) {
			int u = que[i].y1, v = que[i].y2;
			if (que[i].type == 0) {
				update1(u, +1);
				update1(v+1, -1);
				update2(u, v, +1);
			} else {
				res += get1(u) + get1(v) - 2;
				tmp1 += get2(1, v+1, u-1, COOR);
				tmp2 += get2(u, v, u, v) - 1;
				update1(u, -1);
				update1(v+1, +1);
				update2(u, v, -1);
			}
		}
		ans += res - tmp1 - tmp2 / 2;
		//cerr << ans << "\n";
	}
	cout << ans;
}
