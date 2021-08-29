#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "SC2"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int MAX_DIG = 17;
int tc;
ll n, f[MAX_DIG][MAX_DIG][MAX_DIG];
string s;

int cnt(ll n, int dig) {
    int res = 0;
    while (n > 0) {
        res += (n % 10 == dig);
        n /= 10;
    }
    return res;
}
void sub1() {
    int res = 0;
    FOR(i, 1, n)
        if (cnt(i, 4) % 4 == 0 && cnt(i, 7) % 7 == 0) res ++;
    printf("%d\n", res);
}
void sub2() {
    s.clear();
    int l = 0;
    while (n > 0) {
        s = (char) (n % 10 + '0') + s;
        n /= 10;
        l ++;
    }
    int curx = 0, cury = 0;
    memset(f, 0, sizeof f);
    FOR(i, 1, l) {
        FOR(k, 0, s[i-1] - 1 - '0') f[i][curx + (k == 4)][cury + (k == 7)] ++;
        if (s[i] == '4') curx ++;
        else if (s[i] == '7') cury ++;

        FOR(k, 0, 9) {
            FOR(x, (k == 4), i) {
                FOR(y, (k == 7), i) {
                    f[i][x][y] += f[i-1][x - (k == 4)][y - (k == 7)];
                }
            }
        }
    }
    ll res = 0;
    FOR(x, 0, l) FOR(y, 0, l) if (x % 4 == 0 && y % 7 == 0) res += f[l][x][y];
    printf("%lld\n", res);
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d", &tc);
    REP(khue, tc) {
        scanf("%lld", &n);
        /*if (n <= 2e6) sub1();
        else sub2();*/
        sub1();
    }
}
