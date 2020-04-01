#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<long long, long long> Point;

const int N = 2000;

int n;
Point a[N];
long long res;

long long area(Point A, Point B, Point C) {
	long long ans = 0;
	ans += A.X * B.Y - A.Y * B.X;
	ans += B.X * C.Y - B.Y * C.X;
	ans += C.X * A.Y - C.Y * A.X;
	return abs(ans);
}

int nxt(int x, int n) {
	if (x == n - 1) return 0;
	else return x + 1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++ i) {
		cin >> a[i].X >> a[i].Y;
	}
	for (int i = 0; i < n; ++ i) {
		int top = nxt(i, n);
		for (int j = nxt(i, n); j != i; j = nxt(j, n)) {
			while (area(a[i], a[j], a[top]) < area(a[i], a[j], a[nxt(top, n)])) {
				top = nxt(top, n);
			}
			res = max(res, area(a[i], a[j], a[top]));
		}
	}
	cout << res / 2 << '.' << res % 2 * 5;
}
