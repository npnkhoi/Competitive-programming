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

const int N = 1e5 + 5;
int tc, n, q, d;
deque<int> dq;
ll res;
int a[N], f[N];
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &tc);
    REP(khue, tc) {
        scanf("%d%d%d", &n, &q, &d);
        while (!dq.empty()) dq.pop_back();
        FOR(i, 1, n) {
            scanf("%d", &a[i]);
            while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
            if (!dq.empty() && dq.front() <= i - d) dq.pop_front();
            dq.push_back(i);
            f[i] = a[dq.front()];
        }
        res = 0;
        while (q --) {
            int l, k;
            scanf("%d%d", &l, &k);
            if (k == d) res += f[l+d-1];
            //else res += +
        }
        printf("%lld\n", res);
    }
}
