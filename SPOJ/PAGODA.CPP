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

bool Less (string &a, string &b) { /// a be hon b
    int n = a.size();
    REP(i, n) if (a[i] != b[i]) return a[i] < b[i];
    return 0;
}
bool rLess (string &a, string &b) { /// a co nghich dao be hon b
    int n = a.size();
    FORD(i, n-1, 0) if (a[i] != b[i]) return a[i] < b[i];
    return 0;
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    int n;
    string a, b, c, d, x;
    int cnt[15];

    scanf("%d ", &n);
    getline(cin, a);
    getline(cin, b);

    getline(cin, x);
    REP(i, n) cnt[x[i]-'0'] ++;

    if (Less(a, b)) c = b; else c = a;
    if (rLess(a, b)) d = a; else d = b;

    sort(x.rbegin(), x.rend());
    if (!ok(x)) {
        printf("-1");
        return 0;
    }

    REP(i, n) FORD(j, n-1, )
    }

    return 0;
}
/** Happy Coding :D */

