#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int diff[N], z[N], len_diff;


void Z_fn(int s[], int z[], int n) {
    z[0] = 0;
    int l = 0, r = 0;

    for (int i = 1; i < n; ++ i) {
        z[i] = 0;
        if (i <= r) z[i] = min(z[i-l], r-i+1);
        while (i+z[i] < n && (s[i+z[i]] == s[z[i]] || s[i+z[i]] == -1 || s[z[i]] == -1))
            ++ z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

bool is_len_key(int len_key) {
	for (int pos = len_key; pos < len_diff; pos += len_key) {
		if (z[pos] != len_diff - pos)
			return false;
	}
	return true;
}

int minmove(string &s) {
    int n = s.length();
    int x, y, i, j, u, v; // x is the smallest string before string y
    for (x = 0, y = 1; y < n; ++ y) {
        i = u = x;
        j = v = y;
        while (s[i] == s[j]) {
            ++ u; ++ v;
            if (++ i == n) i = 0;
            if (++ j == n) j = 0;
            if (i == x) break; // All strings are equal
        }
        if (s[i] <= s[j]) y = v;
        else {
            x = y;
            if (u > y) y = u;
        }
    }
    return x;
}

void local() {
	// for (char c = 'a'; c <= 'z'; ++ c) {
	// 	cerr << c << ' ' << int(c) << '\n'; 
	// }
	// cerr << minmove("eappl");
	freopen("F.inp", "r", stdin); cerr << "DONT INPUT FROM FILE!\n";
}

int main() {
	// local();
	string a, b, line;
	int len;
	cin >> len;
	while (getline(cin, line)) {
		if (a.size() < len) {
			a += line;
		} else {
			b += line;
		}
	}
	// cerr << a << '\n' << b << '\n';
	len_diff = 0;
	for (int i = 0; i < len; ++ i) {
		if (isalpha(a[i])) {
			diff[len_diff] = b[i] - a[i];
			if (diff[len_diff] <= 0) diff[len_diff] += 26;
			len_diff ++;
		}
		// cerr << diff[len_diff - 1] << ' ';
	}
	// cerr << '\n';
	Z_fn(diff, z, len_diff);
	// for (int i = 0; i < len_diff; ++ i) {
	// 	cerr << z[i] << ' ';
	// }

	// shortest length, NlogN
	int len_key = 1;
	while (!is_len_key(len_key) && len_key < len_diff) {
		len_key ++;
	}
	// find minimum rotation
	string key = "";
	for (int i = 0; i < len_key; ++ i) {
		key += char(diff[i] + 'a' - 1);
	}
	int start_pos = minmove(key);
	for (int i = 0; i < len_key; ++ i) {
		int real_pos = start_pos + i;
		if (real_pos >= len_key) real_pos -= len_key;
		cout << key[real_pos];
	}
}