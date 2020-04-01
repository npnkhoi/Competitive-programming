// Problem: Thang Bom
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

struct Point{
	long long x, y;
	// Point() {
	// 	x = y = 0;
	// }
	// Point(long long _x, long long _y) {
	// 	x = _x;
	// 	y = _y;
	// }
};

Point p[N];
deque<int> verQueue, horQueue;
int id[N], mark[N];

int n, mostL, mostR, mostU, mostD;
char query[N];
int nxtL[N], nxtR[N], ord[N];
long long area, ans[N];

long long ccw(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
}

bool cmpx(int i, int j) {
	return p[i].x < p[j].x;
}

bool cmpy(int i, int j) {
	return p[i].y < p[j].y;
}

void findOrder() {
	// find the removing order
	for (int i = 1; i <= n; ++ i) {
		id[i] = i;
	}
	sort(id + 1, id + n + 1, cmpx);
	for (int i = 1; i <= n; ++ i) {
		horQueue.push_back(id[i]);
	}
	sort(id + 1, id + n + 1, cmpy);
	for (int i = 1; i <= n; ++ i) {
		verQueue.push_front(id[i]);
	}
	scanf("%s", query + 1);
	for (int i = 1; i <= n - 2; ++ i) {
		if (query[i] == 'U') {
			while (mark[verQueue.front()]) {
				verQueue.pop_front();
			}
			int u = verQueue.front();
			verQueue.pop_front();
			mark[u] = 1;
			ord[i] = u;
		} else if (query[i] == 'D') {
			while (mark[verQueue.back()]) {
				verQueue.pop_back();
			}
			int u = verQueue.back();
			verQueue.pop_back();
			mark[u] = 1;
			ord[i] = u;
		} else if (query[i] == 'L') {
			while (mark[horQueue.front()]) {
				horQueue.pop_front();
			}
			int u = horQueue.front();
			horQueue.pop_front();
			mark[u] = 1;
			ord[i] = u;
		} else {
			while (mark[horQueue.back()]) {
				horQueue.pop_back();
			}
			int u = horQueue.back();
			horQueue.pop_back();
			mark[u] = 1;
			ord[i] = u;
		}
 	}
 	// cerr << "order: \n";
 	// for (int i = 1; i <= n - 2; ++ i) {
 	// 	cerr << ord[i] << " ";
 	// }
 	// cerr << "\n";
}

long long triArea(Point a, Point b, Point c) {
	return abs(	a.x * b.y - a.y * b.x +
				b.x * c.y - b.y * c.x +
				c.x * a.y - c.y * a.x);
}

void removePoint(int x) {
	// cerr << "remove " << x << "\n";
	nxtL[nxtR[x]] = nxtL[x];
	nxtR[nxtL[x]] = nxtR[x];
	area -= triArea(p[x], p[nxtL[x]], p[nxtR[x]]);
}

void calcAreas() {
	int cur, l, r;
	for (int i = n - 2; i >= 1; -- i) {
		cur = ord[i];
		// if (i == n - 2) {
		// 	l = mostU;
		// 	r = nxtR[mostU];
		// 	if (ccw(p[l], p[r], p[cur]) < 0) {
		// 		swap(l, r);
		// 	}
		// } else if (query[i] == 'U') {
		// 	l = r = mostU;
		// 	if (p[mostU].x < p[cur].x) {
		// 		r = nxtR[r];
		// 	} else {
		// 		l = nxtL[l];
		// 	}
		// } else if (query[i] == 'D') {
		// 	l = r = mostD;
		// 	if (p[mostD].x > p[cur].x) {
		// 		r = nxtR[r];
		// 	} else {
		// 		l = nxtL[l];
		// 	}
		// } else if (query[i] == 'L') {
		// 	l = r = mostL;
		// 	if (p[mostL].y < p[cur].y) {
		// 		r = nxtR[r];
		// 	} else {
		// 		l = nxtL[l];
		// 	}
		// } else {
		// 	l = r = mostR;
		// 	if (p[mostR].y > p[cur].y) {
		// 		r = nxtR[r];
		// 	} else {
		// 		l = nxtL[l];
		// 	}
		// }

		int tmp;
		if (query[i] == 'U') {
			tmp = mostU;
		} else if (query[i] == 'D') {
			tmp = mostD;
		} else if (query[i] == 'L') {
			tmp = mostL;
		} else {
			tmp = mostR;
		}
		if (ccw(p[tmp], p[nxtR[tmp]], p[cur]) >= 0) {
			l = tmp;
			r = nxtR[tmp];
		} else {
			r = tmp;
			l = nxtL[tmp];
		}

		if (p[cur].x < p[mostL].x) mostL = cur;
		if (p[cur].x > p[mostR].x) mostR = cur;
		if (p[cur].y < p[mostD].y) mostD = cur;
		if (p[cur].y > p[mostU].y) mostU = cur;

		// cerr << query[i] << "\n";
		// cerr << p[cur].x << " " << p[cur].y << "\n";
		// cerr << p[l].x << " " << p[l].y << "\n";
		// cerr << p[r].x << " " << p[r].y << "\n";
		// cerr << "move l\n";
		while (ccw(p[nxtL[l]], p[l], p[cur]) >= 0) {
			// cerr << "remove l\n";
			removePoint(l);
			l = nxtL[l];
		}
		// cerr << "done l\n";
		// cerr << "move r\n";
		while (ccw(p[nxtR[r]], p[r], p[cur]) <= 0) {
			removePoint(r);
			r = nxtR[r];
		}
		// cerr << "done r\n";
		area += triArea(p[cur], p[l], p[r]);
		nxtL[cur] = l, nxtR[cur] = r;
		nxtR[l] = cur, nxtL[r] = cur;

		ans[i] = area;
		// cerr << area << "\n";
	}
}

int main() {
	// freopen("BL.inp", "r", stdin);
	// freopen("BL.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%lld%lld", &p[i].x, &p[i].y);
	}

	findOrder();

	int u = -1, v = -1;
	for (int i = 1; i <= n; ++ i) {
		if (mark[i] == 0) {
			if (u == -1) u = i;
			else v = i;
		}
	}

	nxtL[u] = v; nxtL[v] = u;
	nxtR[u] = v; nxtR[v] = u;

	if (p[u].x > p[v].x) swap(u, v);
	mostL = u; mostR = v;

	if (p[u].y < p[v].y) swap(u, v);
	mostU = u; mostD = v;

	// cerr << u << v << "\n";
	// cerr << "start calc\n";
	calcAreas();

	for (int i = 1; i <= n - 2; ++ i) {
		printf("%lld.%d\n", ans[i] / 2, (ans[i] % 2 ? 5 : 0));
	}
}