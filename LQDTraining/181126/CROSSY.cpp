#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair

typedef pair<pair<int, int>, int> Pack;

const int N = 1e5 + 5;

int n, ans[N];
Pack a[N];

void input() {
	// freopen("CROSSY.inp", "r", stdin);
	// freopen("CROSSY.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		int t;
		char d;
		scanf("%d %c", &t, &d);

		if (d == 'D') d = 0;
		else if (d == 'L') d = 1;
		else if (d == 'U') d = 2;
		else d = 3;

		a[i] = mp(mp(t, d), i);
	}
}

void init() {
	sort(a + 1, a + n + 1);
	memset(ans, -1, sizeof ans);
}

void solve() {
	int idx = 1, inQue = 0, cntOut = 0;
	vector<int> nxt;
	deque<int> q[4];

	for (int cur = 0; cntOut < n; ++ cur) {
		if (idx <= n && cur == a[idx].fi.fi) {
			do {
				q[a[idx].fi.se].push_back(idx);
				inQue ++;
				idx ++;
			} while (idx <= n && a[idx].fi.fi == a[idx - 1].fi.fi);
		}

		if (inQue == 0 && idx <= n) {
			cur = a[idx].fi.fi - 1;
			continue;
		}

		nxt.clear();
		for (int i = 0; i < 4; ++ i) {
			if (q[i].empty()) continue;
			int pre = (i == 0 ? 3 : i - 1);
			
			if (q[pre].empty())
				nxt.push_back(i);
		}

		if (nxt.empty()) break;
		for (int x : nxt) {
			int tmp = q[x].front();
			q[x].pop_front();
			ans[a[tmp].se] = cur;
			cntOut ++;
			inQue --;
		}

	}	
}

void answer() {
	for (int i = 1; i <= n; ++ i) {
		printf("%d\n", ans[i]);
	}
}

int main() {
	input();
	init();
	solve();
	answer();
}