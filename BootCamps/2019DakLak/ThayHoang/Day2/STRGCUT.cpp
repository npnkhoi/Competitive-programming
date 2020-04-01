#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "STRGCUT"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;
struct Node {
    vector<pair<ii, Node*> > son;
    int cnt;
} *T;
const int N = 1e5 + 5;
const int base1 = 73;
const int base2 = 37;
const ll md = 1e9 + 7;
const int MOD = 1e9;
const int MAX_HASH = 1e5 + 2;
int sh, n, m;
pll hs[N], ht[N], EXP[N];
ll f[N], sum[N];
string s, t;
vector<ii> path;
int rnk[N], sa[N], lcp[N], tmp[N];
void init(Node *&p) {
    p = new Node;
    p -> son.clear();
    p -> cnt = 0;
}
int inMod(int x) {
    x %= n;
    if (x < 0) x += n;
    return x;
}
bool cmp(int x, int y) {
    if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
    else return rnk[inMod(x + sh)] < rnk[inMod(y + sh)];
}
int diff(ii a) { return a.se - a.fi + 1;}
void buildSuffixArray() {
    s += (char)'@'; n = s.size();
    REP(i, n) rnk[i] = s[i];
    sh = 1;
    while (1) {
        REP(i, n) sa[i] = i;
        sort(sa, sa+n, cmp);
        int m = 0;
        REP(i, n) if (i == 0 || cmp(sa[i], sa[i+1])) tmp[sa[i]] = m++;
        else tmp[sa[i]] = m;
        REP(i, n) rnk[i] = tmp[i];
        if (m == n-1) break;
        else sh *= 2;
    }
    lcp[1] = 0;
    int q = 0;
    FOR(i, 1, n-2) {
        int j = sa[rnk[i]-1];
        while (q < min(n-i, n-j) && s[i+q] == s[j+q]) ++q;
        lcp[rnk[i]] = q;
        if (q > 0) -- q;
    }
}
void buildSuffixTree() {
    init(T);
    n --;
    FOR(i, 1, n) {
        Node *p = T; T -> cnt ++;
        int tmp = lcp[i];
        while (!(p->son).empty()) {
            int tailSize = diff(p->son.back().fi);
            if (tmp < tailSize) break;
            tmp -= tailSize;
            p = (p->son).back().se;
            p -> cnt ++;
        }
        if (tmp > 0) {
            ii save = (p->son).back().fi;
            Node *q; init(q);
            (q -> cnt) = ((p->son).back().se -> cnt) + 1;
            (q -> son).pb(mp(mp(save.fi + tmp, save.se), (p->son).back().se));
            (p->son).back() = mp(mp(save.fi, save.fi + tmp - 1), q);
            p = q;
        }
        Node *q; init(q);
        q->cnt = 1;
        (p->son).pb(mp(mp(sa[i] + lcp[rnk[sa[i]]], n-1), q));
    }
}
void hashInit() {
    EXP[0] = mp(1, 1);
    FOR(i, 1, MAX_HASH) {
        EXP[i].fi = EXP[i-1].fi * base1 % md;
        EXP[i].se = EXP[i-1].se * base2 % md;
    }
}
void hashBuild(string &s, pll h[], int n) {
    h[0] = mp(s[0], s[0]);
    FOR(i, 1, n-1) {
        h[i].fi = (h[i-1].fi * base1 + s[i]) % md;
        h[i].se = (h[i-1].se * base2 + s[i]) % md;
    }
}
pll hashGet(pll h[], int l, int r) {
    //cerr << "get " << l << " " << r << "\n";
    return mp(
        (h[r].fi - (l == 0 ? 0 : h[l-1].fi * EXP[r-l+1].fi) + md * md) % md,
        (h[r].se - (l == 0 ? 0 : h[l-1].se * EXP[r-l+1].se) + md * md) % md);
}
void show(ii a) {
    FOR(j, a.fi, a.se) cerr << s[j]; cerr << "\n";
}
void dfs(Node *p) {
    if ((p->son).empty()) {
        REP(j, path.size()) show(path[j]);
        //cerr << "\n";
    } else REP(j, (p->son).size()) {
        path.pb((p->son)[j].fi);
        dfs((p->son)[j].se);
        path.pop_back();
    }
}
bool ok(int l, int r) {
    //cerr << "ok " << l << " " << r << "\n";
    Node *p = T;
    while (1) {
        bool flag = 0;
        REP(j, (p->son).size()) {
            int u = (p->son)[j].fi.fi, v = (p->son)[j].fi.se;
            if (r - l > v - u) {
                if (hashGet(ht, l, l + v - u) == hashGet(hs, u, v)) {
                    l += v - u + 1;
                    flag = 1;
                    p = (p->son)[j].se;
                    break;
                }
            } else {
                /*cerr << l << " " << r <<  " " << u << " "  << v << "\n";
                cerr << hashGet(ht, l, r).fi << " " << hashGet(ht, l, r).se << " ";
                cerr << hashGet(hs, u, u+r-l).fi << " " << hashGet(hs, u, u+r-l).se << "\n";*/
                if (hashGet(ht, l, r) == hashGet(hs, u, u+r-l)) return 1;
            }
        }
        if (!flag) return false;
    }
}
int findFarthest(int x) {
    //cerr << "far " << x << "\n";
    int l = x, r = m - 1, biRes = l;
    while (l <= r) {
        //cerr << l << " " << r << "\n";
        int mid = (l + r) / 2;
        if (ok(x, mid)) biRes = mid, l = mid + 1;
        else r = mid - 1;
    }
    //cerr << "bires: " << biRes << "\n";
    if (ok(x, biRes)) return biRes;
    else {
        //cerr << "dec\n";
        return x - 1;
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    getline(cin, t);
    getline(cin, s);
    buildSuffixArray();
    buildSuffixTree();
    dfs(T);
    n = s.size(), m = t.size();
    hashInit();
    hashBuild(s, hs, n);
    hashBuild(t, ht, m);
    f[m] = 1; sum[m] = 1;
    FORD(i, m-1, 0) {
        //cerr << findFarthest(i) << "\n";
        f[i] = (sum[i+1] - sum[findFarthest(i) + 2] + MOD) % MOD;
        sum[i] = (f[i] + sum[i+1]) % MOD;
    }
    printf("%lld\n", f[0]);
    //cerr << hashGet(ht, 1, 1).fi << " " << hashGet(ht, 1, 1).se << "\n";
    //cerr << hashGet(hs, 0, 0).fi << " " << hashGet(hs, 0, 0).se << "\n";
}

