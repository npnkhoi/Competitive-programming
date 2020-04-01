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
const int N = 1e6 + 5;
int n, k, a[N];
int fast_max(int n, int a[]) {
    int ans = 0;
    int offset = 0;
    for (int i = 0; i < n; ++i)
        if (ans < a[i]) {
            ans = a[i];
            offset = 0;
        } else {
            offset = offset + 1;
            if (offset == k)
                return ans;
        }
    return ans;
}
int main() {
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n >> k;
    int res = 0;
    REP(i, n) a[i] = i+1;
    do {
        REP(i, n) cerr << a[i] << " ";
        cerr << "->" << fast_max(n, a) << "\n";
        if (fast_max(n, a) != n) res ++;
    } while (next_permutation(a, a+n));
    cout << res << "\n";
    return 0;
}
/** Happy Coding :D */
