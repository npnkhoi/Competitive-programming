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
const int N = 2e6 + 5;
string s;
int z[N], ans[N];
void Z_fn(string &s, int z[]) {
    memset(z, 0, sizeof z);
    int n = s.size();
    int l = 0, r = 0;

    FOR(i, 1, n-1) {
        if (i <= r) z[i] = min(z[i-l], r-i+1);
        while (i+z[i] < n && s[i+z[i]] == s[z[i]])
            ++ z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}
int main() {
    freopen("PF.inp", "r", stdin);
    //freopen("PF.out", "w", stdout);
    getline(cin, s);
    Z_fn(s, z);

    REP(i, s.size()) ans[i] = i+1;

    REP(i, s.size()) ans[i+z[i]-1] = min(ans[i+z[i]-1], i);
    REP(i, s.size()) cerr << ans[i] << "\n";
    FORD(i, s.size() - 2, 0) {
        ans[i] = min(ans[i], ans[i+1]);
    }
    REP(i, s.size()) printf("%d ", i - ans[i] + 1);
    return 0;
}
/** Happy Coding :D */
