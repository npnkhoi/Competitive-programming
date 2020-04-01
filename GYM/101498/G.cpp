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
const int N = 2e3 + 5;
int n;
ll a[N], s[N], _gcd[N][N], _lcm[N][N], res;
int digits(ll a) {
    if (a == 0) return 1;
    else {
        return 1 + int(floor(log10(a)));
    }
}
ll lcm(ll a, ll b) {
    b /= __gcd(a, b);
    ll c = a*b;
    if (c % a) return -1;
    if (c % b) return -1;
    return a * b;
}
int main() {
    //freopen("0.in","r",stdin);
    //freopen("","w",stdout);
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        res = 0;
        scanf("%d", &n);
        FOR(i, 1, n) {
            scanf("%lld", &a[i]);
            s[i] = s[i-1] + a[i];
        }
        FOR(j, 1, n) {
            _gcd[j][j] = a[j];
            _lcm[j][j] = a[j];
            FOD(i, j-1, 1)
            if (_lcm[i+1][j] == -1 || _gcd[i+1][j] == -1)
                _gcd[i][j] = _lcm[i][j] = -1;
            else {
                _gcd[i][j] = __gcd(a[i], _gcd[i+1][j]);
                _lcm[i][j] = lcm(a[i], _lcm[i+1][j]);
                if (_lcm[i][j] != -1) res += ((s[j] - s[i-1]) % _lcm[i][j] == 0);
            }
        }
        /*FOR(i, 1, n) {
            FOR(j, 1, n) printf("%5lld", _gcd[i][j]);
            cout << endl;
        }
        cout << endl;
        FOR(i, 1, n) {
            FOR(j, 1, n) printf("%5lld", _lcm[i][j]);
            cout << endl;
        }*/
        printf("%d\n", res + n);
    }
    return 0;
}
/** Happy Coding ^^ */
