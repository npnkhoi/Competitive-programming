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
char s[N];
int n, a[N], b[N];
int main() {
    freopen("ALL_PAL.inp", "r", stdin);
    freopen("ALL_PAL.out", "w", stdout);
    scanf("%s", s+1);
    n = strlen(s+1);
    ll res = n;

    int l, r;

    a[1] = 0; l = r = 1;
    FOR(i, 2, n) {
        int k = 0;
        if (i <= r) k = a[r-l-i];
        while (1 < i-k && i+k < n && s[i-k-1] == s[i+k+1]) ++k;
        a[i] = k;
        if (i + k > r)
            l = i - k, r = i + k;
        res += a[i];
    }

    b[2] = (s[1] == s[2]);
    res += b[2];
    l = 1, r = 2;
    FOR(i, 3, n) {
        if (s[i] != s[i-1]) b[i] = 0;
        else {
            int k = 1;
            if (i <= r) k = b[l+r-i+1];
            while (1 < i-k-1 && i+k < n && s[i-k-2] == s[i+k+1]) ++k;
            a[i] = k;
            if (i + r > r) {
                l = i - k - 1, r = i + k;
            }
        }
        res += b[i];
    }
    //FOR(i, 1, n) cerr << a[i]; cerr << "\n";
    //FOR(i, 1, n) cerr << b[i]; cerr << "\n";
    printf("%lld\n", res);


    return 0;
}
/** Happy Coding ^^ */

