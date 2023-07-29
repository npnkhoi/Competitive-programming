#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;

struct Pack {
	int x, l, r, type;
	Pack(int x_, int l_, int r_, int type_) {
		x = x_;
		l = l_;
		r = r_;
		type = type_;
	}
};

int n;
int x1[N], x2[N], y1_[N], y2[N], ft[2 * N];
vector<Pack> segment;
vector<int> num_x, num_y;

// Fenwick tree - Binary Indexed Tree
void update(int i, int val, int n) {
	for (; i <= n; i += i & (-i)) {
		ft[i] += val;
	}
}

int get(int i) {
	if (i <= 0) return 0;
	int ret = 0;
	for (; i; i -= i & -i) {
		ret += ft[i];
	}
	return ret;
}

int get(int l, int r) {
	return get(r) - get(l - 1);
}
// end of Fenwick

void compress(vector<int> &v) {
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
}

int pos(vector<int> &v, int x) {
	return upper_bound(v.begin(), v.end(), x) - v.begin();
}

void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d%d%d%d", &x1[i], &y1_[i], &x2[i], &y2[i]);
		num_x.push_back(x1[i]);
		num_x.push_back(x2[i]);
		num_y.push_back(y1_[i]);
		num_y.push_back(y2[i]);
	}
}

void init() {
	compress(num_x);
	compress(num_y);
	// for (int x : num_x) cerr << x << ' '; cerr << '\n';
	// for (int x : num_y) cerr << x << ' '; cerr << '\n';

	for (int i = 0; i < n; ++ i) {
		x1[i] = pos(num_x, x1[i]);
		x2[i] = pos(num_x, x2[i]);
		y1_[i] = pos(num_y, y1_[i]);
		y2[i] = pos(num_y, y2[i]);
		segment.push_back(Pack(x1[i], y1_[i], y2[i], 0));
		segment.push_back(Pack(x2[i] + 1, y1_[i], y2[i], 1));
	}
	sort(segment.begin(), segment.end(), [](Pack a, Pack b) {
		if (a.x != b.x) return a.x < b.x;
		else return a.type > b.type;
	});
}

int solve() {
	for (auto seg : segment) {
		if (seg.type == 1) {
			update(seg.l, -1, 2 * n);
			update(seg.r, -1, 2 * n);
			if (get(seg.l, seg.r) != 0) {
				return 1;
			}
		} else {
			update(seg.l, +1, 2 * n);
			update(seg.r, +1, 2 * n);
		}
	}
	return 0;
}

int main() {
	input();
	init();
	printf("%d\n", solve());
}