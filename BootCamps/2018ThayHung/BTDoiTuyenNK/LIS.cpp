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

#define task "lis"

const int N = 1e5 + 5;
int n, a[N], trace[N];
vector<int> v;
bool cmp(int i, int j) {
    return a[i] < a[j];
}
void getTrace(int i) {
    if (trace[i] != -1) getTrace(trace[i]);
    printf("%d ", i);
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        if (v.empty()) {
            v.pb(i);
            trace[i] = -1;
        } else if (a[i] > a[v.back()]) {
            trace[i] = v.back();
            v.pb(i);
        } else if (a[i] < a[*v.begin()]) {
            v[0] = i;
            trace[i] = -1;
        } else {
            int l = 0, r = v.size() - 1, d = l;
            while (l <= r) {
                int mi = (l+r)/2;
                if (a[v[mi]] < a[i]) {
                    d = max(d, mi);
                    l = mi + 1;
                } else r = mi - 1;
            }
            if (a[v[d]] < a[i]) {
                trace[i] = v[d];
                if (a[v[d+1]] > a[i]) v[d+1] = i;
            } else trace[i] = -1;
        }
        //REP(j, v.size()) cerr << v[j] << " "; cerr << "\n";
    }
    printf("%d\n", (int)v.size());
    getTrace(v.back());
}
/** Happy Coding :D */
