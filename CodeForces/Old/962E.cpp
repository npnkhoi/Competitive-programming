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

const int N = 2e5 + 5;
int n;
int a[N], b[N], l[4], r[4];
long long res = 0;
vector<ii> data;
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &n);
    l[1] = l[2] = l[3] = -1;
    FOR(i, 1, n) {
        char ch;
        scanf("%d %c", &a[i], &ch);
        if (ch == 'P') b[i] = 1;
        else if (ch == 'R') b[i] = 2;
        else b[i] = 3;

        if (l[b[i]] == -1) l[b[i]] = i;
        r[b[i]] = i;
    }
    if (l[1] == -1) {
        if (l[2] != -1) res += a[r[2]] - a[l[2]];
        if (l[3] != -1) res += a[r[3]] - a[l[3]];
        printf("%lld", res);
        exit(0);
    }

    if (l[2] != -1) {
        if (l[2] < l[1]) res += a[l[1]] - a[l[2]];
        if (r[1] < r[2]) res += a[r[2]] - a[r[1]];
    }
    if (l[3] != -1) {
        if (l[3] < l[1]) res += a[l[1]] - a[l[3]];
        if (r[1] < r[3]) res += a[r[3]] - a[r[1]];
    }
    //cerr << res << "\n";

    //cerr << l[1] << " " << r[1] << "\n";
    int u = -1, v;
    FOR(i, l[1], r[1] + 1) {
        if (b[i] == 1) {
            if (u == -1) u = i;
            v = i;
        } else if (u != -1) {
            data.push_back(mp(u, v));
            res += a[v] - a[u];
            u = -1;
        }
    }

    for (int i = 1; i <= (int)(data.size() - 1); i++) {
        //cerr << i << "\n";
        int u = data[i-1].second;
        int v = data[i].first;
        //cerr << u << " " << v << "\n";

        int tmp2 = -1, maxDist2 = 0;
        FOR(i, u+1, v-1) if (b[i] == 2) {
            if (tmp2 == -1) maxDist2 = a[i] - a[u];
            else maxDist2 = max(maxDist2, a[i] - a[tmp2]);
            tmp2 = i;
        }
        if (tmp2 != -1) maxDist2 = max(maxDist2, a[v] - a[tmp2]);

        int tmp3 = -1, maxDist3 = 0;
        FOR(i, u+1, v-1) if (b[i] == 3) {
            if (tmp3 == -1) maxDist3 = a[i] - a[u];
            else maxDist3 = max(maxDist3, a[i] - a[tmp3]);
            tmp3 = i;
        }
        if (tmp3 != -1) maxDist3 = max(maxDist3, a[v] - a[tmp3]);

        int len1 = 2*(a[v] - a[u]), len2 = a[v] - a[u];

        if (tmp2 != -1) len2 += a[v] - a[u] - maxDist2;
        if (tmp3 != -1) len2 += a[v] - a[u] - maxDist3;

        res += min(len1, len2);
        //err << min(len1, len2) << "\n";
    }
    printf("%lld", res);
}
