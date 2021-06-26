#include <bits/stdc++.h>
using namespace std;

const int N = 200;
const int V = 6 * N + 1;

typedef pair<pair<int, int>, int> Pick;

int a[V], f[V][V], parent[V], num_child[V];
pair<int, int> trace[V][V];
vector<Pick> pick;
queue<int> potential_pick[2];

void saveTrace(int l, int r, int mid, int type) {
	f[l][r] = 1;
	trace[l][r] = {mid, type};
}

void tracing(int l, int r, int par) {
	if (l - r == 1) return;
	// printf("tracing %d %d\n", l, r);
	if (r - l == 2) {
		pick.push_back({{l, l+1}, r});
		parent[pick.size()] = par;
		// printf("%d %d %d\n", l, l+1, r);
		// val[eval(l, r)] = {l, {l+1, r}};
		return;
	} 
	int mid = trace[l][r].first;
	if (trace[l][r].second == 0) {
		// adj[eval(l, r)].push_back(eval(l, mid));
		// adj[eval(l, r)].push_back(eval(mid+1, r));
		tracing(l, mid, par);
		tracing(mid+1, r, par);
	} else {
		pick.push_back({{l, mid}, r});
		int new_par = pick.size();
		parent[pick.size()] = par;
		tracing(l + 1, mid - 1, new_par);
		tracing(mid + 1, r - 1, new_par);
		// adj[eval(l, r)].push_back(eval(l+1, mid-1));
		// adj[eval(l, r)].push_back(eval(mid+1, r-1));
		// printf("%d %d %d\n", l, mid, r);
		// val[eval(l, r)] = {l, {mid, r}};
	}
}

int get_val(int pick_id) {
	return a[pick[pick_id - 1].second];	
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 3*n; ++ i) {
		int x;
		cin >> x;
		a[x] = 1;
	}

	for (int i = 0; i <= 6*n; ++ i) {
		f[i+1][i] = 1;
	}

	for (int r = 3; r <= 6*n; ++ r) {
		if (a[r-2] == a[r-1] && a[r-1] == a[r])
			f[r-2][r] = 1;

		for (int l = r-5; l >= 1; l -= 3) {
			for (int mid = l + 2; mid < r; mid += 3) {
				if (f[l][mid] & f[mid+1][r]) {
					saveTrace(l, r, mid, 0);
					// f[l][r] |= (f[l][mid] & f[mid+1][r]);
				}
			}
			if (a[l] == a[r] && !f[l][r]) {
				for (int mid = l+3; mid < r; mid++) {
					if (a[mid] != a[l]) continue;
					if (f[l + 1][mid - 1] & f[mid + 1][r - 1]) {
						saveTrace(l, r, mid, 1);
						// f[l][r] |= (f[l + 1][mid - 1] & f[mid + 1][r - 1]);
					}
						
				}
			}
			// cout << l << ' ' << r << '\n';
			// if (f[l][r]) {
			// 	cout << l << ' ' << r << '\n';
			// }
		}
	}
	// cout << f[1][6*n];
	tracing(1, 6*n, -1);

	// cerr << "done tracing\n";

	int n_v = 2 * n;

	for (int i = 1; i <= n_v; ++ i) {
		// printf("pick content: %d %d %d -- parent: %d\n", 
		// 	pick[i-1].first.first, pick[i-1].first.second, pick[i-1].second, parent[i]);
		if (parent[i] == -1) continue;
		num_child[parent[i]] ++;
		// cerr << "done\n";
	}
	for (int u = 1; u <= n_v; ++ u) {
		if (num_child[u] == 0) {
			potential_pick[get_val(u)].push(u);
		}
	}
	for (int i = 1; i <= n_v; ++ i) {
		int turn = i & 1;
		int id = potential_pick[turn].front();
		potential_pick[turn].pop();
		Pick this_pick = pick[id-1];
		printf("%d %d %d\n", this_pick.first.first, this_pick.first.second,this_pick.second);
		num_child[parent[id]] --;
		if (num_child[parent[id]] == 0) {
			potential_pick[get_val(parent[id])].push(parent[id]);
		}
	}
}