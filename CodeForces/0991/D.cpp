#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 105;
int n;
char a[N], b[N];
int f[N];
int cnt(int x, int d) {
    int res = 0;
    FOR(i, x-d+1, x) res += (a[i] == 'X') + (b[i] == 'X');
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> (a + 1); cin >> (b + 1);
    n = strlen(a + 1);
    FOR(i, 1, n) {
        f[i] = f[i-1];
        if (i >= 2 && cnt(i, 2) <= 1) f[i] = max(f[i], f[i-2] + 1);
        if (i >= 3 && cnt(i, 3) == 0) f[i] = max(f[i], f[i-3] + 2);
    }
    cout << f[n];
}
