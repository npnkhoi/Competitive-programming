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
struct point{
    ll x, y;
    int id, p;
};
//ifstream inp(".inp");
//ofstream out(".out");
const int N = 1e5 + 5;
ll IT[4*N], lazy[8*N], ans[N];
point a[N];
int w, h, n, pos[N];

void lazyDown(int p, bool x) {
    IT[p] = max(IT[p], lazy[p]);
    if (x) {
        lazy[2*p] = max(lazy[2*p], lazy[p]);
        lazy[2*p+1] = max(lazy[2*p+1], lazy[p]);
    }
    lazy[p] = 0;
}
void update(int p, int l, int r, int L, int R, ll val) {
    lazyDown(p, l < r);
    //printf("update %d %d %d %lld\n", p, l, r, val);
    if (L > R || l > r || L > r || l > R) return;
    if (L <= l && r <= R) {
        IT[p] = max(IT[p], val);
        if (l < r) {
            lazy[2*p] = max(lazy[2*p], val);
            lazy[2*p+1] = max(lazy[2*p+1], val);
            //cerr << "ok lazy\n";
        }
    }
    else {
        int mi = (l+r)/2;
        update(2*p, l, mi, L, R, val);
        update(2*p+1, mi+1, r, L, R, val);
        IT[p] = max(IT[2*p], IT[2*p+1]);
    }
}
ll rmq(int p, int l, int r, int L, int R) {
    //printf("rmq %d %d %d %d %d\n", p, l, r, L, R);
    lazyDown(p, l < r);
    if (l > r || L > R || l > R || L > r) return -1;
    else if (L <= l && r <= R) return IT[p];
    else {
        int mi = (l+r)/2;
        ll ans1 = rmq(2*p, l, mi, L, R);
        ll ans2 = rmq(2*p+1, mi+1, r, L, R);
        if (ans1 == -1) return ans2;
        else if (ans2 == -1) return ans1;
        else return max(ans1, ans2);
    }
}
void preUpdate(ll lo, ll hi, ll x) {
    int l = lower_bound(pos+1, pos+n+1, lo) - pos;
    int r = upper_bound(pos+1, pos+n+1, hi) - pos - 1;
    if (l <= r) {
        update(1, 1, n, l, r, x);
    }
}
bool cmpy(point a, point b) {
    return a.y < b.y;
}
bool cmpx(point a, point b) {
    if (a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}
int main() {
    freopen("GARDEN.inp", "r", stdin);
    freopen("GARDEN.out", "w", stdout);
    scanf("%lld%lld%d", &w, &h, &n);
    FOR(i, 1, n) {
        scanf("%lld%lld", &a[i].x, &a[i].y);
        a[i].id = i;
    }
    sort(a+1, a+n+1, cmpy);
    FOR(i, 1, n) {
        a[i].p = i;
        pos[i] = a[i].y;
    }
    sort(a+1, a+n+1, cmpx);

    FOR(i, 1, n) {
        ll tmp = a[i].x - rmq(1, 1, n, a[i].p, a[i].p);
        ans[a[i].id] = 2 * tmp;
        preUpdate(a[i].y - tmp, a[i].y + tmp, a[i].x + tmp);
    }
    FOR(i, 1, n) printf("%lld\n", ans[i]);
    return 0;
}
/** Happy Coding :D */
