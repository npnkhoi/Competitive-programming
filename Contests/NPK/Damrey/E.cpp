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
const int N = 5e5 + 5;
int n, a[N], p[N], v[N];
int last[N];

void sub1() {
    sort(p+1, p+n+1);
    sort(v+1, v+n+1);
    FOR(i, 1, n) {
        int j = last[i-1];
        while (j < n && p[j+1] < v[i]) ++j;
        last[i] = j;
    }
    //FOR(i, 1, n) cout << last[i] << "\n";
    int tmp = n+5;
    int res = 0;
    FORD(i, n, 1) {
        int j = n - i + 1;
        tmp = min(last[i], tmp - 1);
        //cerr << tmp << "\n";
        if (tmp > 0) res = j;
        else break;
    }
    printf("%d\n", res);
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("E.inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    scanf("%d", &n);

    bool okSub1 = 1;
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        if (a[i] != 1) okSub1 = 0;
    }
    FOR(i, 1, n) scanf("%d", &p[i]);
    FOR(i, 1, n) scanf("%d", &v[i]);
    sub1();
    return 0;
}
/** Happy Coding :D */
