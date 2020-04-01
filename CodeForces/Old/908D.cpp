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

double res = 0, k, p, q;
int cntA, cntAB;
void backTrack(int i, double xs) {
    if (i >= 1000) return;
    cntA ++;
    backTrack(i+1, xs * p / (p+q));
    cntA --;

    cntAB += cntA;
    if (cntAB >= k) res += (double) cntAB * xs * q / (p+q);
    else backTrack(i+1, xs * q / (p+q));
    cntAB -= cntA;
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> k >> p >> q;
    backTrack(1, 1);
    printf("%.20f", res);
}
/// Expelliarmus !
