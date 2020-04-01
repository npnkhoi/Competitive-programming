#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define REP(i,n) for (int i = 0; i < n; ++i)

#define taskname "minsum"

const int LIM = 1e5;
int mark[LIM + 5];
vector<int> v;
bool biton(int mask, int i) {
    return (mask & (1 << i)) > 0;
}
int main() {
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        memset(mark, 0, sizeof mark);
        v.clear();
        long long a, b, minSum, save1, save2;
        scanf("%lld%lld", &a, &b);
        minSum = (long long) 1e10;
        // -----------------------------------
        for (long long i = 2; i*i <= a; i++)
        if (a % i == 0) {
            while (a % i == 0) {
                mark[i] ^= 1;
                a /= i;
            }
        }
        if (1 < a && a <= LIM) {
            mark[a] ^= 1;
            a = 1;
        }
        for (long long i = 2; i*i <= b; i++)
        if (b % i == 0) {
            while (b % i == 0) {
                mark[i] ^= 1;
                b /= i;
            }
        }
        if (1 < b && b <= LIM) {
            mark[b] ^= 1;
            b = 1;
        }
        if (a == b) a = b = 1;
        // ----------------------------------
        for (int i = 2; i <= LIM; i++) if (mark[i]) v.push_back(i);
        if (a != 1) v.pb(a);
        if (b != 1) v.pb(b);
        //REP(i, v.size()) cerr << v[i] << " "; cerr << "\n";

        int n = v.size();
        save1 = 1; save2 = 1;
        REP(mask, 1 << n) {
            long long num1 = 1, num2 = 1;
            REP(i, n) if (biton(mask, i))
                num1 = num1 * v[i];
            else num2 = num2 * v[i];
            if (num1 + num2 < minSum) {
                minSum = num1 + num2;
                save1 = num1;
                save2 = num2;
            }
        }
        if (save1 > save2) swap(save1, save2);
        printf("%lld %lld\n", save1, save2);
    }
}
