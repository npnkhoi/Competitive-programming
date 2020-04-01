#include <bits/stdc++.h>
using namespace std;

struct Point{
	int x, y;
	Point() {x = y = 0;}
	Point(int x, int y): x(x), y(y) {}
};

const int N = 1500 + 5;

int n;
Point a[N];
vector<pair<int, int> > data1, data2;
long long res;

int nextIndex(int i, vector<pair<int, int> > &v) {
	int j = i;
	while (j + 1 < v.size() && v[j] == v[j + 1]) {
		++ j;
	}
	return j + 1;
} 

int main() {
	freopen("RTRIANGLE.inp", "r", stdin);
	freopen("RTRIANGLE.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	if (n < 3) {
		printf("0\n");
		exit(0);
	}
	for (int i = 1; i <= n; ++i) {
		data1.clear();
		data2.clear();
		int cntVer = 0, cntHor = 0;
		for (int j = 1; j <= n; ++j) {
			if (j != i) {
				int u = a[j]. y - a[i].y, v = a[j].x - a[i].x;
				if (u == 0) {
					res += cntVer;
					cntHor ++;
				} else if (v == 0) {
					res += cntHor;
					cntVer ++;
				} else {
					int tmp = __gcd(abs(u), abs(v));
					u /= tmp;
					v /= tmp;
					if (v < 0) {
						u = -u;
						v = -v;
					}
					if (u < 0) {
						data2.push_back(make_pair(v, -u));
					} else {
						data1.push_back(make_pair(u, v));
					}
				}
			}
		}
		if (data1.empty() || data2.empty()) {
			continue;
		}
		sort(data1.begin(), data1.end());
		sort(data2.begin(), data2.end());

		int j = 0, k = 0;
		for (int j = 0; j < data1.size(); j = nextIndex(j, data1)) {
			while (data2[k] < data1[j] && k < data2.size()) {
				k = nextIndex(k, data2);
			} 
			if (k == data2.size()) break;
			if (data1[j] == data2[k]) {
				res += (nextIndex(j, data1) - j) * (nextIndex(k, data2) - k);
			}
		}
	} 
	printf("%lld", res);
}