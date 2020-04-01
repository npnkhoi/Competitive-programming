using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 2005;
const int MASK = 35;
int n, a[N], f[N][MASK];
set<int> data;
map<int, int> cnt;
ii b[N];
bool check(int x) {
    if (data.find(x - 1) != data.end()) return 0;
    if (data.find(x - 8) != data.end()) return 0;
    if (data.find(x - 9) != data.end()) return 0;
    if (data.find(x + 1) != data.end()) return 0;
    if (data.find(x + 8) != data.end()) return 0;
    if (data.find(x + 9) != data.end()) return 0;
    return 1;
}
void sub1() {
    int res = n;
    FOR(mask, 1, (1<<n) - 1) {
        data.clear();
        int ans = n - __builtin_popcount(mask);
        REP(i, n)
        if ((mask & (1 << i)) > 0)
        if (check(a[i])) data.insert(a[i]);
        else { ans = n; break; }
        res = min(res, ans);
    }
    printf("%d", res);
}
int main() {
    freopen("0.inp", "r", stdin);
    freopen("0.ans", "w", stdout);
    scanf("%d", &n);
    REP(i, n) scanf("%d", &a[i]);
    sub1();
    return 0;
}
/** Happy Coding ^^ */
