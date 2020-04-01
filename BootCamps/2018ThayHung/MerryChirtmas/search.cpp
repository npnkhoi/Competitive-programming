#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "search"
typedef long long ll;
//typedef pair<int, int> ii;

const int N = 1e5 + 5;
int a[N], b[N], c[N], pos[N];
int m, n, p;
bool mark[N];

void stdlize(int a[], int &n) {
    sort(a+1, a+n+1);
    int p = 1;
    FOR(i, 2, n) if (a[i] != a[i-1]) a[++p] = a[i];
    n = p;
}
bool ok(int l, int r) {
    //printf("ok %d %d\n", l, r);
    int cnt = 0;
    memset(mark, 0, sizeof mark);
    FOR(i, l, r) if (pos[c[i]]) {
        int tmp = pos[c[i]];
        //cerr << tmp << "\n";
        if (mark[tmp] == 0) cnt++;
        mark[tmp] = 1;
    }
    //cerr << (cnt == m) << "\n";
    return (cnt == m);
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d %d %d", &m, &n, &p);
    FOR(i, 1, m) scanf("%d", &a[i]);
    stdlize(a, m);
    FOR(i, 1, m) pos[a[i]] = i;

    FOR(i, 1, n) scanf("%d", &b[i]);
    stdlize(b, n);

    //FOR(i, 1, m) cerr << a[i] << " "; cerr << "\n";
    //FOR(i, 1, n) cerr << b[i] << " "; cerr << "\n";

    int save = 0;
    int res = 0;
    FOR(i, 1, p) {
        scanf("%d", &c[i]);
        if (binary_search(b+1, b+n+1, c[i])) {
            //cerr << i << "\n";
            if (ok(save + 1, i - 1)) {
                res = max(res, i - save - 1);
                //cerr << save + 1 << " " << i - 1 << "\n";
                //FOR(j, save + 1, i - 1) cerr << c[j] << " "; cerr << "\n";
            }
            save = i;
        }
    }
    if (ok(save+1, p)) res = max(res, p - save);
    printf("%d", res);
}
/// Expelliarmus !
