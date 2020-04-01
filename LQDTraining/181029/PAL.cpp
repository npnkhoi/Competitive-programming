#include <bits/stdc++.h>
using namespace std;

const int BASE = 10000;
typedef vector <int> BigInt;

BigInt operator + (const BigInt a, const BigInt b) {
    BigInt c; int carry = 0;
    for (int i = 0; i < (int)a.size() || i < (int)b.size(); i++) {
        if (i < (int)a.size()) carry += a[i];
        if (i < (int)b.size()) carry += b[i];
        c.push_back(carry % BASE); carry /= BASE;
    }
    if (carry) c.push_back(carry); return c;
}

BigInt operator - (const BigInt a, const BigInt b) {
    BigInt c; int carry = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        int s = a[i] - carry;
        if (i < (int)b.size()) s -= b[i];
        if (s < 0) s += BASE, carry = 1; else carry = 0;
        c.push_back(s);
    }
    while (*c.rbegin() == 0 && c.size() > 1) c.pop_back(); return c;
}

void Print(const BigInt a) {
    int L = a.size(); printf("%d", a[L - 1]);
    for (int i = L - 2; i >= 0; i--) printf("%04d", a[i]);
    printf("\n");
}

const int N = 125;

char s[N];
int n;
BigInt f[N][N], res;

int main() {
	freopen("PAL.inp", "r", stdin);
	freopen("PAL.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	BigInt ONE; ONE.push_back(1);
	BigInt ZERO; ZERO.push_back(0);
	for (int i = 1; i <= n; ++ i) f[i][i] = ONE;
	for (int i = 1; i <= n + 1; ++ i) f[i][i-1] = ZERO; 

	for (int j = 1; j <= n; ++j) {
		for (int i = j-1; i >= 1; --i) {
			if (s[i] == s[j]) f[i][j] = f[i][j-1] + f[i+1][j] + ONE;
			else f[i][j] = f[i][j-1] + f[i+1][j] - f[i+1][j-1];
			// cerr << i << " " << j << " ";
			// Print(f[i][j]);
		}
	}
	Print(f[1][n]);
}