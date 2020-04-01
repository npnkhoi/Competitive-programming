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

long long m, n, k, x, y, res;
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> m >> n >> k;
    x = m - m % k;
    y = n - n % k;
    res = 1 + x/k + y/k + x * (y / k) + (m % k) * (y / k) + (n % k) * (x / k);
    //cerr << res << "\n";
    if (n % k + m % k >= k) res += abs((n % k) - (k - m % k))  + 1;
    cout << res;
}
