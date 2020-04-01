// Kayak

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int m, b, n, e, sb, sn, se;
int c[N];
vector<int> power;
vector<pair<int, int> > pairs;

bool check(long long x) {
	vector<int> cnt = {b, n, e};

	for (int i = 0; i < m; i++) {
		long long bound = (x + c[i] - 1) / c[i];

		for (int j = 0; j < 7; ++ j) {
			if (j == 6) return false;

			if (power[pairs[j].first] + power[pairs[j].second] >= bound) {
				cnt[pairs[j].first] --;
				cnt[pairs[j].second] --;

				if (cnt[0] < 0 || cnt[1] < 0 || cnt[2] < 0) {
					cnt[pairs[j].first] ++;
					cnt[pairs[j].second] ++;
					continue;
				} else break;
			}
		}
	}
	return true;
}

void input() {
	scanf("%d%d%d", &b, &n, &e);
	scanf("%d%d%d", &sb, &sn, &se);
	m = (b + n + e) / 2;
	for (int i = 0; i < m; ++ i) {
		scanf("%d", &c[i]);
	} 
}

void init() {
	sort(c, c + m);
	power = {sb, sn, se};
	for (int i = 0; i < 3; ++ i) {
		for (int j = i; j < 3; ++ j) {
			pairs.push_back({i, j});
		}
	}
	sort(pairs.begin(), pairs.end(), [](pair<int, int> a, pair<int, int> b){
		return power[a.first] + power[a.second] < power[b.first] + power[b.second];
	});
}

void process() {
	long long l = (long long) c[0]*(sb+sb), r = (long long)c[m-1]*(se+se), mid, bs = l;
	while (l <= r) {
		// cerr << l << ' ' << r << '\n';
		mid = (l + r) / 2;
		if (check(mid)) {
			bs = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	printf("%lld", bs);
}

int main() {
	input();
	init();
	process();
}