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

long long Rand(ll l, ll r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    rand() ) % (r-l + 1);
}
int main() {
    //freopen("","r",stdin);
    freopen("0.in","w",stdout);
    int s = 1000;
    int n = 500;
    cout << s << " " << n << "\n";
    REP(i, n) cout << Rand(1, min(10000, s)) << " " << Rand(1, 100) << endl;
    return 0;
}
/** Happy Coding ^^ */
