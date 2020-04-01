#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define REP(i,n) for (int i = 0; i < n; ++i)

#define taskname "minsum"

long long a, b, s, x, y, res;
bool cp(long long x) {
    return (ll)sqrt(x) * (ll) sqrt(x) == x;
}

int main() {
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".ans", "w", stdout);
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        res = (long long) 1e18;
        scanf("%lld%lld", &a, &b);
        s = a * b;
        FOR(i, 1, 10000) FOR(j, 1, 10000)
        if (s % (i * j) == 0 && cp(s / (i * j)) && i + j < res) {
            res = i + j;
            x = i;
            y = j;
        }
        if (x > y) swap(x, y);
        printf("%lld %lld\n", x, y);
    }
}
