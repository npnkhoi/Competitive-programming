#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n, idx;
string s;
vi seq[30];

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

void goNext(int &i, vi &v) {
	int tmp = v[i];
	while (i < v.size() && v[i] == tmp) ++ i;
}

vi operator + (vi a, vi b) {
	vi res;
	// for (int i = 0, j = 0; i < a.size() || j < b.size();) {
	// 	if (j == b.size()) res.push_back(a[i ++]);
	// 	else if (i == a.size()) res.push_back(b[j ++]);
	// 	else {
	// 		if (a[i] < b[j]) res.push_back(a[i ++]);
	// 		else res.push_back(b[j ++]);
	// 	}
	// }
	int i = 0, j = 0;
	while (i < a.size() || j < b.size()) {
		if (i == a.size()) {
			res.push_back(b[j]);
			goNext(j, b);
		} else if (j == b.size()) {
			res.push_back(a[i]);
			goNext(i, a);
		} else {
			if (a[i] < b[j]) {
				res.push_back(a[i]);
				goNext(i, a);
			} else if (a[i] > b[j]) {
				res.push_back(b[j]);
				goNext(j, b);
			} else {
				res.push_back(b[j]);
				goNext(j, b);
				goNext(i, a);
			}
		}
	}
	return res;
}

void show(vi &a) {
	cerr << "vector: ";
	for (int v : a) cerr << v << " ";
	cerr << "\n";
}

vi operator * (vi a, vi b) {
	vi res;
	// cerr << "mul\n";
	// show(a); show(b);
	int i = 0, j = 0;
	while (i < a.size() && j < b.size()) {
		if (a[i] < b[j]) goNext(i, a);
		else if (a[i] > b[j]) goNext(j, b);
		else {
			res.push_back(a[i]);
			goNext(i, a);
			goNext(j, b);
		}
	}
	return res;
}

vi ans() {
	// trả về vector chứa kết quả của dấu ngoặc bắt đầu tại idx
	// int save = idx;
	vector<vi> tmp;
	char oper = '.';
	while (1) {
		++ idx;
		if (isalpha(s[idx])) {
			if (oper == '*') tmp.back() = tmp.back() * seq[s[idx] - 'A'];
			else tmp.push_back(seq[s[idx] - 'A']);
		} else if (s[idx] == '(') {
			if (oper == '*') tmp.back() = tmp.back() * ans();
			else tmp.push_back(ans());
		} else if (s[idx] == ')') {
			break;
		} else oper = s[idx];
	}
	// cerr << "at " << save << ": (" << tmp.size() << "): "; 
	for (int i = 1; i < tmp.size(); ++ i) tmp[0] = tmp[0] + tmp[i];
	// for (int v : tmp[0]) cerr << v << " "; cerr << "\n";
	return tmp[0];
}

int main() {
	char name;
	int x, y, z;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		getAlpha(name);
		name -= 'A';
		getInt(x); getInt(y); getInt(z);
		for (int i = x; i <= y; i += z) {
			seq[name].push_back(i);
		}
	}
	getline(cin, s);
	s = '(' + s + ')';
	// cerr << s << "\n";
	idx = 0;
	vi res = ans();
	printf("%d\n", res.size());
	for (int v : res) printf("%d ", v);
}