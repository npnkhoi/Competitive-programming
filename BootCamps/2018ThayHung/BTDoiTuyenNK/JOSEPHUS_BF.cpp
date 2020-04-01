#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task "josephus"
const int N = 1e5 + 5;
bool mark[N];
int n, m, pos;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d%d", &n, &m);
    if (m%n) m %= n; else m = n;
    int pos = 0;
    FOR(i, 1, n) {
        REP(j, m) {
            do {
                //cerr << pos << "\n";
                pos ++;
                if (pos > n) pos = 1;
            } while (mark[pos]);
        }
        printf("%d ", pos);
        mark[pos] = 1;
    }
}
/** Happy Coding :D */
