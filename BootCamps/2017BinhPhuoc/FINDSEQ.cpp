using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
const int N = 1e5 + 5;
const int oo = 1e9 + 7;
const int LOG = 20;
struct query {
    int l, r, val;
};
int n, m;
query q[N];
int mx[N][LOG], a[N];
map<int, int> cnt;
map<int, int>::iterator it;
vector<ii> qlist[N];

void pop(int val) {
    //printf("pop %d\n", val);
    if (cnt[val] == 1) cnt.erase(val);
    else cnt[val] --;
}
int rmq(int l, int r) {
    //printf("rmq %d %d\n", l, r);
    int res = -oo;
    FORD(i, LOG, 0) if (l + (1<<i) - 1 <= r) {
        res = max(res, mx[l][i]);
        l += (1<<i);
        //printf("%d %d %d %d\n", i, l, r, res);
    }
    return res;
}
int main() {
    freopen("FINDSEQ.inp", "r", stdin);
    freopen("FINDSEQ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i, 1, m) {
        scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].val);
        qlist[q[i].l].pb(mp(q[i].val, 0));
        qlist[q[i].r+1].pb(mp(q[i].val, 1));
    }
    /*FOR(i, 1, n) {
        printf("%d: ", i);
        REP(j, qlist[i].size())
            printf("(%d %d), ", qlist[i][j].fi, qlist[i][j].se);
        cerr << "\n";
    }
    cerr << "-\n";*/
    FOR(i, 1, n) {
        REP(j, qlist[i].size()) {
            ii tmp = qlist[i][j];
            if (tmp.se == 0) cnt[tmp.fi] ++;
            else pop(tmp.fi);
        }
        if (cnt.size() > 0) a[i] = (*cnt.begin()).fi;
        else a[i] = 0;
        /*for (it = cnt.begin(); it != cnt.end(); it ++)
        printf("(%d %d), ", (*it).fi, (*it).se);
        cerr << "\n";*/
    }
    //FOR(i, 1, n) cerr << a[i] << " "; cerr << "\n";
    FOR(i, 1, n) mx[i][0] = a[i];
    for (int j = 1; (1<<j) <= n; j++)
        FOR(i, 1, n) if (i + (1<<j) - 1 <= n) {
            mx[i][j] = max(mx[i][j-1], mx[i + (1<<(j-1))][j-1]);
            //printf("mx(%d, %d) = %d\n", i, j, mx[i][j]);
        }
    FOR(i, 1, m) if (rmq(q[i].l, q[i].r) != q[i].val) {
        printf("NO\n");
        exit(0);
    }
    printf("YES\n");
    FOR(i, 1, n) printf("%d ", a[i]);

    return 0;
}
/** Happy Coding :D */
