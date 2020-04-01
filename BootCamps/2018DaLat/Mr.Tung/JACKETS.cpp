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

//ifstream inp(".inp");
//ofstream out(".out");
const int N = 1e5 + 5;
struct pack {
    int deg;
    int type;
    int id;
    bool operator < (const pack b) {
        if (deg != b.deg) return deg < b.deg;
        else if (type != b.type) return type < b.type;
        else return id < b.id;
    }
};
vector<pack> data;
set<int> avail;
set<int>::iterator it;
int pre[N][3];
vector<int> fits[N];

void trace(int i, int j) {
    if (i > 1) trace(i-1, pre[i][j]);
    printf("%d ", fits[i][j]);
}
pack Pack(int a, int b, int c) {
    pack tmp;
    tmp.deg = a;
    tmp.type = b;
    tmp.id = c;
    return tmp;
}
int main() {
    freopen("JACKETS.inp", "r", stdin);
    freopen("JACKETS.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    int t, l, r;
    FOR(i, 1, n) {
        scanf("%d", &t);
        data.pb(Pack(t, 0, i));
    }
    FOR(i, 1, m) {
        scanf("%d%d", &l, &r);

        data.pb(Pack(l, -1, i));
        data.pb(Pack(r, +1, i));
    }
    sort(data.begin(), data.end());
    REP(i, data.size()) {
        if (data[i].type == -1) avail.insert(data[i].id);
        else if (data[i].type == 1) avail.erase(data[i].id);
        else {
            if (avail.size() == 0) {
                printf("No\n");
                return 0;
            }
            int cur = data[i].id;
            int cnt = 1;
            for (it = avail.begin(); it != avail.end() && cnt <= 3; ++it, ++cnt) {
                fits[cur].pb(*it);
                //cerr << *it << " ";
            }
            //cerr << "\n";
        }
    }
    FOR(i, 2, n) REP(j, fits[i].size()) {
        pre[i][j] = -1;
        REP(k, fits[i-1].size())
        if (fits[i][j] != fits[i-1][k] && pre[i-1][k] != -1) {
            pre[i][j] = k;
            break;
        }
    }
    REP(j, fits[n].size()) if (pre[n][j] != -1) {
        printf("Yes\n");
        trace(n, j);
        return 0;
    }
    printf("No\n");
    return 0;
}
/** Happy Coding :D */
