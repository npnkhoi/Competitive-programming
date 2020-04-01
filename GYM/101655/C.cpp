#include <bits/stdc++.h>
using namespace std;

const int N = 40320 + 5;

map<vector<int>, int> id;
vector<int> a, b;
double f1[N], f2[N]; 
int n, tc;

int main() {
	// freopen("C.inp", "r", stdin);
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		a.resize(n);
		b.resize(n);
		for (int i = 0; i < n; ++ i) {
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b.begin(), b.end());
		int m = -1;
		do {
			id[b] = ++ m;

			if (m == 0) continue;

			double tmp, uncha;

			tmp = 0; uncha = 0;
			for (int i = 0; i < n; ++ i) {
				for (int j = 0; j < n; ++ j) {
					if (b[min(i, j)] > b[max(i, j)]) {
						swap(b[i], b[j]);
						tmp += f1[id[b]];
						swap(b[i], b[j]);
					} else {
						// cerr << i << " " << j << "\n";
						uncha ++;
					}
				}
			}
			// cerr << tmp << " " << uncha << "\n";
			f1[m] = (n*n + tmp) / (n * n - uncha);

			tmp = 0; uncha = 0;
			for (int i = 0; i + 1 < n; ++ i) {
				if (b[i] > b[i + 1]) {
					swap(b[i], b[i + 1]);
					tmp += f2[id[b]];
					swap(b[i], b[i + 1]);
				} else {
					uncha ++;
				}
			}
			// cerr << tmp << "fff " << uncha << "\n";
			f2[m] = (n - 1 + tmp) / (n - 1 - uncha);

			if (m == id[a]) break;

		} while (next_permutation(b.begin(), b.end()));

		printf("Monty %.6f Carlos %.6f\n", f1[id[a]], f2[id[a]]);
	}
}