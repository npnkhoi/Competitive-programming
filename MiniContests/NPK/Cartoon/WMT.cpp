#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define taskName "0"

const int N = 1005;
const ll oo = 1e18 + 8;

int m, n;
ll a[N][N], s[N][N], tmp[2*N];

long long Rand(long long l, long long r) {
    return l + (
        1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
        1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
        1LL * rand() * (RAND_MAX + 1) +
        1LL * rand() ) % (r-l+1);
}

ll sum(int row, int l, int r) {
    return s[row][r] - s[row][l-1];
}

ll sumMed(int row, int val) { /// med: median value
    ll res = 0;
    int pos = upper_bound(a[row]+1, a[row]+n+1, val) - a[row] - 1;
    res += 1LL * val * pos - sum(row, 1, pos);
    res += sum(row, pos+1, n) - 1LL * val * (n - pos);
    return res;
}

ll ans(int u, int v) {
    //printf("ans %d %d ============= \n", u, v);
    int l, r, res = 0;
    int save = 0;
    ll returnVal = oo;

    l = 1, r = n;
    while (l <= r) {
        int mi = (l+r) / 2;
        int pos = lower_bound(a[v] + 1, a[v] + n + 1, a[u][mi]) - a[v];
        int cntLess = mi + pos - 2; /// so luong so toi da, nho hon a[u][mi]
        if (cntLess <= n) {
            if (cntLess >= res) {
                res = cntLess;
                save = a[u][mi];
            }
            l = mi + 1;
        } else r = mi - 1;
    }
    returnVal = min(returnVal, sumMed(u, save)+ sumMed(v, save));

    l = 1, r = n;
    while (l <= r) {
        int mi = (l+r) / 2;
        int pos = lower_bound(a[u] + 1, a[u] + n + 1, a[v][mi]) - a[u];
        int cntLess = mi + pos - 2; /// so luong so toi da, nho hon a[v][mi]
        if (cntLess <= n) {
            if (cntLess >= res) {
                res = cntLess;
                save = a[v][mi];
            }
            l = mi + 1;
        } else r = mi - 1;
    }
    returnVal = min(returnVal, sumMed(u, save) + sumMed(v, save));

    return returnVal;
}
ll ans2() {

}
void bf() {
    //printf("\nSOLUTION!!\n");
    ll res = 0;
    FOR(u, 1, m-1) FOR(v, u+1, m) {
        FOR(i, 1, n) tmp[i] = a[u][i];
        FOR(i, 1, n) tmp[n+i] = a[v][i];
        sort(tmp + 1, tmp + 2*n + 1);
        FOR(i, 1, 2*n) res += abs(tmp[i] - tmp[n]);
    }
    printf("%lld\n", res);
}
void test() {
    srand(time(NULL));
    ofstream inp(taskName".inp");
    int m = Rand(50, 1000);
    int n = Rand(50, 1000);
    inp << m << " " << n << "\n";
    FOR(i, 1, m) {
        FOR(j, 1, n) inp << Rand(1, 1e9) << " ";
        inp << "\n";
    }
    inp.close();
}
int main() {
    //test();
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%d%d", &m, &n);
    FOR(i, 1, m) {
        FOR(j, 1, n) scanf("%lld", &a[i][j]);
        sort(a[i] + 1, a[i] + n + 1);
        FOR(j, 1, n) s[i][j] = s[i][j-1] + a[i][j];
    }
    /*FOR(i, 1, m) {
        FOR(j, 1, n) cerr << a[i][j] << " ";
        cerr << "\n";
    }*/
    ll res = 0;
    FOR(i, 1, m-1) FOR(j, i+1, m) res += ans(i, j);
    printf("%lld", res);
    //bf();
    return 0;
}
/** Happy Coding :D */
