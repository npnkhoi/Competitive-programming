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
int z[N];
string a, b, s;
void zfn(string &s, int z[], int n) {
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
    freopen("UC2XAU.inp", "r", stdin);
    freopen("UC2XAU.out", "w", stdout);
    getline(cin, a);
    getline(cin, b);
    s = a + b;

    int m = a.size(), n = b.size(), p = s.size();
    zfn(s, z, p);
    /*REP(i, p) cerr << z[i] << " ";
    cerr << "\n";*/
    int res = 0;

    for (int i = 1; i <= m && i <= n; ++i)
        if (n%i==0 && m%i == 0)
        res += z[i] == p - i;
    printf("%d\n", res);
    return 0;
}
/** Happy Coding :D */
