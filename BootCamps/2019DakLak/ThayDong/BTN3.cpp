#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "BTN3"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
const int BASE = 10000;
typedef vector <int> BigInt;
BigInt Init(string s) {
    BigInt a; if (s.size() == 0) { a.push_back(0); return a; }
    while (s.size() % 4 != 0) s = '0' + s;
    for (int i = 0; i < (int)s.size(); i += 4) {
        int value = 0;
        for (int j = 0; j < 4; j++)
            value = value * 10 + (s[i + j] - '0');
        a.insert(a.begin(), value);
    } return a;
}
void Print(const BigInt a) {
    if (a.empty()) printf("0\n");
    else {
        int L = a.size(); printf("%d", a[L - 1]);
        for (int i = L - 2; i >= 0; i--) printf("%04d", a[i]);
        printf("\n");
    }

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
BigInt operator * (const int mul, const BigInt a) {
    BigInt c; int carry = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        carry += a[i] * mul; c.push_back(carry % BASE); carry /= BASE;
    }
    if (carry) c.push_back(carry); return c;
}
BigInt operator * (const BigInt a, const BigInt b) {
    BigInt c(a.size() + b.size() + 5, 0);
    for (int i = 0; i < (int)a.size(); i++) {
        int carry = 0;
        for (int j = 0; j < (int)b.size(); j++) {
            int k = i + j; c[k] += a[i] * b[j] + carry;
            carry = c[k] / BASE; c[k] %= BASE;
        }
        if (carry) c[i + b.size()] += carry;
    }
    while (*c.rbegin() == 0 && c.size() > 1) c.pop_back(); return c;
}

const int N = 205;
const int K = 7;
const char bra[] = {'(', ')', '[', ']', '{', '}'};
char str[N];
int n, k;
vi f[N][K][250];

int match(char a, char b) {
    if (a == '?' && b == '?') return 3;
    if (a == '(' && b == ')') return 1;
    if (a == '(' && b == '?') return 1;
    if (a == '?' && b == ')') return 1;
    if (a == '[' && b == ']') return 1;
    if (a == '?' && b == ']') return 1;
    if (a == '[' && b == '?') return 1;
    if (a == '{' && b == '}') return 1;
    if (a == '{' && b == '?') return 1;
    if (a == '?' && b == '}') return 1;
    return 0;
}
int len(int mask) {
    if (mask == 0) return 0;
    else return 1 + len(mask / 3);
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &k);
    scanf("%s", str + 1);

    int ultMask = 1;
    FOR(i, 1, k) ultMask *= 3;

    vi one; one.assign(1, 1);
    f[n+1][0][0] = one;
    FORD(i, n, 1) {
        int ultMask = 1;
        FOR(l, 0, k) {
            REP(mask, ultMask) {
                REP(nxt, 6) {
                    if (nxt % 2) {
                        if (l > 0 && mask % 3 * 2 == nxt - 1) {
                            f[i][l][mask] = f[i][l][mask] + f[i+1][l-1][mask/3];
                            //cout << "add " << i+1 << " " << l-1 << " " << mask/3 << "\n";
                        }
                    } else {
                        if (l < k) {
                            f[i][l][mask] = f[i][l][mask] + f[i+1][l+1][3*mask + nxt / 2];
                            //cout << "add2 " << i+1 << " " << l+1 << " " << 3*mask+nxt/2 << "\n";
                            //Print(f[i+1][l+1][3*mask + nxt / 2]);
                        }

                    }
                    //cout << i << " " << l << " " << mask << " ", Print(f[i][l][mask]);
                }
                //cerr << i << " " << l << " " << mask << " "; Print(f[i][l][mask]);
                //cerr << "\n";
                //cout << "------------\n";
            }
            ultMask *= 3;
        }
    }

    //Print(f[1][0]);
    int l = 0, mask = 0;
    vi res = one;
    FOR(i, 1, n) {
        REP(j, 6)
        if (bra[j] == str[i]) {
            if (j % 2) l--, mask /= 3;
            else l++, mask = mask * 3 + j / 2;
        } else {
            if (j % 2) {
                if (mask % 3 * 2 == j - 1) res = res + f[i+1][l-1][mask/3];
            } else {
                if (l < k) res = res + f[i+1][l+1][mask * 3 + j / 2];
            }
        }
    }
    Print(res);
}
