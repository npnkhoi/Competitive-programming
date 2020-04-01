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
#define task "E"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

ll n;
int cnt[20], idx[20];
bool check(int x) {
    memset(idx, 0, sizeof idx);
    while (x > 0) {
        idx[x % 10] ++;
        x /= 10;
    }
    REP(i, 10) if (idx[i] > cnt[i] || (cnt[i] > 0 && idx[i] == 0)) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);

    cin >> n;
    int m = n;
    while (m > 0) {
        cnt[m % 10] ++;
        m /= 10;
    }
    int res = 0;
    FOR(i, 1, 9999999) {
        if (check(i)) res ++, cerr << i << "\n";
    }
    cout << res;
}
