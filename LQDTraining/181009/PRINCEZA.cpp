#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define task "PRINCEZA"
const int N = 1e5 + 5;

int n, k;
char jumps[N];
pair<int, int> a[N];
map<int, int> id1, id2; 
vector<int> diag1[N], diag2[N];
int nxt[N][4];

bool cmp(int i, int j) {
	return a[i] < a[j];
}

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d%d", &n, &k);
	scanf("%s", jumps);
	id2.clear();
	int size1 = 0, size2 = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d", &a[i].fi, &a[i].se);
		int tmp;
		
		tmp = a[i].fi - a[i].se;
		if (id1[tmp] == 0) {
			id1[tmp] = ++ size1;
		}
		diag1[id1[tmp]].push_back(i);

		tmp = a[i].fi + a[i].se;
		if (id2[tmp] == 0) {
			id2[tmp] = ++ size2;
		}
		diag2[id2[tmp]].push_back(i);
	}
	for (int i = 1; i <= size1; ++ i) {
		sort(diag1[i].begin(), diag1[i].end(), cmp);
		for (int j = 0; j < diag1[i].size() - 1; ++ j) {
			nxt[diag1[i][j]][0] = diag1[i][j + 1];
			nxt[diag1[i][j + 1]][3] = diag1[i][j];
		}
	}
	for (int i = 1; i <= size2; ++ i) {
		sort(diag2[i].begin(), diag2[i].end(), cmp);
		for (int j = 0; j < diag2[i].size() - 1; ++ j) {
			nxt[diag2[i][j]][1] = diag2[i][j + 1];
			nxt[diag2[i][j + 1]][2] = diag2[i][j];
		}
	}
	int p = 1;
	for (int i = 0; i < k; ++ i) {
		int dir = jumps[i] - 'A';
		if (nxt[p][dir] != 0) {
			for (int j = 0; j < 4; ++ j) {
				if (nxt[p][j] != 0) nxt[nxt[p][j]][3 - j] = nxt[p][3 - j];
			}
			p = nxt[p][dir];
		}
	}
	printf("%d %d\n", a[p].fi, a[p].se);
}