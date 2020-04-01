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

//ifstream inp("PAIRING.inp");
//ofstream out("PAIRING.out");
int main() {
    freopen("PAIRING.inp", "r", stdin);
    freopen("PAIRING.out", "w", stdout);
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    a %= 2; c %= 2;

    int t = min(b, d);
    b -= t; d -= t;

    if (b > 0 && c > 0) --b;
    if (d > 0 && a > 0) --d;
    if (a > 0 && b > 0) --a;
    if (c > 0 && d > 0) --c;
    printf("%d", a+b+c+d);
    return 0;
}
/** Happy Coding :D */
