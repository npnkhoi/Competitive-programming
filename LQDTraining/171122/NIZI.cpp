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
const int N = 1e6 + 5;
ll a[N];
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("NIZI.inp", "r", stdin);
    freopen("NIZI.out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    int n;
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%lld", &a[i]);
        //a[i] += a[i-1];
    }
    //printf("%d\n", ans(1, n));
    int l = 1, r = n;
    int res = 0;
    while (l < r) {
        if (a[l] == a[r]) ++ l, -- r;
        else {
            res ++;
            if (a[l] < a[r]) {
                a[l+1] += a[l];
                ++ l;
            } else {
                a[r-1] += a[r];
                -- r;
            }
        }
    }
    printf("%d", res);
    return 0;
}
/** Happy Coding :D */
