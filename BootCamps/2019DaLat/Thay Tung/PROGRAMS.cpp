#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct Pack {
	int x, type, id;
	Pack() {}
	Pack(int a, int b, int c): x(a), type(b), id(c) {}
};

int n;
vector<Pack> v;
set<int> cur;
int exist[N];
vector<int> ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		int l, r;
		scanf("%d%d", &l, &r);
		v.push_back(Pack(l, 0, i));
		v.push_back(Pack(r, 1, i));
	}
	sort(v.begin(), v.end(), [](Pack a, Pack b) {
		if (a.x != b.x) return a.x > b.x;
		else if (a.type != b.type) return a.type < b.type;
	});
	for (Pack p : v) {
		// cerr << p.x << " " << p.type << " " << p.id << "\n";
		if (p.type == 0) {
			cur.erase(p.id);
		} else {
			if (cur.empty()) {
				exist[p.id] = 1;
			} else if (p.id > *cur.rbegin()) {
				// cerr << "del " << *cur.begin() << "to add " << p.id << "\n";
				exist[*cur.rbegin()] = 0;
				exist[p.id] = 1;
			}
			cur.insert(p.id);
		}
	}	
	for (int i = 1; i <= n; ++ i) {
		if (exist[i]) ans.push_back(i);
	}
	printf("%d\n", ans.size());
	for (int x : ans) printf("%d ", x);
}