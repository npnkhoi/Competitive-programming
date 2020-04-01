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
    scanf("%d", &n);
    REP(i, n) scanf("%d", &p[i]);
    scanf("%d", &k);
    REP(i, n) nxt[i] = 1;
    int ptr = 0;
    FOR(i, 1, k) {
        while (1) {
            if (binary_search(a+1, a+k, nxt[ptr])) {
                ptr ++;
                if (ptr == n) ptr = 0;
            }
        }

    }
}
