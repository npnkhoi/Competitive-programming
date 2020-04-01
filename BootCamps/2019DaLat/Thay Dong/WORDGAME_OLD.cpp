#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 7;
const int N = 105;
const int L = 55;

struct Pack {
	int dist, tail, ml, mr;
	Pack() { }
	Pack(int a, int b, int c, int d): dist(a), tail(b), ml(c), mr(d) {}
};

bool operator > (const Pack a, const Pack b) {
	return a.dist > b.dist;
}

string str, s[N], cur;
int n, res, len;
int rev[N], pal[N];
priority_queue<Pack, vector<Pack>, greater<Pack> > heap;
int dist[N][L][L];

bool contain(string &s, string &t) {
	int j = 0;
	for (int i = 0; i < t.size(); ++ i, ++ j) {
		while (t[i] != s[j] && j < s.size()) ++j;
		if (j >= s.size()) return 0;
	}
	return 1;
}

bool palin(string cur) {
	int sz = cur.size();
	for (int i = 0; i < sz / 2; ++ i) {
		if (cur[i] != cur[sz - i - 1]) return 0;
	}
	return 1;
}

void answer() {
	if (res == oo) printf("-1");
	else printf("%d\n", res);
	exit(0);
}

void TLE() {
	if ((double) clock() / 1000 >= 0.92) {
		answer();
	}
}

void brute(int i) {
	// cerr << cur << "\n";
	TLE();
	if (cur.size() >= res) return;
	if (contain(cur, str) && palin(cur)) {
		// cerr << cur << "\n";
		res = min(res, (int) cur.size());
		return;
	}
	if (i > 20) return; /// unsure bound

	for (int j = 1; j <= n; ++ j) {
		if (!cur.empty() && s[j][0] != cur.back()) continue;
		cur += s[j];
		brute(i + 1);
		cur.resize(cur.size() - s[j].size());
	}
}

void sub1() {
	res = oo;
	cur = "";
	// random_shuffle(s + 1, s + n + 1);
	brute(1);
	answer();
}

bool equalSize() {
	for (int i = 2; i <= n; ++i) 
		if (s[i].size() != s[1].size()) return 0;
	return 1;
}

void init() {
	for (int i = 1; i <= n; ++ i) {
		if (rev[i]) continue;
		if (palin(s[i])) {
			rev[i] = 1;
			pal[i] = 1;
		}
		for (int j = i + 1; j <= n; ++ j) {
			if (palin(s[i] + s[j])) {
				rev[i] = 1;
				rev[j] = 1;
			}
		}
	}	
}

bool match(int i, int j) {
	if (i == 0) return 1;
	return (s[j][0] == s[j].back() && s[j].back() == s[i][0]);
}

int nxtMatchLeft(int ml, int i) {
	for (int j = 0; j < s[i].size(); ++ j) {
		if (str[ml] == s[i][j]) {
			ml ++;
		}
	}
	return ml;
}

int nxtMatchRight(int mr, int i) {
	for (int j = s[i].size() - 1; j >= 0; -- j) {
		if (str[len - 1 - mr] == s[i][j]) {
			mr ++;
		}
	}
	return mr;
}

void sub2() {
	// cerr << "sub2\n";
	init();
	// cerr << "done init\n";
	for (int i = 0; i <= n; ++ i) {
		for (int ml = 0; ml <= len; ++ ml) {
			for (int mr = 0; mr <= len; ++ mr) {
				// cerr << i << " " << ml << " " << mr << "\n";
				dist[i][ml][mr] = oo;
			}
		}
	}
	res = oo;
	heap.push(Pack(0, 0, 0, 0));
	dist[0][0][0] = 0;
	// cerr << "done prepare\n";
	while (!heap.empty()) {
		Pack t = heap.top(); heap.pop();

		// cerr << t.dist << " " << t.tail << " " << t.ml << " " << t.mr << "\n";

		if (t.dist != dist[t.tail][t.ml][t.mr]) continue;
		for (int i = 1; i <= n; ++ i) {
			// cerr << "add " << i << "?\n";
			if (!rev[i] || !match(t.tail, i)) continue;
			// cerr << "pass condition 1\n";
			int nxt_ml = nxtMatchLeft(t.ml, i);
			if  (nxt_ml + t.mr >= len) {
				res = min(res, t.dist + (int) s[i].size());
				continue;
			}
			// cerr << "pass condition 2\n";
			int nxt_mr = nxtMatchRight(t.mr, i);
			if (nxt_ml + nxt_mr >= len) {
				res = min(res, t.dist + 2 * (int) s[i].size());
				continue;
			}
			// cerr << "pass condition 3\n";
			// cerr << "ml mr: " << nxt_ml << " " << nxt_mr << "\n";
			if (t.dist + 2 * (int) s[i].size() < dist[i][nxt_ml][nxt_mr]) {
				dist[i][nxt_ml][nxt_mr] = t.dist + 2 * (int) s[i].size();
				heap.push(Pack(dist[i][nxt_ml][nxt_mr], i, nxt_ml, nxt_mr)); 
			}
		}
	}
	printf("%d\n", res);
}

void sub3() {

}

int main() {
	freopen("WORDGAME.inp", "r", stdin);
	freopen("WORDGAME.out", "w", stdout);
	// cerr << contain("ababbaba", "abcba") << "\n";
	getline(cin, str);
	len = str.size();
	scanf("%d ", &n);
	for (int i = 1; i <= n; ++ i) {
		getline(cin, s[i]);
	}
	// if (n <= 3) sub1();
	// else if (equalSize()) sub2();
	// else sub3();
	if (equalSize()) sub2();
	else sub1();
}