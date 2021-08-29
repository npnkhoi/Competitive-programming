#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

long long a[55];
int n, pos, res;
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &n);
    pos = 1;
    FOR(i, 1, n) {
        scanf("%lld", &a[i]);
        if (a[i] > a[pos]) pos = i;
    }
    while (a[pos] >= n) {
        res ++;
        a[pos] -= n;
        FOR(i, 1, n) if (i != pos) a[i] ++;
        FOR(i, 1, n) if (a[i] > a[pos]) pos = i;
    }
    printf("%d", res);
}
/// Expelliarmus !
