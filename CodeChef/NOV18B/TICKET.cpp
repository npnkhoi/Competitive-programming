#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct Pack {
	int x, type, id;
	Pack() {};
	Pack(int a, int b, int c): x(a), type(b), id(c) {}
};	

int n, s, q;
vector<Pack> v;
int num[N], ans[N];
set<int> book;

int main() {
	scanf("%d%d%d", &n, &s, &q);
	v.resize(2 * q);
	for (int i = 1; i <= q; ++ i) {
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		num[i] = k;
		v[2 * i - 2] = Pack(x, 0, i);
		v[2 * i - 1] = Pack(y, 1, i);
	}
	sort(v.begin(), v.end(), [](Pack a, Pack b) {
		if (a.x != b.x) return a.x < b.x;
		if (a.type != b.type) return a.type > b.type;
	});
	int cur = 0;	
	for (Pack p : v) {
		if (p.type == 0) {
			while (!book.empty()) {
				int tmp = *book.rbegin();
				if (tmp > p.id) {
					book.erase(tmp);
					cur -= num[tmp];
				} else break;
			}
			if (cur + num[p.id] <= s) {
				cur += num[p.id];
				book.insert(p.id);
			}
		} else {
			if (book.find(p.id) != book.end()) {
				cur -= num[p.id];
				book.erase(p.id);
				ans[p.id] = 1;
			}
		}
	}
	for (int i = 1; i <= q; ++ i) {
		printf("%d\n", ans[i]);
	}
}