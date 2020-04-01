using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

//ifstream inp(".inp");
//ofstream out(".out");
const int N = 3e5 + 5;
int a[N], s[N];
int main() {
    freopen("TRUMPET.inp", "r", stdin);
    freopen("TRUMPET.out", "w", stdout);
    int n, d;
    scanf("%d%d", &n, &d);
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];
    }
    int l = 1, r;
    int res = 0;
    while (1) {
        if (n - l <= d) break;
        else {
            r = l + d;
            if (s[r] - s[l]> 0) {
                FORD(k, r, l) if (a[k] == 1) {
                    l = k;
                    break;
                }
            } else ++ res, l = r;
        }
    }
    printf("%d\n", res);
    return 0;
}
/** Happy Coding :D */
