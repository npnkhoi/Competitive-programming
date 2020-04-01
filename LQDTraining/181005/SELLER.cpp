#include <bits/stdc++.h>
using namespace std;

#define task "SELLER"

const int BASE = 10000;
typedef vector <int> BigInt;
void Print(const BigInt a) {
    int L = a.size(); printf("%d", a[L - 1]);
    for (int i = L - 2; i >= 0; i--) printf("%04d", a[i]);
    printf("\n");
}
BigInt operator + (const BigInt a, const BigInt b) {
    BigInt c; int carry = 0;
    for (int i = 0; i < (int)a.size() || i < (int)b.size(); i++) {
        if (i < (int)a.size()) carry += a[i];
        if (i < (int)b.size()) carry += b[i];
        c.push_back(carry % BASE); carry /= BASE;
    }
    if (carry) c.push_back(carry); return c;
}

const int N = 5000 + 5;
const int MAX_VAL = 5000;

int n;
pair<int, int> a[N];
int mark[N];
int pos[MAX_VAL + 5];
BigInt Exp[MAX_VAL + 5];

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	
	Exp[0] = vector<int> (1, 1);
	for (int i = 1; i <= MAX_VAL; ++ i) {
		Exp[i] = Exp[i - 1] + Exp[i - 1];
		Print(Exp[i]);
	}

	scanf("%d ", &n);
	char query[5];
	int val;
	for (int i = 1; i <= n; ++i) {
		scanf("%s %d", &query, &val);
		a[i] = make_pair(query[0] == 's', val);
		if (a[i].first == 1) {
			pos[val] = i;
		}
		// tmp = max(tmp, val);
	} 
	// cerr << tmp << "\n";
	BigInt res(1, 0);
	for (int val = MAX_VAL; val >= 0; -- val) {
		if (pos[val] != 0) {
			for (int i = pos[val]; i >= 1; --i) {
				if (mark[i]) break;

				if (a[i] == make_pair(0, val)) {
					for (int j = i; j <= pos[val]; ++ j) {
						mark[j] = 1;
					}
					res = res + Exp[val];
					break;
				}
			}
		}
	}
	Print(res);
}