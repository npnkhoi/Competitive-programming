#include <bits/stdc++.h>
using namespace std;

const int N = 52;
const int oo = 1e9 + 7;

char s[N], t[N];
int n, c[N][N], matchL[N], matchR[N], trace[N];
int last, pushInQueue, res;
queue<int> q;

bool findAugment(int s) {
	while (!q.empty()) q.pop();
	memset(trace, 0, sizeof trace);
	q.push(s);
	pushInQueue = 0;
	while (!q.empty()) {
		// cerr << s << q.size() << "\n";
		int u = q.front(); q.pop();
		// cerr << "pop\n";
		for (int v = 1; v <= n; ++ v) {
			if (c[u][v] == 0 && trace[v] == 0) {
				trace[v] = u;
				pushInQueue ++;
				if (matchR[v] == 0) {
					last = v;
					return true;
				}
				q.push(matchR[v]);
				// cerr << v << " pushed \n";
			}
		}
	}
	// cerr << "end augment\n";
	return false;
}

void changeGraph(int s) {
	// cerr << "change graph\n";
	int delta = oo;
	// for (int i = 1; i <= n; ++ i) {
	// 	cerr << trace[i] << " ";
	// }
	// cerr << "\n";
	for (int i = 1; i <= n; ++ i) if (i == s || (matchL[i] && trace[matchL[i]])) {
		for (int j = 1; j <= n; ++ j) if (!trace[j]) {
			delta = min(delta, c[i][j]);
		}
	}
	// cerr << "delta " << delta << "\n";
	for (int i = 1; i <= n; ++ i) if (i == s || (matchL[i] && trace[matchL[i]])) {
		res += delta;
		for (int v = 1; v <= n; ++ v) {
			c[i][v] -= delta;
		}
	}
	for (int i = 1; i <= n; ++ i) if (trace[i]) {
		res -= delta;
		for (int j = 1; j <= n; ++ j)
			c[j][i] += delta;
	}
	// for (int i = 1; i <= n; ++ i) {
	// 	for (int j = 1; j <= n; ++ j) {
	// 		cerr << c[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }
}

void enLarge() {
	int u = last;
	while (1) {
		int nxt = matchL[trace[u]];
		matchL[trace[u]] = u;
		matchR[u] = trace[u];
		if (nxt == 0) break;
		u = nxt;
	}
}

void hungarian() {
	// memset matchL, matchR
	for (int i = 1; i <= n; ++ i) {
		while (!findAugment(i)) changeGraph(i);
		// cerr << "last = " << last << "\n";
		enLarge();
	}
}

int main() {
	freopen("ANAGRAMS.inp", "r", stdin);
	freopen("ANAGRAMS.out", "w", stdout);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			c[i][j] = t[j] - s[i];
			if (c[i][j] < 0) c[i][j] += 26;
			// cerr << c[i][j] << " ";
		}
		// cerr << "\n";
	}
	hungarian();
	printf("%d", res);
}