#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
//typedef pair<int, int> ii;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task "pbcpoint"

const int MAX_X = 2000;
const int sh = 1000;
int n;
int l[MAX_X + 5], r[MAX_X + 5];
int minL1[MAX_X + 5], minL2[MAX_X + 5], maxR1[MAX_X + 5], maxR2[MAX_X + 5];
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    FOR(i, 0, MAX_X) l[i] = MAX_X + 1, r[i] = -1;
    scanf("%d", &n);
    FOR(i, 1, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        x += sh; y += sh;
        l[x] = min(l[x], y);
        r[x] = max(r[x], y);
    }
    //FOR(i, 0, MAX_X) cerr << l[i] << " " << r[i] << "\n";
    minL1[0] = l[0];
    maxR1[0] = r[0];
    FOR(i, 1, MAX_X) {
        minL1[i] = min(minL1[i-1], l[i]);
        maxR1[i] = max(maxR1[i-1], r[i]);
    }
    minL2[MAX_X] = l[MAX_X];
    maxR2[MAX_X] = r[MAX_X];
    FORD(i, MAX_X - 1, 0) {
        minL2[i] = min(minL2[i+1], l[i]);
        maxR2[i] = max(maxR2[i+1], r[i]);
    }
    //FOR(i, 0, MAX_X) printf("%d %d, %d %d\n", minL1[i], minL2[i], maxR1[i], maxR2[i]);
    int res = 0;
    FOR(i, 0, MAX_X) {
        l[i] = max(minL1[i], minL2[i]);
        r[i] = min(maxR1[i], maxR2[i]);
        //cerr << l[i] << " " << r[i] << "\n";
        if (l[i] <= r[i]) res += r[i] - l[i] + 1;
    }
    printf("%d", res);
}
/// Expelliarmus !
