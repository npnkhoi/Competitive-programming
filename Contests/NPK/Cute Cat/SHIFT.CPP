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

#define taskName "shift"
const int N = 3e6 + 5;
int n;
string sa, sb, x;
int z[N];
void Zfn(string &s, int z[], int n) {
    z[0] = 0;
    int l = 0, r = 0;

    FOR(i, 1, n-1) {
        z[i] = 0;
        if (i <= r) z[i] = min(z[i-l], r-i+1);
        while (i+z[i] < n && s[i+z[i]] == s[z[i]])
            ++ z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}
int main() {
    freopen(taskName".inp", "r", stdin);
    freopen(taskName".out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    //cin >> n >> sa >> sb;
    scanf("%d ", &n);
    getline(cin, sa);
    getline(cin, sb);
    //cerr << sa.empty() << " " << sb.empty() << "\n";
    x = sa + "*" + sb + sb;
    //cerr << x << "\n";
    Zfn(x, z, 3*n+1);
    int mx = 0, res = 0;
    FOR(i, n+1, 3*n)
        if (z[i] > mx) {
            mx = z[i];
            res = i - n - 1;
        }
    cout << res;
    return 0;
}
/** Happy Coding :D */

