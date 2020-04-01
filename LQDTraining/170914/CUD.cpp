using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 20;
const int S = 140;
long long numA, numB;
int s;
int n, a[N], sa[N];
long long memo[N][S];
int numDigit(long long n) {
    if (n == 0) return 1;
    else {
        int res = 0;
        while (n) n /= 10, res ++;
        return res;
    }
}
long long ans(long long num) {
    n = numDigit(num);
    FOD(i, n, 1) a[i] = num%10, num /= 10;
    FOR(i, 1, n) sa[i] = sa[i-1] + a[i];

    memset(memo, 0, sizeof memo);
    FOR(i, 1, n) FOR(j, 0, s) {
        FOR(k, 0, 9) if (j - k >= 0) memo[i][j] += memo[i-1][j-k];
        memo[i][j] += (j <= sa[i]) && (j - sa[i-1] < a[i]) && (0 <= j - sa[i-1]);
    }
    return memo[n][s];
}
int main() {
    freopen("CUD.inp", "r", stdin);
    freopen("CUD.out", "w", stdout);
    cin >> numA >> numB >> s;
    cout << ans(numB + 1) - ans(numA) << endl;
    long long l = numA, r = numB, tmp = ans(numA);
    while (l < r) {
        long long mid = (l + r) / 2;
        if (ans(mid + 1) - tmp >= 1) r = mid;
        else l = mid + 1;
    }
    cout << l;
    return 0;
}
/** Happy Coding ^^ */
