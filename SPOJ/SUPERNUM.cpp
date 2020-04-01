using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const long long md = 1e9 + 7;
long long Exp(int a, int x) {
    if (x == 1) return a % md;
    else {
        long long res = Exp(a, x/2);
        res = (res * res) % md;
        if (x%2) res = (res * a) % md;
        return res;
    }
}
int main() {
    //freopen("0.in", "r", stdin);
    //freopen("", "w", stdout);
    string line;
    int n, k;
    long long res;
    while (getline(cin, line)) {
        //cout << "-->" << line << endl;
        if (line[1] == 'E') break;
        scanf("%d%d ", &k, &n);
        //cout << "==>" << k << " " << n << endl;
        res = 1;
        for (int i = n; i <= n+k; ++i) res = (res * i) % md;
        for (int i = 2; i <= k+1; ++i) res = (res * Exp(i, md-2)) % md;
        printf("%lld\n", res);
    }
    return 0;
}
/** Happy Coding ^^ */

