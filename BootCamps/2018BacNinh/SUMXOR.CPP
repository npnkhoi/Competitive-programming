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
const int N = 1e6 + 5;
int a[N];
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SUMXOR.inp", "r", stdin);
    freopen("SUMXOR.out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    int n;
    ll res = 0;

    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    for (int i = 0; (1<<i) <= 1e6+5; i++) {
        int cnt = 0;
        FOR(j, 1, n) if (a[j] & 1<<i) cnt ++;
        res += (1LL << i) * cnt * (n - cnt);
    }
    printf("%lld\n", res);


    return 0;
}
/** Happy Coding :D */
