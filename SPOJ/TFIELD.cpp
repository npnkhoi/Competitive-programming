#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, n) for (int i = 0; i < n; i++)
const int N = 1005;
int m, k, n;
li a[N];
ii p[N];
ll res;
int main() {
    scanf("%d %d", &m, &k);
    REP(i, m) {
        scanf("%d %d", &n, &a[i].se);
        REP(j, n) scanf("%d %d", &p[j].fi, &p[j].se);
        //cerr << "ok\n";
        ll tmp = 0;
        REP(j, n) {
            int l = (j+1) % n;
            tmp += 1LL* p[j].fi * p[l].se - 1LL* p[j].se * p[l].fi;
        }
        a[i].fi = abs(tmp);
    }
    sort(a, a+m);
    FOR(color, 1, m) {
        int l = 0, cnt = 0;
        REP(r, m) {
            cnt += (a[r].se != color);
            while (cnt > k) cnt -= (a[l++].se != color);
            if (l == 0) res = max(res, a[r].fi);
            else res = max(res, a[r].fi - a[l-1].fi);
        }
    }
    printf("%lld.%lld", res/2, res%2*5);
}
