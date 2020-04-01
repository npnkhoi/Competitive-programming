#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n, idx;
char name[20];
int id[30];
string s;
vi seq[(1 << 16) + 5], res, tmp;

void getAlpha(char &ch) {
	do ch = getchar(); while (ch < 'A' || 'Z' < ch);
}

void getInt(int &x) {
	int c;
	do c = getchar(); while (c < '0' || '9' < c);
	x = c - '0';
	while (1) {
		c = getchar();
		if (c < '0' || '9' < c) break;
		x = 10 * x + c - '0';
	}
}

void add (vi &a, vi &b, vi &res) {
	res.clear();
	int i = 0, j = 0;
	while (i < a.size() || j < b.size()) {
		if (i == a.size()) {
			res.push_back(b[j]);
			++ j;
		} else if (j == b.size()) {
			res.push_back(a[i]);
			++ i;
		} else {
			if (a[i] < b[j]) {
				res.push_back(a[i]);
				++ i;
			} else if (a[i] > b[j]) {
				res.push_back(b[j]);
				++ j;
			} else {
				res.push_back(b[j]);
				++i; ++j;
			}
		}
	}
}

void mul (vi &a, vi &b, vi &res) {
	res.clear();
	int i = 0, j = 0;
	while (i < a.size() && j < b.size()) {
		if (a[i] < b[j]) ++i;
		else if (a[i] > b[j]) ++j;
		else {
			res.push_back(a[i]);
			++i; ++j;
		}
	}
}

void show(vi &a) {
	cerr << "vector: ";
	for (int v : a) cerr << v << " ";
	cerr << "\n";
}

int main() {
	int x, y, z;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		getAlpha(name[i]);
		id[name[i] - 'A'] = i;
		getInt(x); getInt(y); getInt(z);
		for (int j = x; j <= y; j += z) {
			seq[1 << i].push_back(j);
		}
	}

	for (int mask = 2; mask < (1 << n); ++mask) {
		if (__builtin_popcount(mask) < 2) continue;
		int lso = mask & -mask;
		mul(seq[mask ^ lso], seq[lso], seq[mask]);
	}

	getline(cin, s);
	s = '(' + s  + ')';
	cerr << s << "\n";
	stack<int> st;
	int mask = 0;
	st.push(0);
	for (char ch : s) {
		if (ch == '(') {
			st.push(mask);
		} else if (ch == ')' || ch == '+') {
			add(res, seq[mask], tmp);
			res = tmp;
			st.pop();
			mask = st.top();
		} else if (isalpha(ch)) {
			mask = mask | (1 << id[ch - 'A']);
			st.push(mask);
		}
		cerr << mask << "\n";
	}
	printf("%d\n", res.size());
	for (int x : res) printf("%d ", x);
}