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
const int N = 1e5 + 5;
int a[N];
int n, q;

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    scanf("%d%d", &n, &q);
    FOR(i, 1, n) scanf("%d", &a[i]);
    while (q--) {
        int res = -1;
        int x, l, r;
        scanf("%d%d%d", &x, &l, &r);
        FOR(i, l, r) if (__gcd(a[i], x) > 1) res = max(res, a[i]);
        if (res == -1) printf("-1 -1\n");
        else {
            int cnt = 0;
            FOR(i, l, r) if (a[i] == res) cnt ++;
            printf("%d %d\n", res, cnt);
        }
    }
    return 0;
}
/** Happy Coding :D */
