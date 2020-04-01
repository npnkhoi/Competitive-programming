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
const int N = 1e5 + 5;
string s;
int z[N];
void Z_fn(string &s, int z[], int n) {
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
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    getline(cin, s);
    ll res = 0;
    REP(i, s.size()) {
        reverse(s.begin(), s.begin() + i+1);
        Z_fn(s, z, i+1);
        int tmp = 0;
        REP(j, i+1) tmp = max(tmp, z[j]);
        /*cerr << s << endl;
        REP(j, i+1) cerr << z[j] << " "; cerr << "\n";
        cerr << tmp << endl;*/
        res += i-tmp+1;
        reverse(s.begin(), s.begin() + i+1);
    }
    printf("%lld\n", res);
    return 0;
}
/** Happy Coding :D */
