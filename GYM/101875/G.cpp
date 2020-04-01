#include <bits/stdc++.h>
using namespace std;

struct Line {
	double a, b;
};

const int N = 1e5 + 5;

int n, pre[N], del[N];
Line line[N];
stack<int> st;

bool cmp(Line u, Line v) {
	return u.b < v.b;
}

double timeInter(Line u, Line v) {
	if (u.a == v.a) return -1;
	else return (double) - (u.b - v.b) / (u.a - v.a);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lf%lf", &line[i].b, &line[i].a);
	}
	sort(line + 1, line + n + 1, cmp);
	st.push(1);
	pre[1] = 0;
	for (int i = 2; i <= n; ++i) {
		while (!st.empty() && timeInter(line[i], line[st.top()]) > 0) {
			int u = st.top();
			del[u] = 1;
			st.pop();
			while (pre[u] != 0) {
				int v = pre[u];
				if (timeInter(line[i], line[v]) >= timeInter(line[i], line[u])) {
					u = v;
					del[u] = 1;
				} else break;
			}
			pre[i] = u;
			// cerr << "pre " << i << " " << u << "\n";
		} 
		st.push(i);
	}
	double res = 0;
	for (int i = 1; i <= n; ++i) {
		if (del[i] == 0 && pre[i] != 0) {
			res = max(res, timeInter(line[i], line[pre[i]]));
		}
	}
	printf("%.10lf", res);
}