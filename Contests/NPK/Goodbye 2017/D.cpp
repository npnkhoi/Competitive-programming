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

int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b <= c || d <= a) cout << 0;
    else if (a <= c && d <= b) cout << d-c;
    else if (c <= a && b <= d) cout << b-a;
    else cout << min(b-c, d-a);
}
/// Expelliarmus !
