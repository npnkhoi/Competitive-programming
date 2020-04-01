#include <bits/stdc++.h>
using namespace std;

struct Pack {
	int sum, minL, posL, minR, posR;
};

struct Node {
	int l, r;
	Pack inf;
	Node() {}
};

void combine(Pack a, Pack b, Pack &res) {
	res.sum = a.sum + b.sum;
	if (a.minL <= a.sum + b.minL) {
		res.minL = a.minL;
		res.posL = a.posL;
	} else {
		res.minL = a.sum + b.minL;
		res.posL = b.posL;
	}
	if (b.minR <= b.sum + a.minR) {
		res.minR = b.minR;
		res.posR = b.posR;
	} else {
		res.minR = b.sum + a.minR;
		res.posR = a.posR;
	}
}

void show(Pack a) {
	cerr << a.sum << " " << a.minL << " " << a.posL << " " << a.minR << " " << a.posR << "\n";
}

struct SegmentTree {
	vector<Node> IT;

	void build(int p, int u, int v, int a[]) {
		IT[p].l = u;
		IT[p].r = v;
		if (u == v) {
			IT[p].inf.sum = a[u];
			if (a[u] > 0) {
				IT[p].inf.minL = IT[p].inf.minR = 0;
				IT[p].inf.posL = u - 1;
				IT[p].inf.posR = u + 1;
			} else {
				IT[p].inf.minL = IT[p].inf.minR = -1;
				IT[p].inf.posL = IT[p].inf.posR = u;
			}
		} else {
			int mid = (u + v) / 2;
			build(2 * p, u, mid, a);
			build(2 * p + 1, mid + 1, v, a);
			combine(IT[2*p].inf, IT[2*p+1].inf, IT[p].inf);
		}
		cerr << "build " << p << " " << u << " " << v << "\n";
		show(IT[p].inf);
	}

	Pack get(int p, int l, int r) {
		// cerr << "get " << IT[p].l << " " << IT[p].r << " " << l << " " << r << "\n";
		// musn't go to outside node
		if (l <= IT[p].l && IT[p].r <= r) {
			return IT[p].inf;
		}
		if (r < IT[2*p + 1].l) return get(2 * p, l, r);
		else if (IT[2*p].r < l) return get(2 * p + 1, l, r);
		else {
			Pack res;
			combine(get(2*p, l, r), get(2*p+1, l, r), res);
			return res;
		}
	}

	SegmentTree (int n, int a[]) {
		IT.resize(4*n+1);
		build(1, 1, n, a);
	}
};

const int N = 5e5 + 5;

int n, q, a[N], cnt[N], s[N];
char ch;


int main() {
	freopen("GENETECH.inp", "r", stdin);
	freopen("GENETECH.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf(" %c", &ch);
		a[i] = (ch == 'C' ? 1 : -1);
		s[i] = s[i-1] + a[i];
		cnt[i] = cnt[i - 1] + (ch == 'T');
	}
	for(int i = 1; i <= n; ++ i) cerr << a[i] << " "; cerr << "\n";
	SegmentTree IT(n, a);

	scanf("%d", &q);
	while (q --) {
		int l, r;
		scanf("%d%d", &l, &r);
		Pack tmp = IT.get(1, l, r);
		// cerr << "done\n";
		show(tmp);
		// tmp.minL -= s[l - 1];
		// tmp.minR -= (s[n] - s[r]);
		show(tmp);
		int x = abs(tmp.minL), y = abs(tmp.minR);
		int res = x + y - min(cnt[tmp.posL] - cnt[tmp.posR - 1], min(x, y));
		printf("%d\n", res);
	}
}