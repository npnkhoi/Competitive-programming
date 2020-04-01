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
const int N = 2e5 + 5;
int a[N], cnt[N];
int main() {
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    int n;
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    int res;
    FORD(i, n, 1) {
        if (cnt[a[i]] == 0) res = a[i];
        cnt[a[i]] = 1;
    }
    cout << res;
    return 0;
}
/** Happy Coding :D */
