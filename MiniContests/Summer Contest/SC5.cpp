#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "sc5"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;
const int A = 1e6 + 5;
int a[N], cnt[A];
int tmp, n, k, tc;
void add(int val) {
    //cerr << "add " << val << "\n";
    if (val <= k && cnt[val] == 0) tmp ++;
    cnt[val] ++;
    //REP(i, k+1) cerr << cnt[i] << " "; cerr << "\n";
}
void del(int val) {
    //cerr << "del " << val << "\n";
    if (val <= k && cnt[val] == 1) tmp --;
    cnt[val] --;
    //REP(i, k+1) cerr << cnt[i] << " "; cerr << "\n";
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &tc);
    REP(khue, tc) {
        scanf("%d%d", &n, &k);
        memset(cnt, 0, sizeof cnt);
        FOR(i, 1, n) scanf("%d", &a[i]);

        int l = 1;
        ll res = 1LL * n * (n+1) / 2;
        tmp = 0;

        FOR(r, 1, n) {
            add(a[r]);
            if (tmp == k + 1) {
                while (tmp == k + 1) {
                    del(a[l]);
                    l ++;
                    //cerr << "when l = " << l << " -> " << tmp << "\n";
                    //REP(i, k+1) cerr << cnt[i] << " "; cerr << "\n";
                }
                l--; add(a[l]);
                //cerr << r << " " << l << "\n";
                res -= l;
            }
        }
        printf("%lld\n", res);
    }
}
