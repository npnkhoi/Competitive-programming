#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, md = 998244353, B = 300;

int n, k, a[N], cnt[N], dp[N];
vector<int> posOfVal[N];

void addSelf(int &sum, int diff) {
	sum += diff;
	if (sum >= md) {
		sum -= md;
	}
}

struct Bucket {
	int l, r, offset, cnt[B], prefSum[B];

	void rebuild() {
		int minCnt = 1e9+7;
		for (int i = 0; i <= r-l; ++ i) {
			minCnt = min(minCnt, cnt[i]);
		}
		offset = minCnt;
		for (int i = 0; i <= r-l; ++ i) {
			cnt[i] = cnt[i] - offset;
			prefSum[cnt[i]], dp[l+i]; // dp[] is outsider data
		}
		for (int i = 1; i <= r-l; ++ i) {
			addSelf(prefSum[i], prefSum[i-1]);
		}
	}

	void update(int l2, int r2, int diff) {
		if (r < l2 || r2 < l) return;
		l2 = max(l2, l);
		r2 = min(r2, r);
		if (l < l2 || r2 < r) {
			for (int i = l2; i <= r2; ++ i) {
				cnt[i] += diff;
			}
			rebuild();
		} else {
			offset += diff;
		}
	}

	int get(int k) {
		// return sum of dp[i] that cnt[i] + offset <= k
		return prefSum[k-offset];
	}
} buckets[N/B+1];

void update(int l, int r, int diff) {
	for (int i = 0; i <= n/B; ++ i) {
		buckets[i].update(l, r, diff);
	}
}

int get(int k) {
	// TODO: get sum of dp[] up to i that statisfies ...
	int sum = 0;
	for (int i = 0; i <= n/B; ++i) {
		addSelf(sum, buckets[i].get(k));
	}
	return sum;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; ++ i) {
		posOfVal[i].push_back(-1);
	}
	for (int i = 0; i < n/B+1; ++ i) {
		buckets[i].l = i * B;
		buckets[i].r = (i+1) * B - 1;
		// others fields are zeros
	}
	dp[0] = 1;
	buckets[0].rebuild();

	for (int i = 0; i < n; ++ i) {
		vector<int>& vec = posOfVal[a[i]];
		if (vec.size() >= 2) {
			update(vec.end()[-2], vec.back(), -1);
		}
		vec.push_back(i);
		update(vec.end()[-2], vec.back(), +1);

		dp[i + 1] = get(k);
		buckets[(i+1)/B].rebuild();
	}

	printf("%d", dp[n]);
}