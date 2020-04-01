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
#define taskName "RNUM"

const int LOG = 70;
ll dp[LOG], g[LOG], tmpG[LOG];
int nBit(ll num) {
    int res = 0;
    while (num) {
        res ++;
        num >>= 1;
    }
    return res;
}
ll minPart(ll num, int k) {
    ll head = num >> (nBit(num) - k);
    ll tmp = 0;
    FOR(i, 1, nBit(num)/k) tmp = (tmp << k) + head;
    if (tmp <= num) return head;
    else return head - 1;
}
void init() {
    FOR(l, 1, LOG-1) {
        FOR(i, 1, l) if (l % i == 0 && l/i >= 2) {
            tmpG[i] = 1LL << (i-1);
            FOR(j, 1, i-1) if (i % j == 0)
                tmpG[i] -= tmpG[j];
            g[l] += tmpG[i];
        }
        //cerr << l << " " << g[l] << "\n";
    }
}
ll calc(ll num) {
    int n = nBit(num);
    ll res = 0;
    FOR(i, 2, n-1) res += g[i];
    memset(dp, 0, sizeof dp);
    FOR(i, 1, n/2) if (n % i == 0) {
        ll tmp = minPart(num, i);
        if ((tmp & (1LL << (i-1))) > 0) dp[i] = (tmp^(1LL<<(i-1))) + 1;
        else {
            dp[i] = 0;
            continue;
        }
        FOR(j, 1, i-1) if (i % j == 0) {
            dp[i] -= dp[j];
        }
        res += dp[i];
    }
    return res;
}
int checkRNUM(ll num) {
    int l = nBit(num);
    FOR(i, 1, l-1) if (l % i == 0) {
        ll last = num % (1LL << i);
        ll tmp = num;
        bool ok = 1;
        while (tmp) {
            if (tmp % (1LL << i) != last) {
                ok = false;
                break;
            }
            tmp >>= i;
        }
        if (ok) return true;
    }
    return false;
}
void show(ll num) {
    if (num == 0) return;
    show(num >> 1);
    printf("%lld", num%2);
}
int main() {
    freopen(taskName".inp", "r", stdin);
    freopen(taskName".out", "w", stdout);
    ll l, r;
    init();
    /*FOR(i, 1, LOG-1) printf("g[%d] = %lld\n", i, g[i]);
    FOR(i, 1, 1007) {
        show(i);
        printf(" %lld ", calc(i));
        if (checkRNUM(i)) printf("RNUM!!!!!!!\n");
        else printf("\n");
    }*/
    scanf("%lld%lld", &l, &r);
    printf("%lld", calc(r) - calc(l-1));
    return 0;
}
/** Happy Coding :D */
