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

#define task "szero"

map<ll, int> pos;
int n, val, res, lo, hi;
long long sum;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    pos[0] = 0;
    FOR(i, 1, n) {
        scanf("%d", &val);
        sum += val;
        if (pos.find(sum) == pos.end())
            pos[sum] = i;
        else {
            int tmp = i - pos[sum];
            if (tmp > res) {
                res = tmp;
                hi = i;
            }
        }
    }
    lo = hi - res + 1;
    printf("%d %d", lo, hi);
}
/** Happy Coding :D */
