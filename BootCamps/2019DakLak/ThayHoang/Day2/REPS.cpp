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
    vector<pair<ii, Node*> > son;
    int cnt;
} *T;
const int N = 1e5 + 5;
int sh, n, k, maxL;
string s;
vector<ii> curString, saveString;
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
void show(ii a) {
    FOR(i, a.fi, a.se) cerr << s[i];
    cerr << "\n";
}
void show(string &s, int x) {
    FOR(i, x, s.size() - 1) cerr << s[i]; cerr << '\n';
}
void dfs(Node *p, int l) {
    /*cerr << p->cnt << ' ' << curString.size() << "\n";
    REP(j, (p->son).size()) cerr << p->son[j].fi.fi << ' ' << p->son[j].fi.se << ' ',
     show(p->son[j].fi);
    cerr << '\n';*/
    if (l > maxL) {
        maxL = l;
        saveString = curString;
    }
    REP(j, (p->son).size()) {
        Node *q = (p->son)[j].se;
        if (q -> cnt >= k) {
            curString.pb((p->son)[j].fi);
            //FOR(z, (p->son)[j].fi.fi, (p->son)[j].fi.se) cerr << s[z];
            //cerr << ' ' << curString.size() << '\n';
            dfs(q, l + diff((p->son)[j].fi));
            curString.pop_back();
        }
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    getline(cin, s);
    scanf("%d", &k);

    s += (char)'@'; n = s.size();
    REP(i, n) rnk[i] = s[i];
    sh = 1;
    //REP(i, n) cerr << rnk[i] << ' '; cerr << '\n';
    while (1) {
        REP(i, n) sa[i] = i;
        sort(sa, sa+n, cmp);
        //REP(i, n) cerr << sa[i] << ' '; cerr << '\n';
        int m = 0;
        REP(i, n) if (i == 0 || cmp(sa[i], sa[i+1])) tmp[sa[i]] = m++;
        else tmp[sa[i]] = m;
        REP(i, n) rnk[i] = tmp[i];
        //REP(i, n) cerr << rnk[i] << ' '; cerr << '\n';
        if (m == n-1) break;
        else sh *= 2;
        //cerr << "-----------\n";
    }
    //REP(i, n) show(s, sa[i]);
    lcp[1] = 0;
    int q = 0;
    FOR(i, 0, n-2) {
        int j = sa[rnk[i]-1];
        while (q < min(n-i, n-j) && s[i+q] == s[j+q]) ++q;
        lcp[rnk[i]] = q;
        if (q > 0) -- q;
    }
    //cerr << "ok lcp\n";

    init(T);
    //cerr << "T size" << (T->son.size()) << '\n';
    n --;
    FOR(i, 1, n) {
        //show(s, sa[i]);
        //cerr << "lcp " << i << " = " << lcp[i] << endl;
        Node *p = T; T -> cnt ++;
        int tmp = lcp[i];
        while (!(p->son).empty()) {
            int tailSize = diff(p->son.back().fi);
            if (tmp < tailSize) break;
            //cerr << "move down\n";
            tmp -= tailSize;
            p = (p->son).back().se;
            p -> cnt ++;
        }
        if (tmp > 0) {
            //cerr << "crack " << tmp << " " << diff(p->son.back().fi) << "\n";
            //show(p->son.back().fi);
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
    //cerr << (T->son).size() << '\n';
    dfs(T, 0);
    //cerr << maxL;
    REP(i, saveString.size())
    FOR(j, saveString[i].fi, saveString[i].se) printf("%c", s[j]);
}

