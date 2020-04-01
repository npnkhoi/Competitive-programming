#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct Pole {
	int type, x, h;
	Pole(): type(0), x(0), h(0) {}
	Pole(int type, int x, int h): type(type), x(x), h(h) {}
};

Pole a[N];
int n, d;
double shadeL[N], shadeR[N];

void sub1() {
	for (int i = 1; i <= n + 1; ++ i) {
		shadeL[i] = a[i-1].x;
	}
	for (int i = 0; i <= n; ++ i) {
		shadeR[i] = a[i+1].x;
	}
	// for (int j = 1; j <= n; ++j) cerr << shadeL[j] << " " << shadeR[j] << "\n";
	// 	cerr << "\n";
	for (int i = 1; i <= n; ++ i) if (a[i].type) {
		shadeL[i] = shadeR[i] = a[i].x;
		for (int j = i + 1; j <= n; ++ j) {
			if (a[j].h >= a[i].h) break;
			shadeR[j] = min(shadeR[j], a[j].x + (double) (a[j].x - a[i].x) / ((double) a[i].h / a[j].h - 1));
		}
		for (int j = i - 1; j >= 1; --j) {
			if (a[j].h >= a[i].h) break;
			shadeL[j] = max(shadeL[j], a[j].x - (double) (a[i].x - a[j].x) / ((double) a[i].h / a[j].h - 1));
		}
		// for (int j = 1; j <= n; ++j) cerr << shadeL[j] << " " << shadeR[j] << "\n";
		// cerr << "\n";
	}
	double res = 0;
	for (int i = 0; i <= n; ++ i) {
		// cerr << shadeL[i] << " " << shadeR[i] << "\n";
		res += min((double) a[i+1].x - a[i].x, a[i+1].x - shadeR[i] + shadeL[i+1] - a[i].x);
	}
	printf("%.3lf", res);
}

void sub2() {
	for (int i = 1; i <= n + 1; ++ i) {
		shadeL[i] = a[i-1].x;
	}
	for (int i = 0; i <= n; ++ i) {
		shadeR[i] = a[i+1].x;
	}
	double maxH = 0;
	for (int i = 1; i <= n; ++ i) if (a[i].type) {
		shadeL[i] = shadeR[i] = a[i].x;
		for (int j = i + 1; j <= n; ++ j) {
			if (a[j].h >= a[i].h) break;
			shadeR[j] = min(shadeR[j], a[j].x + (double) (a[j].x - a[i].x) / ((double) a[i].h / a[j].h - 1));
		}
		for (int j = i - 1; j >= 1; --j) {
			if (a[j].h >= a[i].h) break;
			shadeL[j] = max(shadeL[j], a[j].x - (double) (a[i].x - a[j].x) / ((double) a[i].h / a[j].h - 1));
		}
		// for (int j = 1; j <= n; ++j) cerr << shadeL[j] << " " << shadeR[j] << "\n";
		// cerr << "\n";
	}
	double res = 0;
	for (int i = 0; i <= n; ++ i) {
		// cerr << shadeL[i] << " " << shadeR[i] << "\n";
		res += min((double) a[i+1].x - a[i].x, a[i+1].x - shadeR[i] + shadeL[i+1] - a[i].x);
	}
	printf("%.3lf", res);
}


int main() {
	// freopen()
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d%d", &a[i].type, &a[i].x, &a[i].h);
	}
	a[0].x = 0;
	a[n+1].x = d;
	if (n <= 5000) sub1();
	else sub2();
}