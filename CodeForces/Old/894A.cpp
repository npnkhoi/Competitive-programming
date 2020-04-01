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
string s;
const int N = 500;
int a[N];

int sum(int l, int r) {
    if (l == 0) return a[r];
    else return a[r] - a[l-1];
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    cin >> s;
    int n = s.size();
    REP(i, n) {
        a[i] = (s[i] == 'Q');
        if (i > 0) a[i] += a[i-1];
    }
    int res = 0;
    FOR(i, 1, n-2) if (s[i] == 'A') res += sum(0, i-1) * sum(i+1, n-1);
    cout << res;
    return 0;
}
/** Happy Coding :D */
