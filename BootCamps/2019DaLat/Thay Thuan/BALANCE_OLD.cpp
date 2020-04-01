#include <bits/stdc++.h>
using namespace std;

const int N = 22;
const int MAX_M = 2e7;
const int sh = MAX_M + 1;

int n, m, a[N];
long long f[2][2 * MAX_M + 5];
queue<int> q;

int main() {
	freopen("BALANCE.inp", "r", stdin);
	freopen("BALANCE.out", "w", stdout);
	scanf("%d%d", &n, &m);

	int s = m;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		s += a[i];
	}

	s /= 2;

	// cerr << s << "\n";

	int cur = 0;
	f[0][sh] = 1;
	q.push(sh);

	for (int i = 1; i <= n; ++ i) {
		cur ^= 1;
		int sz = q.size();

		// cerr << sz << "\n";

		while (sz --) {
			int u = q.front();
			// cerr << u << " " << u - a[i] << " " << u + a[i] << "\n";
			q.pop();

			if (f[cur][u] == 0) {
				q.push(u);
				// cerr << u - sh << " ";
			}
			f[cur][u] += f[cur ^ 1][u];

			if (abs(u - sh - a[i]) <= s) {
				if (f[cur][u - a[i]] == 0) {
					q.push(u - a[i]);
					// cerr << u - a[i] - sh << " ";
				}
				f[cur][u - a[i]] += f[cur ^ 1][u];
			}


			if (abs(u - sh + a[i]) <= s) {
				if (f[cur][u + a[i]] == 0) {
					q.push(u + a[i]);
					// cerr << u + a[i] - sh << " ";
				}
				f[cur][u + a[i]] += f[cur ^ 1][u];
			}
			f[cur ^ 1][u] = 0;
		}
			// cerr << "\n";
		// for (int i = 0; i <= 21; ++ i) cerr << f[cur][i + sh] << " "; cerr << "\n";
	}
	printf("%lld", f[cur][sh + m]);
}