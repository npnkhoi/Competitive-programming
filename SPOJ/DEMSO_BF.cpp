#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "demso"
typedef long long ll;
//typedef pair<int, int> ii;
int a[20], A, B, d, k;
int ok(int val) {
    int n = 0, cnt = 0;
    while (val) {
        a[++ n] = val % 10;
        val /= 10;
    }
    FOR(i, 1, n-1) cnt += (abs(a[i] - a[i+1]) <= d);
    return cnt <= k;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    cin >> A >> B >> d >> k;
    int res = 0;
    FOR(i, A, B) res += ok(i);
    cout << res;
}
/// Expelliarmus !
