#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define task "fastfood"

const int N = 1505;
const int M = N*N;
int n, m;

int a[N][N], save[2*N], id[M], cnt[2*N];//, IT[4*N], lazy[8*N];
vector<int> data[M], lis, lds;

void solve(vector<int> &v) {
    int n = v.size();
    lis.clear();
    lds.clear();
    REP(i, v.size()) {
        int val = v[i];
        if (lis.empty() || val >= lis.back()) {
            lis.pb(val);
            save[i] = lis.size() - 1;
        }
        else {
            int pos = upper_bound(lis.begin(), lis.end(), val) - lis.begin();
            lis[pos] = val;
            save[i] = pos;
        }
    }
    FORD(i, v.size() - 1, 0) {
        int val = v[i];
        if (lds.empty() || val <= lds.back()) {
            lds.pb(val);
            save[i] += lds.size();
            cnt[save[i]] ++;
        } else {
            int pos = upper_bound(lds.begin(), lds.end(), val, greater<int>()) - lds.begin();
            lds[pos] = val;
            save[i] += pos + 1;
            cnt[save[i]] ++;
        }
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) FOR(j, 1, n) {
        scanf("%d", &a[i][j]);
        if (id[a[i][j]] == 0) id[a[i][j]] = ++ m;
        data[id[a[i][j]]].pb(j);
    }
    FOR(i, 1, m) solve(data[i]);
    FOR(i, 1, 2*n-1) printf("%d ", cnt[i]);
}
/*void lazyDown(int p, int l, int r) {
    if (l == r) {
        IT[p] = max(IT[p], lazy[p]);
        lazy[p] = 0;
    } else {
        IT[p] = max(IT[p], lazy[p]);
        lazy[2*p] = max(lazy[2*p], lazy[p]);
        lazy[2*p+1] = max(lazy[2*p+1], lazy[p]);
        lazy[p] = 0;
    }
}
int query(int p, int l, int r, int L, int R) {
    if (l > r || L > R || l > R || L > r) return -1;
    lazyDown(p, l, r);
    if (L <= l && r <= R) return IT[p];
    else {
        int mi = (l+r)/2;
        int x = query(2*p, l, mi, L, R);
        int y = query(2*p+1, mi+1, r, L, R);
        return max(x, y);
    }
}
void update(int p, int l, int r, int L, int R, int val) {
    if (l > r || L > R || l > R || L > r) return;
    lazyDown(p, l, r);
    if (L <= l && r <= R) {
        IT[p] = max(IT[p], val);
        lazy[2*p] = max(lazy[2*p], val);
        lazy[2*p+1] = max(lazy[2*p+1], val);
    } else {
        int mi = (l+r) / 2;
        update(2*p, l, mi, L, R, val);
        update(2*p+1, mi+1, r, L, R, val);
        IT[p] = max(IT[2*p], IT[2*p+1]);
    }
}

int maxLength(vector<int> &v) {
    memset(IT, 0, sizeof IT);
    memset(lazy, 0, sizeof lazy);

    REP(i, v.size()) {
        int tmp = query(1, 1, n, 1, v[i]);
        update(1, 1, n, v[i], n, tmp + 1);
    }
    return query(1, 1, n, 1, n);
}
int maxLength(vector<int> &v) {
    lis.clear();
    cerr << "maxLength algo\n";
    REP(i, v.size()) cerr << v[i] << " ";
    cerr << "\n";
    REP(i, v.size()) {
        int val = v[i];
        if (lis.empty() || val >= lis.back()) lis.pb(val);
        else {
            int pos = upper_bound(lis.begin(), lis.end(), val) - lis.begin();
            lis[pos] = val;
        }
        REP(j, lis.size()) cerr << lis[i] << " "; cerr << "\n";
    }
    return lis.size();
}*/
