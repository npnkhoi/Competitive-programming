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

const int N = 3e5 + 5;
const int Q = 5e4 + 5;
int n, m, x, cnt, curL, curR, block;
vi fact[N];
int a[N], ans[N], f[N];
map<int, int> id;
vector<int> v;
int minfact[(int)1e7 + 5];
bool mark[N];

void sieve() {
    FOR(i, 2, 1e7) if (minfact[i] == 0) {
        minfact[i] = i;
        for (ll j = 1LL * i * i; j <= 1e7; j += i)
        if (minfact[j] == 0) minfact[j] = i;
    }
}
struct query{
    int l, r, id;
} q[Q];
bool cmp_query(query a, query b) {
    if (a.l / block != b.l / block) return a.l < b.l;
    else return a.r < b.r;
}
void add(int i) {
    if (a[i] == 0) return;
    if (f[a[i]] == 0) cnt ++;
    f[a[i]] ++;
}
void del(int i) {
    if (a[i] == 0) return;
    f[a[i]] --;
    if (f[a[i]] == 0) cnt --;
}
int main() {
    sieve();
    scanf("%d%d", &n, &m);
    block = (int) sqrt(n);
    FOR(i, 1, n) {
        scanf("%d", &x);
        if (x == 0) a[i] = 0;
        else if (x < 0) a[i] = -1;
        else a[i] = 1;

        while (x > 1) {
            int tmp = minfact[x], cnt = 0;
            while (minfact[x] == tmp) {
                cnt ++;
                x /= tmp;
            }
            if (cnt % 2) a[i] *= tmp;
        }
        v.pb(a[i]);
    }

    int rr = 0;
    sort(v.begin(), v.end());
    REP(i, v.size()) if (i == 0 || v[i] != v[i-1]) id[v[i]] = ++ rr;
    FOR(i, 1, n) a[i] = id[a[i]];


    FOR(i, 1, m) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q + 1, q + m + 1, cmp_query);
    curL = 1; curR = 0;
    FOR(i, 1, m) {
        //cerr << q[i].l << " " << q[i].r << "\n";
        while (curL < q[i].l) del(curL++);
        while (curL > q[i].l) add(--curL);
        while (curR < q[i].r) add(++curR);
        while (curR > q[i].r) del(curR--);
        ans[q[i].id] = max(cnt, 1);
    }
    FOR(i, 1, m) printf("%d\n", ans[i]);
}
