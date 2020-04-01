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

//ifstream inp(".inp");
//ofstream out(".out");

int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int x, y;
    scanf("%d%d", &x, &y);
    int d = y - x;
    if (d == 0) printf("0\n");
    else if (d > 0) {
        int i = int(ceil(log2(d)));
        if (i%2) i ++;
        //cerr << i << "\n";
        printf("%d\n", 2*((1<<i) - 1) + d);
    } else {
        d = -d;
        int i = int(ceil(log2(d)));
        if (i%2 == 0) ++i;
        printf("%d\n", 2*((1<<i)-1) + d);
    }
    return 0;
}
/** Happy Coding :D */
