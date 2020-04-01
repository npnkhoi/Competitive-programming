#include  <bits/stdc++.h>
using namespace std;

#define task "GRUEL"

const int MAX_TIME = 1e5;
const int N = 1e4 + 5;

struct Query{
	int id, spoonChange, chopChange;
	Query(int _id, int _spoonChange, int _chopChange): id(_id), spoonChange(_spoonChange), chopChange(_chopChange) {}
};

int spoon, chop, n, comeIn[N];
vector<Query> v[MAX_TIME + 5][2];

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d%d%d", &spoon, &chop, &n);
	for (int i = 1; i <= n; ++ i) {
		int t, len, dish;
		scanf("%d%d%d", &t, &len, &dish);
		if (dish == 0) {
			v[t][0].push_back(Query(i, -1, 0));
			v[t + len][1].push_back(Query(i, +1, 0));
		} else {
			v[t][0].push_back(Query(i, -1, -1));
			v[t + len][1].push_back(Query(i, +1, +1));
		}
	}
	for (int i = 1; i <= MAX_TIME; ++ i) {
		for (int j = 0; j < v[i][1].size(); ++ j) {
			Query t = v[i][1][j];
			if (comeIn[t.id]) {
				spoon += t.spoonChange;
				chop += t.chopChange;
			}
		}
		for (int j = 0; j < v[i][0].size(); ++ j) {
			Query t = v[i][0][j];
			if (spoon + t.spoonChange >= 0 && chop + t.chopChange >= 0) {
				spoon += t.spoonChange;
				chop += t.chopChange;
				comeIn[t.id] = 1;
			}
		}
	}
	for (int i = 1; i <= n; ++ i) {
		if (comeIn[i]) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
}