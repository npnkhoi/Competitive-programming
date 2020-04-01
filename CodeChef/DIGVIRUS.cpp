#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int oo = 1e9 + 7;

int n, dist[N];
queue<int> q;
char s[N];

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc --) {
		scanf("%s", s);
		n = strlen(s);
		for (int i = 0)
		// int maxVal = 0;
		// for (int i = 0; i < n; ++ i) {
		// 	maxVal = max(maxVal, s[i] - '0');
		// }
		// for (int i = 0; i < n; ++ i) {
		// 	if (s[i] - '0' == maxVal) {
		// 		q.push(i);
		// 		dist[i] = 0;
		// 	} else {
		// 		dist[i] = oo;
		// 	}
		// }
		// int res = -1;
		// while (!q.empty()) {
		// 	res ++;
		// 	int sz = q.size(); 
		// 	while (sz --) {
		// 		int u = q.front();
		// 		cerr << "-- from " << u << "\n";
		// 		q.pop();
		// 		for (int v = u - 1; v >= min(0, u - maxVal); -- v) {
		// 			if (abs(u - v) <= maxVal - s[v] + '0' && dist[v] == oo) {
		// 				dist[v] = dist[u] + 1;
		// 				q.push(v);
		// 				cerr << "to " << v << "\n";
		// 			} else break;
		// 		}
		// 		for (int v = u + 1; v <= max(n - 1, u + maxVal); ++ v) {
		// 			if (abs(u - v) <= maxVal - s[v] + '0' && dist[v] == oo) {
		// 				dist[v] = dist[u] + 1;
		// 				q.push(v);
		// 				cerr << "to " << v << "\n";
		// 			} else break;
		// 		}
		// 	}
		// }
		// cerr << "done\n";
		printf("%d\n", res);
	}
}