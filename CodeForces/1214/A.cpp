#include <bits/stdc++.h>
using namespace std;

const vector<int> dollarBills = {1, 2, 5, 10, 20, 50, 100};
const vector<int> euroBills = {5, 10, 20, 50, 100, 200};

int n, d, e, res;
vector<int> dollarSets, euroSets;

void findSets(vector<int> bills, int lim, vector<int> &sets) {
	int n = bills.size();
	int f[n][lim + 1];
	memset(f, 0, sizeof f);
	f[0][0] = 1;
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j <= lim; ++ j) {
			if (f[i][j] == 0) continue;
			if (j + bills[i] <= lim) f[i][j + bills[i]] = 1;
			if (i < n - 1) f[i + 1][j] = 1;
		}
	}
	for (int j = 0; j <= lim; ++ j) 
		if (f[n - 1][j]) 
			sets.push_back(j);
}

int main() {
	scanf("%d%d%d", &n, &d, &e);

	findSets(dollarBills, n / d, dollarSets);
	findSets(euroBills, n / e, euroSets);

	// for (int x: dollarSets) cerr << x << ' '; cerr << '\n';
	// for (int x: euroSets) cerr << x << ' '; cerr << '\n';

	res = n;
	for (int x : dollarSets) {
		int rest = n - x * d;
		// cerr << "rest: " << rest << '\n';
		int idx = upper_bound(euroSets.begin(), euroSets.end(), rest / e) - euroSets.begin() - 1;
		// cerr << "idx: " << idx << '\n';
		if (idx >= 0) rest -= e * euroSets[idx];
		res = min(res, rest);
	}
	printf("%d", res);
}