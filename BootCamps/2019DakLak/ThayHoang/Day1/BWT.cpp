#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "BWT"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
const int N = 1e5 + 5;
string s;
int n, sh, a[N], id[N], tmp[N], cnt[300];
map<ii, ii> nxt;
int inmod(int x) {
    x %= n;
    if (x < 0) x += n;
    return x;
}
int cmp(int x, int y) {
    if (id[x] != id[y]) return id[x] < id[y];
    else return id[inmod(x+sh)] < id[inmod(y+sh)];
}
void task1() {
    s += '@'; n ++;
    //cerr << s << "\n";
    sh = 1;
    REP(i, n) id[i] = s[i] - '@';
    //REP(i, n) cerr << id[i] << " "; cerr << "\n";
    while (1) {
        REP(i, n) a[i] = i;
        sort(a, a + n, cmp);
        //REP(i, n) cerr << a[i] << " "; cerr << '\n';
        int m = 1; tmp[a[0]] = 0;
        REP(i, n-1) {
            m += cmp(a[i], a[i+1]);
            tmp[a[i+1]] = m;
            //cerr << (int) cmp(a[i], a[i+1]) << "\n";
        }
        REP(i, n) id[i] = tmp[i];
        //REP(i, n) cerr << id[i] << " "; cerr << '\n';
        if (m == n) break;
        sh *= 2;
        //cerr << "----------\n";
    }
    REP(i, n) cout << s[inmod(a[i] - 1)];
    cout << '\n';
}
void task2() {
    memset(cnt, 0, sizeof cnt);
    nxt.clear();
    REP(i, n) tmp[i] = cnt[s[i]] ++;
    int p = 0;
    REP(ch, 256) REP(z, cnt[ch]) {
        nxt[mp(s[p], tmp[p])] = mp(ch, z);
        p ++;
    }
    ii cur = mp('@', 0);
    REP(i, n-1) {
        cur = nxt[cur];
        cout << (char) (cur.fi);
    }
    cout << '\n';
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> s) {
        n = s.size();
        bool flag = 0;
        REP(i, n) if (s[i] == '@') flag = 1;
        if (flag) task2(); else task1();
    }
}
