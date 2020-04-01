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
string s, t, x;
int z[N];
vector<int> ans;
void Z_fn(string &s, int z[]) {
    z[0] = 0;
    int n = s.size();
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
    freopen("sm.inp", "r", stdin);
    freopen("sm.out", "w", stdout);
    getline(cin, s);
    getline(cin, t);
    x = s + '.' + t;
    int m = s.size();

    Z_fn(x, z);

    FOR(i, m+1, x.size() - 1) if (z[i] == m) ans.push_back(i-m-1);
    printf("%d\n", ans.size());
    REP(j, ans.size()) printf("%d ", ans[j]);
    return 0;
}
/** Happy Coding :D */
