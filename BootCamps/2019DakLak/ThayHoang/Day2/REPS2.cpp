#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "REPS"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
struct Node {
    vector<pair<string, Node*> > son;
    int cnt;
} *T;
const int N = 1e5 + 5;
int sh, n, k, res;
string s;
int rnk[N], sa[N], lcp[N], tmp[N];
int inMod(int x) {
    x %= n;
    if (x < 0) x += n;
    return x;
}
bool cmp(int x, int y) {
    if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
    else return rnk[inMod(x + sh)] < rnk[inMod(y + sh)];
}
void dfs(Node *p, int l) {
    res = max(res, l);
    REP(j, (p->son).size()) {
        Node *q = (p->son)[j].se;
        if (q -> cnt >= k) dfs(q, l + (p->son)[j].fi.size());
    }
}
void show(string &s, int x) {
    FOR(i, x, s.size() - 1) cerr << s[i]; cerr << '\n';
}
int main() {
    freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    getline(cin, s);
    scanf("%d", &k);

    s += (char)'@'; n = s.size();
    REP(i, n) rnk[i] = s[i];
    sh = 1;
    REP(i, n) cerr << rnk[i] << ' '; cerr << '\n';
    while (1) {
        REP(i, n) sa[i] = i;
        sort(sa, sa+n, cmp);
        REP(i, n) cerr << sa[i] << ' '; cerr << '\n';
        int m = 0;
        REP(i, n) if (i == 0 || cmp(sa[i], sa[i+1])) tmp[sa[i]] = m++;
        else tmp[sa[i]] = m;
        REP(i, n) rnk[i] = tmp[i];
        REP(i, n) cerr << rnk[i] << ' '; cerr << '\n';
        if (m == n-1) break;
        else sh *= 2;
        cerr << "-----------\n";
    }
    REP(i, n) show(s, sa[i]);
    lcp[0] = 0;
    int q = 0;
    REP(i, n-1) {
        int j = sa[rnk[i]-1];
        while (q < min(n-i, n-j) && s[i+q] == s[j+q]) ++q;
        lcp[rnk[i]] = q;
        if (q > 0) -- q;
    }
    cerr << "ok lcp\n";

    T = new Node;
    REP(i, n) {
        Node *p = T; T -> cnt ++;
        int tmp = lcp[i];
        while (!(p->son).empty() && tmp > (p->son).back().fi.size()) {
            tmp -= (p->son).back().fi.size();
            p = (p->son).back().se;
            p -> cnt ++;
        }
        if (tmp > 0) {
            string save = (p->son).back().fi;
            Node *q = new Node;
            q -> cnt = p -> cnt;
            (q -> son).pb(mp(save.substr(tmp, save.size() - tmp), (p->son).back().se));
            (p->son).back() = mp(save.substr(0, tmp), q);
            p = q;
        }
        Node *q = new Node;
        (p->son).pb(mp(s.substr(sa[i] + lcp[rnk[sa[i]]], n - (sa[i] + lcp[rnk[sa[i]]])), q));
        (q->cnt) = 1;
    }
    dfs(T, 0);
    cerr << res;
}

