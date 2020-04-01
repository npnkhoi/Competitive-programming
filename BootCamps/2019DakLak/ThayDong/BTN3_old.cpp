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
char str1[N], str2[N];
int n, k;
vi s[N][N][K];
stack<char> st;

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
vi calc(int flag) {
    FOR(x, 1, k) {
        FOR(r, 1, n) {
            FORD(l, r, 1) {
                s[l][r][x] = match(str2[l], str2[r]) * s[l+1][r-1][x-1];
                FOR(mid, l+1, r-2) {
                    s[l][r][x] = s[l][r][x] + match(str2[l], str2[mid]) * s[l+1][mid-1][x-1] * s[mid+1][r][x];
                }
            }
        }
    }
    return s[1][n][k];
}
void preCalc() {
    FOR(x, 1, k) {
        FOR(r, 1, n) {
            FORD(l, r, 1) {
                s[l][r][x] = match(str2[l], str2[r]) * s[l+1][r-1][x-1];
                FOR(mid, l+1, r-2) {
                    s[l][r][x] = s[l][r][x] + match(str2[l], str2[mid]) * s[l+1][mid-1][x-1] * s[mid+1][r][x];
                }
            }
        }
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d%d", &n, &k);
    scanf("%s", str1 + 1);
    //cerr << "ok\n";
    FOR(i, 1, n+1) FOR(x, 0, k) s[i][i-1][x].assign(1, 1);

    FOR(i, 1, n) str2[i] = '?';

    preCalc();
    vi res; res.assign(1, 1);
    FOR(i, 1, n) {
        REP(z, 6) {
            str2[i] = bra[z];
            if (str2[i] == str1[i]) break;
            else res = res + calc(i);
            //cerr << calc(str2) << "\n";
        }
    }
    Print(res);
}
