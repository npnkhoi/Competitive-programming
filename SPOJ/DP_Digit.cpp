//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
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
//typedef pair<int, int> ii;
const int MAX_N = 35;
int choose[MAX_N+2][MAX_N+2], a[MAX_N+2];
void init() {
    choose[0][0] = 1;
    FOR(i, 1, MAX_N) {
        choose[i][0] = choose[i][i] = 1;
        FOR(j, 1, i-1) choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
    }
}
int numZero(long long n) {
    if (n == 0) return 1;
    int res = 0;
    for (int i = 0; (1LL << i) <= n; i++) res += (n & (1LL << i)) == 0;
    return res;
    //cerr << n << " " << res << "\n";
}
long long solve(long long n, int k) {
    if (n == 0) return 0;
    int m = 0;
    while (n > 0) a[m++] = n%2, n /= 2;
    //FORD(i, m-1, 0) cerr << a[i] << " "; cerr << "\n";

    long long res = 0;
    FOR(i, k, m-2) res += choose[i][k];
    if (k == 1) res ++;
    //cerr << res << "\n";
    FORD(i, m-2, 0)
    if (a[i]) {
        if (0 <= k-1 && k-1 <= i) res += choose[i][k-1];
    } else k--;
    return res;
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    init();
    long long n;
    int k;
    while (scanf("%lld %d", &n, &k) != EOF) {
        //1cerr << numZero(n) << " " << solve(n, k) << "\n";
        printf("%lld\n", (numZero(n) == k) + solve(n, k));
    }

}
/// Expelliarmus !
