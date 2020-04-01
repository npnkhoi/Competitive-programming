#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "L"

queue<ll> q;
ll L, R;

bool checkPrime(ll val) {
    if (val == 0 || val == 1) return 0;
    if (val%2 == 0) return val == 2;
    if (val%3 == 0) return val == 3;
    for (ll x = 5; x*x <= val; ) {
        if (val % x == 0) return 0;
        x += 2; if (x*x > val) break;
        if (val % x == 0) return 0;
        x += 4;
    }
    return 1;
}
void solve() {
    ll LT = 1, res = 0;
    q.push(0);

    FOR(love, 1, 11) {
        int siz = q.size();
        while (siz --) {
            ll val = q.front(); q.pop();
            FOR(i, 1, 9) {

                ll newVal = i * LT + val;
                if (checkPrime(newVal)) {
                    q.push(newVal);
                    res += (L <= newVal && newVal <= R);
                }
            }
        }
        LT *= 10;
    }
    printf("%d", res);
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%lld%lld", &L, &R);
    solve();
}
/** Happy Coding :D */
