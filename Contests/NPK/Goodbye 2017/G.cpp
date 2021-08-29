#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

long long a, b, res;
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> a >> b;
    for (long long x = 1; x <= a; x++)
    res += (long long) floor(sqrt(x*x + b)) - x;
    cout << res;
}
/// Expelliarmus !
