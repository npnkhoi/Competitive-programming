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

#define task "msis"

const int N = 1e6 + 5;
int n, m, a[N], pos[N], trace[N];
ll IT[4*N], memo[N], res;
vi data;
map<int, int> id;
vector<int> ans;

ll query(int p, int l, int r, int L, int R) {
    //printf("query %d %d\n", L, R);
    if (l > r || L > R || l > R || L > r) return -1;
    if (L <= l && r <= R) return IT[p];
    int mi = (l+r)/2;
    ll x = query(2*p, l, mi, L, R);
    ll y = query(2*p+1, mi+1, r, L, R);
    return max(x, y);
}
void update(int p, int l, int r, int idx, ll val) {
    //printf("update %d %d %d\n", l, r, idx);
    if (l > r || l > idx || idx > r) return;
    if (l == idx && idx == r) IT[p] = max(IT[p], val);
    else {
        int mi = (l+r)/2;
        update(2*p, l, mi, idx, val);
        update(2*p+1, mi+1, r, idx, val);
        IT[p] = max(IT[2*p], IT[2*p+1]);
    }
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        data.pb(a[i]);
    }
    sort(data.begin(), data.end());
    REP(i, n)
        if (i == 0 || data[i] != data[i-1])
        id[data[i]] = ++ m;
    FOR(i, 1, n) pos[i] = id[a[i]];

    FOR(i, 1, n) {
        ll tmp;
        if (pos[i] > 1) {
            tmp = query(1, 1, m, 1, pos[i] - 1);
        }
        else {
            tmp = 0;
        }
        memo[i] = tmp + a[i];
        res = max(res, memo[i]);
        update(1, 1, m, pos[i], memo[i]);
    }
    //cerr << res << "\n";
    int val = (int)1e9 + 7;
    FORD(i, n, 1) {
        if (memo[i] == res && a[i] < val) {
            res -= a[i];
            val = a[i];
            ans.push_back(i);
            if (res == 0) break;
        }
    }
    printf("%d\n", (int)ans.size());
    FORD(i, ans.size() - 1, 0) printf("%d ", ans[i]);
}
/** Happy Coding :D */
