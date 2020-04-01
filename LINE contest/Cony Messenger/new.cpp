#include <bits/stdc++.h>
using namespace std;

typedef pair<unsigned long long, long long> HashType;

const int N = 1e4 + 5, BASE = 29, LEN = 105;
const long long md = 1e9 + 7;

int m, n;
string s;
HashType h[LEN], POW[LEN];
vector<HashType> v[LEN];

void init() {
	POW[0] = {1, 1};
	for (int i = 1; i < LEN; ++ i) {
		POW[i] = {
			POW[i-1].first * BASE,
			POW[i-1].second * BASE % md
		};
	}
}

HashType get(int l, int r) {
	if (l > r) return {0, 0};
	if (l == 0) return h[r];
	return {
		h[r].first - h[l-1].first * POW[r-l+1].first,
		(h[r].second - h[l-1].second * POW[r-l+1].second + md*md) % md
	};
}

void parse(string &s) {
	for (int i = 0; i < s.size(); ++ i) {
		if (s[i] <= 'Z') s[i] += 'a' - 'A';
	}
	h[0] = {s[0], s[0] % md};
	for (int i = 1; i < s.size(); ++i) {
		h[i] = {
			h[i-1].first * BASE + s[i],
			(h[i-1].second * BASE + s[i]) % md
		};
	}
}

int main() {
	init();
	cin >> m >> n;
	for (int i = 0; i < m; ++ i) {
		cin >> s;
		parse(s);
		// generate hash codes, store them
		for (int i = 0; i < s.size(); ++ i) {
			HashType le = get(0, i-1), ri = get(i+1, s.size()-1);
			v[i].push_back({
				le.first * POW[s.size()-i-1].first + ri.first,
				le.second * POW[s.size()-i-1].second + ri.second
			});
		}
	}

	for (int i = 0; i < LEN; ++ i)
		sort(v[i].begin(), v[i].end());

	for (int i = 0; i < n; ++i) {
		cin >> s;
		parse(s);
		bool ok = false;
		for (int i = 0; i < s.size(); ++ i) {
			HashType le = get(0, i-1), ri = get(i+1, s.size()-1);
			HashType hash = {
				le.first * POW[s.size()-i-1].first + ri.first,
				le.second * POW[s.size()-i-1].second + ri.second
			};
			if (binary_search(v[i].begin(), v[i].end(), hash)) {
				ok = true;
				break;
			}
			// cerr << hash.first << ", " << hash.second << '\n';
		}
		cout << (ok ? "CAN FIX\n" : "CAN NOT FIX\n");
	}
}