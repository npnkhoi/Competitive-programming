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

#define taskName ""

int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    int a, b, c, tmp, ans = 0;
    cin >> a >> b >> c;

    ans = max(ans, (a+b)*c);
    ans = max(ans, a * (b+c));
    ans = max(ans, a * b * c);
    ans = max(ans, a * b + c);
    ans = max(ans, a + b * c);
    ans = max(ans, a + b + c);

    cout << ans;
    return 0;
}
/** Happy Coding :D */
