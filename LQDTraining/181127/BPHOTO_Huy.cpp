#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> ix3;

int blockSize;

inline bool Magic(ix3 A, ix3 B) {
	if (A.second.first / blockSize != B.second.first / blockSize) {
		return A.second.first / blockSize < B.second.first / blockSize;
	}
	return A.second.second < B.second.second;
}

const int MAX = 10007;
int cnt[MAX];

int main() {
	freopen("BPHOTO.inp", "r", stdin);
	freopen("BPHOTO.ans", "w", stdout);
	int n, c; cin >> n >> c;
	blockSize = sqrt(n);
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	int q; cin >> q;
	vector<ix3> Query;
	vector<int> Result(q + 1);
	for (int i = 1; i <= q; ++i) {
		int l, r; scanf("%d %d", &l, &r);
		Query.push_back(ix3(i, ii(l, r)));
	}

	sort(Query.begin(), Query.end(), Magic);

	set<ii> s;
	set<ii> ::iterator it;
	int curL = 0, curR = 0;
	for (int i = 0; i < (int)Query.size(); ++i) {
		int L = Query[i].second.first, R = Query[i].second.second;
		while (curL > L) {
			s.erase(ii(cnt[a[curL]], a[curL]));
			--curL, ++cnt[a[curL]];
			s.insert(ii(cnt[a[curL]], a[curL]));
		}
		while (curL < L) {
			s.erase(ii(cnt[a[curL]], a[curL]));
			--cnt[a[curL]], ++curL;
			s.insert(ii(cnt[a[curL]], a[curL]));
		}
		while (curR > R) {
			s.erase(ii(cnt[a[curR]], a[curR]));
			--cnt[a[curR]], --curR;
			s.insert(ii(cnt[a[curR]], a[curR]));
		}
		while (curR < R) {
			s.erase(ii(cnt[a[curR]], a[curR]));
			++curR, ++cnt[a[curR]];
			s.insert(ii(cnt[a[curR]], a[curR]));
		}

		it = s.end(); --it;

		// cerr << "debug: " << L << " " << R << " " << it->first << " " << it->second << '\n';
		Result[Query[i].first] = (it->first > ((R - L + 1) / 2)) ? it->second : 0;
	}

	for (int i = 1; i <= q; ++i) {
		printf((Result[i] == 0) ? "%d\n" : "1 %d\n", Result[i]);
	}
}