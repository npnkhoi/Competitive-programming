#include <bits/stdc++.h>
using namespace std;

#define task "LORRY"

const int N = 1e5 + 5;

int n, v;
vector<pair<int, int> > caps[2];
int s[2][N];

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d%d", &n, &v);
	for (int i = 1; i <= n; ++i) {
		int type, cap;
		scanf("%d%d", &type, &cap);
		caps[type - 1].push_back(make_pair(cap, i));
	}
	int p = caps[0].size(), q = caps[1].size();

	sort(caps[0].rbegin(), caps[0].rend());
	for (int i = 1; i <= p; ++ i) {
		s[0][i] = s[0][i - 1] + caps[0][i - 1].first;
		// cerr << s[0][i] << "\n";
	}
	sort(caps[1].rbegin(), caps[1].rend());
	for (int i = 1; i <= q; ++ i) {
		s[1][i] = s[1][i - 1] + caps[1][i - 1].first;
	}

	int res = -1, numOfType0;
	for (int i = 0; i <= min(v, p); ++ i) {
		if ((v - i) / 2 <= q) {
			res = max(res, s[0][i] + s[1][(v - i) / 2]);
		} else {
			res = max(res, s[0][i] + s[1][q]);
		}
	}
	res = max(res, s[0][min(v, p)]);
	res = max(res, s[1][min(v / 2, q)]);
	printf("%d", res);
}