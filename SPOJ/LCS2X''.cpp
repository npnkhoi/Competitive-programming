#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int N = 1500 + 5;
int tc, m, n, IT[4*N], a[N], b[N], res;
map<int, int> id;
void update(int p, int l, int r, int i, int val) {
    if (l < r || i < l || r < i) return;
    if (l == i && i == r) IT[p] = max(IT[p], val);
    else {
        int mi = (l+r)/2;
        update(2*p, l, mi, i, val);
        update(2*p+1, mi+1, r, i, val);
        IT[p] = max(IT[2*p], IT[2*p+1]);
    }
}
int rmq(int p, int l, int r, int L, int R) {
    if (l > r || l > R || L > r || L > R) return -1;
    if (L <= l && r <= R) return IT[p];
    else {
        int mi = (l+r)/2;
        return max(rmq(2*p, l, mi, L, R), rmq(2*p+1, mi+1, r, L, R));
    }
}
int main() {
    scanf("%d", &tc);
    REP(z, tc) {
        memset(IT, 0, sizeof IT);
        res = 0;
        scanf("%d %d", &m, &n);
        FOR(i, 1, m) {
            scanf("%d", &a[i]);
            id[a[i]] = 0;
        }
        FOR(i, 1, n) {
            scanf("%d", &b[i]);
            id[b[i]] = 0;
        }
        map<int, int>::iterator it;
        int i = 0;
        for (it = id.begin(); it != id.end(); it++) {
            it -> second = ++i;
            cout << it -> first << " " << it -> second << endl;
        }
        int siz = id.size();
        for (int i = 1; i <= n; i++) cout << a[i] << " " ;
        cout << "1\n";
        for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) if (a[i] == b[j]) {
            cout << i << " " << j << " " << id.lower_bound(a[i]/2)->second - 1<< endl;
            int tmp = 1 + rmq(1, 1, siz, 1, id.lower_bound(a[i]/2)->second - 1);
            cout << "ok\n";
            res = max(res, tmp);
            update(1, 1, siz, id[a[i]], tmp);
        }
        printf("%d\n", res);
    }
}
