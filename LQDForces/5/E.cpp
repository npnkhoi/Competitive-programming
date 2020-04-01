#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, int> Que;

const int N = 1e5 + 5;

int n, q, block;
int a[N], ans[N], cnt[N], le[N], ri[N];
deque<int> pos[N];
multiset<int> dist;
Que que[N];

int get(int val) {
	if (pos[val].empty()) return 0;
	else return pos[val].back() - pos[val].front();
}

int main() {
	scanf("%d", &n);
	block = sqrt(n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		cnt[a[i]] ++;
		if (cnt[a[i]] == 1) le[a[i]] = i;
		else if (cnt[a[i]] == 2) ri[a[i]] = i;
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; ++ i) {
		int l, r;
		scanf("%d%d", &l, &r);
		que[i] = {{l, r}, i};	
	}
	sort(que + 1, que + q + 1, [](const Que &a, const Que &b) {
		if (a.first.first / block != b.first.first / block)
			return a.first.first / block < b.first.first / block;
		else return a.first.second < b.first.second;
	});
	// for (int i = 0; i <= n; ++ i) cerr << cnt[i] << ' '; cerr << '\n';
	int l = 1, r = 0;
	for (int i = 1; i <= q; ++ i) {
		int tmp = 0;
		// cerr << "-- " << i << '\n';
		// cerr << que[i].first.first << ' ' << que[i].first.second << '\n';
		while (r < que[i].first.second) {
			// cerr << r << '\n';
			++ r;
			if (cnt[a[r]] == 1) continue;
			else if (cnt[a[r]] == 2) {
				if (que[i].first.first <= le[a[r]] && ri[a[r]] <= que[i].first.second)
					tmp = max(tmp, ri[a[r]] - le[a[r]]);
				continue;
			}
			if (!pos[a[r]].empty()) 
				dist.erase(dist.find(get(a[r])));
			pos[a[r]].push_back(r);
			dist.insert(get(a[r]));
		}
		while (r > que[i].first.second) {
			// cerr << r << '\n';
			if (cnt[a[r]] == 1) {
				-- r;
				continue;
			} else if (cnt[a[r]] == 2) {
				if (que[i].first.first <= le[a[r]] && ri[a[r]] <= que[i].first.second)
					tmp = max(tmp, ri[a[r]] - le[a[r]]);
				r --;
				continue;
			}
			dist.erase(dist.find(get(a[r])));
			pos[a[r]].pop_back();
			if (!pos[a[r]].empty())
				dist.insert(get(a[r]));
			-- r;
		}

		while (l > que[i].first.first) {
			// cerr << l << '\n';
			-- l;
			if (cnt[a[l]] == 1) continue;
			else if (cnt[a[l]] == 2) {
				if (que[i].first.first <= le[a[l]] && ri[a[l]] <= que[i].first.second)
					tmp = max(tmp, ri[a[l]] - le[a[l]]);
				continue;
			}
			if (!pos[a[l]].empty()) 
				dist.erase(dist.find(get(a[l])));
			pos[a[l]].push_front(l);
			dist.insert(get(a[l]));
		}
		while (l < que[i].first.first) {
			// cerr << l << '\n';
			if (cnt[a[l]] == 1) {
				++ l;
				continue;
			} else if (cnt[a[l]] == 2) {
				if (que[i].first.first <= le[a[l]] && ri[a[l]] <= que[i].first.second)
					tmp = max(tmp, ri[a[l]] - le[a[l]]);
				++ l;
				continue;
			}
			dist.erase(dist.find(get(a[l])));
			pos[a[l]].pop_front();
			if (!pos[a[l]].empty())
				dist.insert(get(a[l]));
			++ l;
		}
		if (!dist.empty()) ans[que[i].second] = max(tmp, *dist.rbegin());
		else ans[que[i].second] = tmp;
		// for (auto it = dist.begin(); it != dist.end(); ++it) cerr << *it << ' '; cerr << '\n';
	}
	// cerr << "ok\n";
	for (int i = 1; i <= q; ++ i) printf("%d\n", ans[i]);
}