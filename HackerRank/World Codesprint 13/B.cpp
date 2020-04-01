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
int n, m, mini, tmp;
string name[N];
int lim[4], lab[N], cnt[N][4], Rank[N], grade[N];
vi ans;
map<string, int> id;
int root(int u) {
    if (lab[u] == -1) return u;
    else return lab[u] = root(lab[u]);
}
void join(int u, int v) {
    if (Rank[u] > Rank[v]) {
        lab[v] = u;
        FOR(i, 0, 3) cnt[u][i] += cnt[v][i];
    } else {
        lab[u] = v;
        FOR(i, 0, 3) cnt[v][i] += cnt[u][i];
        Rank[v] += (Rank[u] == Rank[v]);
    }
}
bool cmp(int a, int b) {
    return name[a] < name[b];
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> mini >> lim[0] >> lim[1] >> lim[2] >> lim[3];
    FOR(i, 1, n) {
        cin >> name[i] >> grade[i];
        id[name[i]] = i;
    }
    memset(lab, -1, sizeof lab);
    FOR(i, 1, n) cnt[i][0] = cnt[i][grade[i]] = 1;
    while (m --) {
        string su, sv;
        cin >> su >> sv;
        //cerr << su << " " << sv << "\n";
        int u = root(id[su]), v = root(id[sv]);
        if (u == v) continue;
        //cerr << u << " " << v << "\n";
        bool ok = 1;
        FOR(l, 0, 3) if (cnt[u][l] + cnt[v][l] > lim[l]) ok = 0;
        if (!ok) continue;
        else join(u, v);
        tmp = max(tmp, cnt[root(u)][0]);
    }
    if (tmp < mini) cout << "no groups";
    else {
        FOR(i, 1, n) if (cnt[root(i)][0] == tmp) ans.push_back(i);
        sort(ans.begin(), ans.end(), cmp);
        REP(i, ans.size()) cout << name[ans[i]] << '\n';
    }

}
