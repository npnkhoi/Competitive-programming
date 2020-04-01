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
    double p = 2, q = 5;
    double s = 0;
    int n = 50;
    FOR(i, 0, n) FOR(j, 0, n) {
        s += pow(q / (p+q), i) * pow(p/(p+q), j+1) * j;
        cerr << s << "\n";
    }
}
/// Expelliarmus !
