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

int n, x[105], a, b;
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n/2) scanf("%d", &x[i]);
    sort(x + 1, x + n/2 + 1);
    FOR(i, 1, n/2) {
        a += abs(x[i] - (2*i-1));
        b += abs(x[i] - 2*i);
    }
    printf("%d", min(a, b));
}

