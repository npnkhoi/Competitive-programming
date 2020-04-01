#include <bits/stdc++.h>
using namespace std;

const long long oo = 1e18 + 7;
const int N = 55;

typedef long long Mat[51][51];

int n, m, k;
Mat d0, d1, f, maxEdge;
vector<int> bits;

void add(const Mat &a, const Mat &b, Mat &c) {
	// a != c, b != c
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			c[i][j] = oo;
			for (int k = 1; k <= n; ++ k) {
				c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
			}
		}
	}
}

void Copy(const Mat &a, Mat &b) {
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			b[i][j] = a[i][j];
		}
	}
}

void show(Mat a) {
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			cerr << a[i][j] << " ";
		}
		cerr << '\n';
	}
	cerr << "\n";
}

int main() {
	// freopen("MAZE.inp", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			if (i == j) continue;
			d0[i][j] = oo;
			maxEdge[i][j] = -oo;
		}
	}
	for (int i = 1; i <= m; ++ i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		maxEdge[u][v] = max(maxEdge[u][v], 1LL * c);
		d0[u][v] = min(d0[u][v], 1LL * c);
	}
	scanf("%d", &k);

	// Floyd - calculate d0[][]
	for (int z = 1; z <= n; ++ z) {
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				d0[i][j] = min(d0[i][j], d0[i][z] + d0[z][j]);
			}
		}
	}

	// calculate d1
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			d1[i][j] = d0[i][j];			
			for (int u = 1; u <= n; ++ u) {
				for (int v = 1; v <= n; ++ v) {
					d1[i][j] = min(d1[i][j], d0[i][u] - maxEdge[u][v] + d0[v][j]);
					// cerr << i << " " << j << " " << u << " " << v << " " << d1[i][j] << "\n";
				}
			}
		}
	}
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			f[i][j] = d0[i][j];
		}
	}
	// show(d0);
	// show(d1);
	// show(f);

	// calculate f
	while (k) {
		bits.push_back(k % 2);
		k /= 2;
	}
	Mat tmp;
	for (int i = bits.size() - 1; i >= 0; --i) {
		// cerr << "bit: " << bits[i] << "\n";
		add(f, f, tmp);
		if (bits[i]) add(tmp, d1, f);
		else Copy(tmp, f);
	}
	printf("%lld", f[1][n]);
}